WL_CLIENT := wayland-client
OPTS = -g ./olive.c

define Pkg
	$$(pkg-config --libs $1)
endef

define RenderEx
	$(filter-out $1,$(MAKECMDGOALS) $1-render.c)
endef

cross:
	if [[ $(DISPLAY) == x11 ]]; then \
		make x11 $(filter-out cross,$(MAKECMDGOALS)) ./$@.c;\
	fi
none:
	touch ./olive-platform.h
	gcc $(filter-out $@,$(MAKECMDGOALS)) $(OPTS)
gl:
	echo "#define USE_GL" > ./olive-platform.h
	gcc $(call RenderEx, $@) $(OPTS) $(call Pkg, gl glfw3)
gtk:
	echo "#define USE_GTK" > ./olive-platform.h
	gcc $(call RenderEx, $@) $(OPTS) $(call Pkg, --cflags gtk4)
gtkmm:
	echo "#define USE_GTK" > ./olive-platform.h
	g++ $(call RenderEx, $@)pp $(OPTS) $(call Pkg, --cflags gtkmm-3.0)
wl:
	echo "#define WAYLAND" > ./olive-platform.h
	gcc $(call RenderEx, $@) ./xdg-shell-protocol.c $(OPTS) -l$(WL_CLIENT)

x11:
	echo "#define X11" > ./olive-platform.h
	gcc $(OPTS) $(call RenderEx, $@) -lX11
win:
	echo "#define WINDOWS" > ./olive-platform.h
	gcc $(OPTS) $(call RenderEx, $@) -lgdi
