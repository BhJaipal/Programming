#!/bin/python3
from make import make_class, Make, pkg_config
from sys import platform
from os import getenv, listdir, system

windows = ["win32", "msys", "cygwin"]

class Server(Make):
    flags = " -g ./olive.c "
    def platform(self, args: list[str]):
        display = ""
        if platform in windows:
            with open("./olive-platform.h", "w") as f:
                f.write("#define DISPLAY WINDOWS")
                display = "windows"
        else:
            with open("./olive-platform.h", "w") as f:
                if len(args) == 0:
                    f.write("#define DISPLAY " + ("WAYLAND" if getenv("XDG_SESSION_TYPE") == "wayland" else "X11"))
                    display = getenv("XDG_SESSION_TYPE")
                    if display is None:
                        display = "X11"
                elif args[0] == "x11":
                    f.write("#define DISPLAY X11")
                    display = "X11"
                else:
                    f.write("#define DISPLAY WAYLAND")
                    display = "wayland"
        return "echo \"\x1b[92m'olive-platform.h' successfully created for " + display + "\x1b[0m\""

    def wl(self, args: list[str]):
        system(self.platform(["wl"]))
        src = [args[0], "./wl-render.c", "./xdg-shell-protocol.c"]
        return "gcc " + self.flags + " ".join(src) + pkg_config("wayland-client")

    def x11(self, args: list[str]):
        system(self.platform(["x11"]))
        return "gcc " + self.flags + f" {args[0]} ./x11-render.c -lX11"
    def gl(self, args: list[str]):
        system(self.platform(["x11"]))
        return "gcc " + self.flags + " ./gl-render.c " + args[0] + pkg_config("gl", "glfw3")
    def win(self, args: list[str]):
        if "olive-platform.h" not in listdir():
            system(self.platform([]))
        return "gcc " + self.flags + f" {args[0]} ./win-render.c -lgdi"
    def cross(self, args: list[str]):
        if platform in windows:
            if "olive-platform.h" not in listdir():
                system(self.platform([]))
            return self.win(args[1:]) + " ./cross.c"
        else:
            if args[0] in ["x11", "wayland", "wl"]:
                return (self.x11 if args[0] == "x11" else self.wl)(args[1:]) + " ./cross.c"
            if getenv("XDG_SESSION_TYPE") == "wayland":
                return self.wl(args) + " ./cross.c"


make_class(Server())
