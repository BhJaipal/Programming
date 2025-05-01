from time import sleep
from typing import Tuple
from math import sin, cos

singleRow = Tuple[float, float, float]
Matrix = Tuple[singleRow, singleRow, singleRow]


def multiply(m1: singleRow, m2: Matrix) -> singleRow:
    a = (m1[0] * m2[0][0]) + (m1[1] * m2[1][0]) + (m1[2] * m2[2][0])
    b = (m1[0] * m2[0][1]) + (m1[1] * m2[1][1]) + (m1[2] * m2[2][1])
    c = (m1[0] * m2[0][2]) + (m1[1] * m2[1][2]) + (m1[2] * m2[2][2])
    return (a, b, c)


colors = {
    ".": "\x1b[38;5;056m",
    ",": "\x1b[38;5;057m",
    "-": "\x1b[38;5;061m",
    "~": "\x1b[38;5;062m",
    ":": "\x1b[38;5;063m",
    ";": "\x1b[38;5;067m",
    "=": "\x1b[38;5;068m",
    "!": "\x1b[38;5;069m",
    "*": "\x1b[38;5;074m",
    "#": "\x1b[38;5;075m",
    "$": "\x1b[38;5;080m",
    "@": "\x1b[38;5;081m",
}


if __name__ == "__main__":
    A: float = 0
    B: float = 0
    R2 = 2
    R1 = 1
    screen_height = 22
    screen_width = 80
    zBuffer = [0.0] * (screen_width * screen_height)
    buffer = [" "] * (screen_width * screen_height)

    print("\x1b[2J", end="")
    while True:
        zBuffer = [0] * (screen_width * screen_height)
        # 32 = space ' '
        buffer = [" "] * (screen_width * screen_height)

        for theta in range(0, 628, 9):
            for phi in range(0, 628, 3):
                circleX = R2 + R1 * cos(theta / 100)
                circleY = R1 * sin(theta / 100)
                circle = (circleX, circleY, 0)

                Ry: Matrix = (
                    (cos(phi / 100), 0, sin(phi / 100)),
                    (0, 1, 0),
                    (-sin(phi / 100), 0, cos(phi / 100)),
                )
                donut1 = multiply(circle, Ry)

                Rx: Matrix = ((1, 0, 0), (0, cos(A), sin(A)), (0, -sin(A), cos(A)))
                donut2 = multiply(donut1, Rx)

                Rz: Matrix = ((cos(B), sin(B), 0), (-sin(B), cos(B), 0), (0, 0, 1))
                # final result of spinning donut
                donut = multiply(donut2, Rz)

                # R1 / (Nz + 5)
                # 5 is distance or so IDK correctly
                reciNz = R1 / (donut[2] + 5)

                # x position
                x = int(40 + 30 * donut[0] * reciNz)
                # y position
                y = int(12 + 15 * donut[1] * reciNz)
                # current buffer index where current char has to be set
                o = int(x + (screen_width * y)) % 1760

                # L = 8 * (
                # 		(circleY * cosA * cosB - sinϕ * cosB * cosθ * sinA)
                # 		- (circleY * sinA)
                # 		- (sinϕ * cosθ * cosA)
                # 		- (cosϕ * cosθ * sinB)
                #  )

                #  L = Ny - Nz
                #  	- 2 sinB cosϕ cosθ
                #  	- 2 sinB cosϕ
                #  	+ 2 cosB sinA sinϕ
                #  	+ 2 cosA sinϕ
                L_float = (
                    donut[1]
                    - donut[2]
                    + 2 * cos(B) * sin(A) * sin(phi)
                    - 2 * cos(phi) * cos(theta) * sin(B)
                    - 2 * cos(phi) * sin(B)
                    + 2 * cos(A) * sin(phi)
                )

                L = int(8 * L_float)

                charOpts = ".,-~:;=!*#$@"
                try:
                    if zBuffer[o] < reciNz and y < screen_height and x < screen_width:
                        # printf("%d ", L);
                        buffer[o] = charOpts[max(0, L % len(charOpts))]
                        zBuffer[o] = reciNz
                except IndexError:
                    print(o)

        print("\x1b[H", end="")
        # printf("%d ", buffer[i]);
        for i in range(0, len(buffer) + 1):
            if i % 80 == 0:
                print()
            elif buffer[i] == " ":
                print(
                    buffer[i] + "\x1b[0m",
                    end="",
                )
            else:
                print(
                    colors[buffer[i]] + buffer[i] + "\x1b[0m",
                    end="",
                )
            A += 0.00004
            B += 0.00002
        sleep(0.002)
