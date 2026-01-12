@echo off
if not exist build (
    echo No build directory found
    echo target not built
    exit
)
cd build
if not exist CMakeCache.txt cmake ..
cmake --build .
echo Program output:
Uno.exe