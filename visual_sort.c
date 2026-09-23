#include <asm-generic/ioctls.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sort_algo.h"
#include <sys/ioctl.h>

int hsl_to_term(double h, double s, double l);

void print_arr_vertical_selected_no_num(int arr[], int n, int r, int l);
void print_arr_selected_no_num(int arr[], int n, int r, int l);
void print_arr_vertical_no_num(int arr[], int n);
void print_arr_no_num(int arr[], int n);

void print_arr_vertical_selected(int arr[], int n, int r, int l);
void print_arr_selected(int arr[], int n, int r, int l);
void print_arr_vertical(int arr[], int n);
void print_arr(int arr[], int n);

int main(int argc, char *argv[])
{
    int n = 200;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 360;
    }
    RAND_MAX;
    print_arr(arr, n);
    quick_sort(arr, 0, n, n, print_arr_vertical_no_num, NULL);
    return EXIT_SUCCESS;
}
int hsl_to_rgb(double h, double s, double l)
{
    double c = (1 - fabs(2 * l - 1)) * s;
    double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    double m = l - c / 2;

    double r1, g1, b1;
    if (h < 60) {
        r1 = c;
        g1 = x;
        b1 = 0;
    } else if (h < 120) {
        r1 = x;
        g1 = c;
        b1 = 0;
    } else if (h < 180) {
        r1 = 0;
        g1 = c;
        b1 = x;
    } else if (h < 240) {
        r1 = 0;
        g1 = x;
        b1 = c;
    } else if (h < 300) {
        r1 = x;
        g1 = 0;
        b1 = c;
    } else {
        r1 = c;
        g1 = 0;
        b1 = x;
    }

    unsigned char r = (unsigned char)round((r1 + m) * 255);
    unsigned char g = (unsigned char)round((g1 + m) * 255);
    unsigned char b = (unsigned char)round((b1 + m) * 255);

    return (r << 16) | (g << 8) | b;
}

// Fixed version: proper xterm 256-color cube mapping
int rgb_to_term(int rgb)
{
    int r = (rgb >> 16) & 0xff;
    int g = (rgb >> 8) & 0xff;
    int b = rgb & 0xff;

    // scale 0-255 down to 0-5
    int r6 = r * 5 / 255;
    int g6 = g * 5 / 255;
    int b6 = b * 5 / 255;

    return 16 + 36 * r6 + 6 * g6 + b6;
}

int hsl_to_term(double h, double s, double l)
{
    int rgb = hsl_to_rgb(h, s, l);
    return rgb_to_term(rgb);
}

void print_arr_vertical_selected_help(int arr[], int n, int r, int l, int nums)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    printf("\e[0m\e[H\e[2J\e[3J");
    int subdiv = floor((double)max / w.ws_row) + 1;
    while (max > 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] >= max) {
                if (i == r || i == l) {
                    printf("\e[41m");
                } else
                    printf("\e[47m");
            } else
                printf("\e[0m");
            if (nums)
                printf("    ");
            else
                printf(" ");
        }
        printf("\e[0m\n");
        max -= subdiv;
    }
    for (int i = 0; i < n; i++) {
        if (i == r || i == l) {
            printf("\e[41;30m");
        } else {
            printf("\e[47;30m");
        }
        if (nums)
            printf("%3d ", arr[i]);
        else
            printf(" ");
    }
    printf("\e[0m\n");
    usleep(10000);
}
void print_arr_selected_help(int *arr, int n, int r, int l, int nums)
{
    printf("\e[H\e[2J\e[3J");
    for (int i = 0; i < n; i++) {
        double f = arr[i];
        f /= 360;
        f *= 160;
        if (i == r || i == n) {
            printf("\e[41m\e[30m");
        } else
            printf("\e[47m\e[30m");
        if (nums)
            printf(" %3d ", arr[i]);
        for (int i = 0; i < ceil(f); i++) {
            printf(" ");
        }
        printf("\e[0m\n");
    }
    usleep(10000);
}
void print_arr_vertical_help(int *arr, int n, int nums)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    printf("\e[0m\e[H\e[2J\e[3J");
    int subdiv = floor((double)max / w.ws_row) + 1;
    while (max > 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] >= max)
                printf("\e[48;5;%dm\e[30m", hsl_to_term(arr[i], 0.75, 0.50));
            else
                printf("\e[0m");
            if (nums)
                printf("    ");
            else
                printf(" ");
        }
        printf("\e[0m\n");
        max -= subdiv;
    }
    for (int i = 0; i < n; i++) {
        printf("\e[48;5;%dm\e[30m", hsl_to_term(arr[i], 0.75, 0.50));
        if (nums)
            printf("%3d ", arr[i]);
        else
            printf(" ");
    }
    printf("\e[0m\n");
    usleep(10000);
}
void print_arr_help(int *arr, int n, char nums)
{
    printf("\e[H\e[2J\e[3J");
    for (int i = 0; i < n; i++) {
        double f = arr[i];
        f /= 360;
        f *= 160;
        printf("\e[48;5;%dm\e[30m", hsl_to_term(arr[i], 0.75, 0.50));
        if (nums)
            printf(" %3d ", arr[i]);

        for (int i = 0; i < ceil(f); i++) {
            printf(" ");
        }
        printf("\e[0m\n");
    }
    usleep(10000);
}

inline void print_arr_vertical_selected_no_num(int *arr, int n, int r, int l)
{
    print_arr_vertical_selected_help(arr, n, r, l, 0);
}
inline void print_arr_vertical_selected(int *arr, int n, int r, int l)
{
    print_arr_vertical_selected_help(arr, n, r, l, 1);
}
inline void print_arr_selected_no_num(int *arr, int n, int r, int l)
{
    print_arr_selected_help(arr, n, r, l, 0);
}
inline void print_arr_selected(int *arr, int n, int r, int l)
{
    print_arr_selected_help(arr, n, r, l, 1);
}

inline void print_arr_vertical_no_num(int *arr, int n)
{
    print_arr_vertical_help(arr, n, 0);
}
inline void print_arr_vertical(int *arr, int n)
{
    print_arr_vertical_help(arr, n, 1);
}
inline void print_arr_no_num(int *arr, int n)
{
    print_arr_help(arr, n, 0);
}
inline void print_arr(int *arr, int n)
{
    print_arr_help(arr, n, 1);
}
