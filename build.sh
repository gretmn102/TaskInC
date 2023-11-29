#!/bin/bash

gcc="gcc -fdiagnostics-color=always -g -I ."
main_dir="src"
main_output_filename="Main.exe"
tests_output_filename="Tests.exe"
tests_dir="tests"

main_output_dir="$main_dir/bin"
main_output_path=$main_output_dir/$main_output_filename
tests_output_dir="$tests_dir/bin"
tests_output_path=$tests_output_dir/$tests_output_filename

build() {
    mkdir $main_output_dir >/dev/null 2>/dev/null
    $gcc $main_dir/Main.c -o $main_output_path
    return_code=$?
    if [ $return_code -eq 0 ]; then
        echo "Build successful"
    else
        echo "Build failed"
    fi
    return $return_code
}

help() {
    echo "Usage: $0, $0 --build, $0 --run or $0 --tests"
}

if [ $# -gt 1 ]; then
    help
    exit 1
elif [ $# -ne 1 ] || [ "$1" = "--build" ]; then
    build
elif [ "$1" = "--run" ]; then
    build
    if [ $? -eq 0 ]; then
        echo "Starting $main_output_path..."
        $main_output_path
    fi
elif [ "$1" = "--tests" ]; then
    $gcc -o $tests_output_path $tests_dir/Tests.c
    if [ $? -eq 0 ]; then
        echo "Tests build successful"
        $tests_output_path
        if [ $? -eq 0 ]; then
            echo "Tests successful"
        else
            echo "Tests failed"
        fi
    else
        echo "Tests build failed"
    fi
else
    echo "Unknown option: $1."
    help
    exit 1
fi
