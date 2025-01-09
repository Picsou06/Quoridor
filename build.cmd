@echo off
set C_INCLUDE_PATH=include

rem Set color to green
color 0A

echo Compiling...
gcc src\*.c -o bin\main.exe -Llib -lncursesw
echo Running...

rem Reset color to default
color

bin\main.exe