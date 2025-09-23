@echo off
if not exist build (
    echo No build directory found
    echo target not built
    exit
)
cd build
cmake --build .
echo Program output:
Uno.exe