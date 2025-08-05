DEPS = $$(pkg-config --libs glfw3 opengl glew)
CC = g++
MAIN ?= ./basic.cpp

all:
	$(CC) $(MAIN) $(DEPS) -fPIE
