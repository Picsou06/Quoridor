@echo off
set C_INCLUDE_PATH=include

rem Set color to green
color 0A

echo Compiling...
gcc src\*.c -o bin\main.exe -Llib -lncursesw

if %errorlevel% neq 0 (
    echo Compilation failed. Press any key to exit...
    pause >nul
    exit /b
)

echo Running...

rem Reset color to default
color

bin\main.exe