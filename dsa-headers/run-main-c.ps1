if (!(Test-Path -Path 'out')) {
  New-Item -ItemType Directory -Path 'out'
}

if (!(Test-Path -Path 'out\c')) {
  New-Item -ItemType Directory -Path 'out\c'
}
if (!(Test-Path -Path 'out\cpp')) {
  New-Item -ItemType Directory -Path 'out\cpp'
}
gcc -c -o out/c/run.o main.c
#gcc -c -o out/c/stack.o lib/src/stack.c
#gcc -c -o out/c/queue.o lib/src/queue.c
#gcc -c -o out/c/linkedlist.o lib/src/linkedlist.c
# gcc -c -o out/c/hashmap.o lib/src/hashmap.c
gcc -c -o out/c/hashset.o lib/src/hashset.c
gcc -c -o out/c/my_string.o lib/src/my_string.c
gcc -o out/c/run.exe out/c/run.o out/c/my_string.o # out/c/hashset.o out/c/stack.o out/c/linkedlist.o out/c/hashmap.o
./out/c/run.exe