cmake_minimum_required(VERSION 3.30)
project(Aloo)

include_directories(include)

add_library(aloo "src/app.c" "src/box.c" "src/button.c" "src/grid.c" "src/label.c" "src/style.c" "src/widget.c" "src/builder.c")
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/)

include_directories(
	"/usr/include/gtk-4.0"
	"/usr/include/glib-2.0"
	"/usr/include/gdk-pixbuf-2.0"
	"/usr/lib/x86_64-linux-gnu/glib-2.0/include"
	"/usr/include/gtk-4.0/gdk"
	"/usr/include/gtk-4.0"
	"/usr/include/cairo"
	"/usr/lib/x86_64-linux-gnu/graphene-1.0/include"
	"/usr/include/pango-1.0"
	"/usr/include/graphene-1.0"
	"/usr/include/harfbuzz"
	)
target_link_libraries(aloo "/lib/x86_64-linux-gnu/libgtk-4.so.1" "/lib/x86_64-linux-gnu/libglib-2.0.so.0")
