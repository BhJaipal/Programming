#!/usr/bin/env bash
# run this file by first do this: chmod +x run-main.sh
# then do: ./run-main.sh
# if you don't have out folder, out/c, out/cpp folders, uncomment the below 3 lines or
# add these 3 folders in this pattern:
# out
#  |- c (folder)
#  |- cpp (folder)
mkdir out
mkdir out/c
mkdir out/cpp

gcc -c -o out/c/run.o main.c
#gcc -c -o out/c/stack.o lib/src/stack.c
#gcc -c -o out/c/queue.o lib/src/queue.c
#gcc -c -o out/c/linkedlist.o lib/src/linkedlist.c
gcc -c -o out/c/hashmap.o lib/src/hashmap.c
gcc -c -o out/c/hashset.o lib/src/hashset.c
gcc -o out/c/run.exe out/c/run.o out/c/hashmap.o out/c/hashset.o # out/c/stack.o out/c/linkedlist.o
./out/c/run.exe
