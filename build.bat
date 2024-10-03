@echo off
REM Compile the C files for the shell application


SET SRC_FILES=main.c src/commands.c
SET OUTPUT=shell
SET INCLUDE_DIR=./lib


echo Compiling...
gcc %SRC_FILES% -o %OUTPUT% -I%INCLUDE_DIR%


IF ERRORLEVEL 1 (
    echo Compilation failed! Please check your code.
    exit /b 1
)

echo Compilation successful! Executable created: %OUTPUT%
pause
