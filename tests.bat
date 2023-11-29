mkdir tests\bin
gcc -fdiagnostics-color=always -g -o tests\bin\Tests.exe -I . tests\Tests.c && tests\bin\Tests.exe
