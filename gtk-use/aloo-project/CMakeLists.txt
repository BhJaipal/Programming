cmake_minimum_required(VERSION 3.30)

project(aloo-project)

add_executable(run.exe app/main.c)
set(CMAKE_BINARY_DIR build/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

target_link_libraries(run.exe /home/jaipal001/Desktop/files/c-use/Programming/gtk-use/lib/libaloo.a)

include_directories(
	"/home/jaipal001/Desktop/files/c-use/Programming/gtk-use/include"
	"/usr/include/gtk-4.0"
	"/usr/include/glib-2.0"
	"/usr/include/glib-2.0/gobject"
	"/usr/include/gdk-pixbuf-2.0"
	"/usr/lib/x86_64-linux-gnu/glib-2.0/include"
	"/usr/include/gtk-4.0/gdk"
	"/usr/include/cairo"
	"/usr/lib/x86_64-linux-gnu/graphene-1.0/include"
	"/usr/include/pango-1.0"
	"/usr/include/graphene-1.0"
	"/usr/include/harfbuzz"
	)
target_link_libraries(run.exe
	"/lib/x86_64-linux-gnu/libgtk-4.so"
	"/lib/x86_64-linux-gnu/libgtk-4.so.1"
	"/lib/x86_64-linux-gnu/libglib-2.0.so.0"
	"/lib/x86_64-linux-gnu/libglib-2.0.so"
	"/lib/x86_64-linux-gnu/libgobject-2.0.so.0"
	"/lib/x86_64-linux-gnu/libgobject-2.0.so"
	"/lib/x86_64-linux-gnu/libgobject-2.0.so"
	"/lib/x86_64-linux-gnu/libgio-2.0.so"
	"/lib/x86_64-linux-gnu/libgio-2.0.so.0"
)