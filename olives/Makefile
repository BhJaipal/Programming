WL_CLIENT_DEPS := wayland-client

define Pkg
	$$(pkg-config --libs $1)
endef

OPTS = -g ./olive.c

.PHONY: wl-client
wl-client:
	gcc $@.c $S ./xdg-shell-protocol.c $(OPTS) $(call Pkg, $(WL_CLIENT_DEPS))

x11-main:
	gcc $(OPTS) ./x11-render.c $@.c -lX11
