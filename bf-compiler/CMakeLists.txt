cmake_minimum_required(VERSION 3.28)
project("BrainFuck compiler in C" LANGUAGES C)
add_executable(bf.exe src/main.c)
set(COMPILER "gcc")