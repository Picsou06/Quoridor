@echo off
set C_INCLUDE_PATH=include

echo Compiling...
gcc src\*.c -o bin\main.exe -Llib -lncursesw
echo Running...

bin\main.exe