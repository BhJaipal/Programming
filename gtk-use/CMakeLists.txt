cmake_minimum_required(VERSION 3.30)
project(Aloo)

include_directories(include)

add_library(aloo
	"src/common/app.c"
	"src/common/box.c"
	"src/common/builder.c"
	"src/common/button.c"
	"src/common/grid.c"
	"src/common/input.c"
	"src/common/label.c"
	"src/common/style.c"
	"src/common/widget.c"
	"src/common/window.c"
	"src/utils/error.c"
	"src/utils/logger.c"
	"src/test/aloo.c"
	"src/db/sqlite.c"
)
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
	"/usr/include/tirpc"
)
target_link_libraries(aloo
	"/lib/x86_64-linux-gnu/libgtk-4.so.1"
	"/lib/x86_64-linux-gnu/libglib-2.0.so.0"
	"/lib/x86_64-linux-gnu/libsqlite3.so"
	"/lib/x86_64-linux-gnu/libsqlite3.so.0"
)
