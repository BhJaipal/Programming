#include <windows.h>
#include "olive.h"

WinData global;
HWND hwnd;
HINSTANCE g_hInstance;
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void set_global(WinData data) {
    global = data;
}

int Main();
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, wchar_t* lpCmdLine, int nCmdShow) {
    MSG Msg;
    WNDCLASSEX WndClsEx = { 0 };
    g_hInstance = hInstance;

    WndClsEx.cbSize = sizeof(WNDCLASSEX);
    WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
    WndClsEx.lpfnWndProc = WndProc;
    WndClsEx.hInstance = hInstance;
    WndClsEx.lpszClassName = "ClassName";
    WndClsEx.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);

    RegisterClassEx(&WndClsEx);
    Main();

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}

void create_window(char* title) {
    hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
        "ClassName",
        title,
        WS_OVERLAPPEDWINDOW,
        100,
        120,
        global.width + 10,
        global.height + 30,
        NULL,
        NULL,
        g_hInstance,
        NULL);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    switch (Msg) {
        case WM_DESTROY:
            PostQuitMessage(WM_QUIT);
            break;
        case WM_PAINT:
            {
                /* */
                PAINTSTRUCT ps;
                HDC hdc;
                RECT rc;
                hdc = BeginPaint(hwnd, &ps);

                GetClientRect(hwnd, &rc);

                for (int i = 0; i < global.width * global.height; i++) {
                    size_t data = global.pixels[i];
                    COLORREF color = RGB((data >> 16) & 0xff, (data >> 8) & 0xff, data & 0xff);
                    SetPixel(hdc, i % global.width, i / global.width, color); // SetPixel(HDC hdc, int x, int y, COLORREF color)
                }

                EndPaint(hwnd, &ps);
                break;
            }
            break;
        default:
            return DefWindowProc(hwnd, Msg, wParam, lParam);
    }
    return 0;
}

