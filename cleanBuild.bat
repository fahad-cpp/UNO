@echo off
if exist build (
    powershell del .\build\*
)
timeout 3
mkdir build
cd build
cmake ..
cmake --build .
echo Program output:
Uno.exe