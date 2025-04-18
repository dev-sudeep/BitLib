#ifndef DRAW_H
#define DRAW_H

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// --- Platform-Agnostic Sleep ---
void sleep_ms(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

// --- Clear the terminal ---
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H"); // ANSI escape clear
#endif
}

// --- Move cursor to position ---
void move_cursor(int x, int y) {
#ifdef _WIN32
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y, x);
#endif
}

// --- Draw pixel (character at x,y) ---
void draw_pixel(int x, int y, const char* ch) {
    move_cursor(x, y);
    printf("%s", ch);
    fflush(stdout);
}

// --- Draw a filled box ---
void draw_box(int x, int y, int w, int h, const char* ch) {
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            draw_pixel(x + j, y + i, ch);
}

// --- Draw a basic circle (text-based) ---
void draw_circle(int cx, int cy, int r, const char* ch) {
    for (int y = -r; y <= r; y++) {
        for (int x = -r; x <= r; x++) {
            if (x*x + y*y <= r*r)
                draw_pixel(cx + x, cy + y, ch);
        }
    }
}

// --- Draw a line (Bresenham-style) ---
void draw_line(int x1, int y1, int x2, int y2, const char* ch) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;

    while (1) {
        draw_pixel(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

#endif // DRAW_H
// --- End of DRAW_H ---