DEPS = $$(pkg-config --libs glfw3 gl)
CC = g++
MAIN ?= ./basic.cpp

a.out: $(MAIN)
	g++ $< $(DEPS) -fPIE ../glad/gl.c

test: a.out
	@./$<
