#!/usr/bin/env bash
# run this file by first do this: chmod +x run-main.sh
# then do: ./run-main.sh
gcc -c -o run.o main.c
gcc -c -o stack.o stack.c
gcc -o run.exe run.o stack.o
./run.exe
