@echo off

setlocal enabledelayedexpansion

set "gcc=gcc -fdiagnostics-color=always -g -I ."
set "main_dir=src"
set "main_output_filename=Main.exe"
set "tests_output_filename=Tests.exe"
set "tests_dir=tests"

set "main_output_dir=%main_dir%\bin"
set "main_output_path=%main_output_dir%\%main_output_filename%"
set "tests_output_dir=%tests_dir%\bin"
set "tests_output_path=%tests_output_dir%\%tests_output_filename%"

call :main %*
exit /b %errorlevel%

:build
mkdir "%main_output_dir%" >nul 2>nul
%gcc% "%main_dir%\Main.c" -o "%main_output_path%"
set resultcode=%errorlevel%
if %resultcode% equ 0 (
    echo Build successful
) else (
    echo Build failed
)
exit /b %resultcode%

:main
if "%~1" == "" (
    call :build
) else if "%~1" == "--build" (
    call :build
) else if "%~1" == "--run" (
    call :build
    if !errorlevel! equ 0 (
        echo Starting %main_output_path%...
        %main_output_path%
    )
) else if "%~1" == "--tests" (
    mkdir "%tests_output_dir%" >nul 2>nul
    %gcc% -o "%tests_output_path%" "%tests_dir%\Tests.c"
    if !errorlevel! equ 0 (
        echo Tests build successful
        %tests_output_path%
        if !errorlevel! equ 0 (
            echo Tests successful
        ) else (
            echo Tests failed
        )
    ) else (
        echo Tests build failed
    )
    exit /b
) else (
    echo Unknown option: %~1.
    call :help
    exit /b -1
)
exit /b %errorlevel%
