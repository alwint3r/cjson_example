#include <iostream>
#include <cstdint>
#include <cJSON/cJSON.h>

struct Preference {
    uint32_t telemetryInterval;
    uint32_t reportInterval;
    uint8_t telemetryRetryCount;
    uint8_t reportRetryCount;
    uint8_t maxWiFiRetryCount;

    std::string toJSON() {
        cJSON *_root = cJSON_CreateObject();
        cJSON_AddNumberToObject(_root, "telemetryInterval", telemetryInterval);
        cJSON_AddNumberToObject(_root, "reportInterval", reportInterval);
        cJSON_AddNumberToObject(_root, "telemetryRetryCount", telemetryRetryCount);
        cJSON_AddNumberToObject(_root, "reportRetryCount", reportRetryCount);
        cJSON_AddNumberToObject(_root, "maxWiFiRetryCount", maxWiFiRetryCount);

        char* serialized = cJSON_PrintUnformatted(_root);
        std::string output = serialized;

        free(serialized); // otherwise there will be leaks.
        cJSON_Delete(_root); // this one also

        return output;
    }

    void fromJSON(const std::string& jsonString) {
        cJSON *_root = cJSON_Parse(jsonString.c_str());

        cJSON *_telemetryInterval = cJSON_GetObjectItem(_root, "telemetryInterval");
        if (cJSON_IsNumber(_telemetryInterval)) {
            telemetryInterval = static_cast<uint32_t>(cJSON_GetNumberValue(_telemetryInterval));
        }

        cJSON *_reportInterval = cJSON_GetObjectItem(_root, "reportInterval");
        if (cJSON_IsNumber(_telemetryInterval)) {
            telemetryInterval = static_cast<uint32_t>(cJSON_GetNumberValue(_reportInterval));
        }

        cJSON *_telemetryRetryCount = cJSON_GetObjectItem(_root, "telemetryRetryCount");
        if (cJSON_IsNumber(_telemetryRetryCount)) {
            telemetryRetryCount = static_cast<uint8_t>(cJSON_GetNumberValue(_telemetryRetryCount));
        }

        cJSON *_reportRetryCount = cJSON_GetObjectItem(_root, "reportRetryCount");
        if (cJSON_IsNumber(_reportRetryCount)) {
            reportRetryCount = static_cast<uint8_t>(cJSON_GetNumberValue(_reportRetryCount));
        }

        cJSON *_maxWiFiRetryCount = cJSON_GetObjectItem(_root, "maxWiFiRetryCount");
        if (cJSON_IsNumber(_maxWiFiRetryCount)) {
            maxWiFiRetryCount = static_cast<uint8_t>(cJSON_GetNumberValue(_maxWiFiRetryCount));
        }

        cJSON_Delete(_root);
    }
};


int main(int, char**) {
    Preference pref{};
    std::string json_string = pref.toJSON();

    std::cout << json_string << std::endl;

    pref.fromJSON("{}");

    return 0;
}
