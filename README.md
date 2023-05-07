# An Example of Using cJSON Library

## Building

Run this if you didn't clone this repo with `--recursive` flag
```sh
git submodule update --init
```

Then build using CMake

```
cmake -B build -S .
cmake --build build -j8
```