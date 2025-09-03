WL_CLIENT_DEPS := wayland-client

define Pkg
	$$(pkg-config --libs $1)
endef

define RenderEx
	$(filter-out $1,$(MAKECMDGOALS) $1-render.c)
endef

OPTS = -g ./olive.c

gl:
	gcc $(call RenderEx, $@) $(OPTS) $(call Pkg, gl glfw3)
gtk:
	gcc $(call RenderEx, $@) $(OPTS) $(call Pkg, --cflags gtk4)

wl:
	gcc $(call RenderEx, $@) ./xdg-shell-protocol.c $(OPTS) $(call Pkg, $(WL_CLIENT_DEPS))

x11:
	gcc $(OPTS) $(call RenderEx, $@) $(SRC) -lX11
