SRC := main.cpp cl.cpp
LIBS := gl OpenCL glfw3

a.out: $(SRC) fragment.glsl vertex.glsl ../renderer.hpp
	g++ -mavx $(SRC) -g $$(pkg-config --cflags --libs $(LIBS)) ../glad/gl.c

test: a.out
	@./$<
