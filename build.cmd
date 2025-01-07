@echo off
set C_INCLUDE_PATH=include

REM Compiling...
gcc src\*.c -o bin\main.exe -Llib -lncursesw
REM Running...
bin\main.exe