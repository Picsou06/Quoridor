@echo off
set C_INCLUDE_PATH=include

echo Compiling...
gcc src\*.c -o bin\main.exe -Llib -lncursesw

if %errorlevel% neq 0 (
    echo Compilation failed. Press any key to exit...
    pause >nul
    exit /b
)

echo Running...

bin\main.exe