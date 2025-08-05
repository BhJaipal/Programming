CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

MAIN ?= main.cpp

build:
	g++ $(CFLAGS) -o VulkanTest $(MAIN) $(LDFLAGS)

.PHONY: test clean

test: build
	./VulkanTest

clean:
	rm -f VulkanTest
