WL_CLIENT_DEPS := wayland-client wayland-egl gl egl

define Pkg
	$$(pkg-config --libs $1)
endef

OPTS = -g ./olive.c

wl-client:
	gcc $@.c $(OPTS) $(call Pkg, $(WL_CLIENT_DEPS))

x11-main:
	gcc $(OPTS) $@.c -lX11
