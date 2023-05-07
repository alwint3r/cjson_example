cmake_minimum_required(VERSION 3.0.0)
project(json_cjson VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(lib/cJSON)

add_executable(json_cjson main.cpp)
target_link_libraries(json_cjson cjson)
target_include_directories(json_cjson PRIVATE lib)