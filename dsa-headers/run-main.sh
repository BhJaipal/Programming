#!/usr/bin/env bash
# run this file by first do this: chmod +x run-main.sh
# then do: ./run-main.sh
gcc -c -o out/c/run.o main.c
gcc -c -o out/c/stack.o lib/src/stack.c
gcc -c -o out/c/linkedlist.o lib/src/linkedlist.c
gcc -o out/c/run.exe out/c/run.o out/c/stack.o out/c/linkedlist.o
./out/c/run.exe
