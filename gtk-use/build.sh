#!/bin/bash
if [ ! -d "build/" ]; then
	mkdir build
fi

cmake -S . -B build
cd build
make
