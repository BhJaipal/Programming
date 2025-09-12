WL_CLIENT := wayland-client
OPTS = -g ./olive.c

define Pkg
	$$(pkg-config --libs $1)
endef

define RenderEx
	$(filter-out $1,$(MAKECMDGOALS) $1-render.c)
endef

$%:
	echo $@

cross:
	if [[ $(DISPLAY) == x11 ]]; then \
		make x11 $(filter-out cross,$(MAKECMDGOALS)) ./$@.c;\
	fi
none:
	gcc $(filter-out $@,$(MAKECMDGOALS)) $(OPTS)
gl:
	gcc $(call RenderEx, $@) $(OPTS) $(call Pkg, gl glfw3)
gtk:
	gcc $(call RenderEx, $@) $(OPTS) $(call Pkg, --cflags gtk4)
gtkmm:
	g++ $(call RenderEx, $@)pp $(OPTS) $(call Pkg, --cflags gtkmm-3.0)
wl:
	gcc $(call RenderEx, $@) ./xdg-shell-protocol.c $(OPTS) -l$(WL_CLIENT)

x11:
	gcc $(OPTS) $(call RenderEx, $@) -lX11
win:
	gcc $(OPTS) $(call RenderEx, $@) -lgdi
