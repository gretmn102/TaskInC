@echo off

setlocal enabledelayedexpansion

set "gcc=gcc -fdiagnostics-color=always -g -I ."
set "main_dir=src"
set "main_output_filename=Main.exe"
set "tests_output_filename=Tests.exe"
set "tests_dir=tests"
set "tester_dir=src\Tester"
set "tester_output_filename=Tester.exe"

set "main_output_dir=%main_dir%\bin"
set "main_output_path=%main_output_dir%\%main_output_filename%"
set "tests_output_dir=%tests_dir%\bin"
set "tests_output_path=%tests_output_dir%\%tests_output_filename%"
set "tester_output_dir=%tester_dir%\bin"
set "tester_output_path=%tester_output_dir%\%tester_output_filename%"

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

:tester_build
mkdir "%tester_output_dir%" >nul 2>nul
%gcc% "%tester_dir%\Main.c" -o "%tester_output_path%"
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
) else if "%~1" == "--tester-build" (
    call :tester_build
) else if "%~1" == "--tester-run" (
    call :tester_build
    if !errorlevel! equ 0 (
        echo Starting %tester_output_path%...
        %tester_output_path% %main_output_path%
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
