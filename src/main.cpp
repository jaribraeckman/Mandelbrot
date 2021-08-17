#include <iostream>
#include "Mandelbrot.h"
#include <conio.h>
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int KEY_ARROW = 224;
const int KEY_ESC = 27;

int main() {
    cout << "Start with real axis [-2, 2] and imaginary axis [-2, 2]:" << endl;
    MandelbrotSet m = MandelbrotSet((double) -1.0, (double) 1.0, (double) -1.0, (double) 1.0, (int) 100, (int) 50);
    m.showGrid();
    bool stop = false;
    char ans;
    double real_min = -1.0;
    double real_max = 1.0;
    double imag_min = -1.0;
    double imag_max = 1.0;
    double nx = 100;
    double ny = 50;
    while (!stop) {
        cout << "Zoom in with arrow keys" << endl;
        int ch = _getch();
        if (ch == KEY_ARROW){
            int ch = _getch();
            if (ch == KEY_UP) {
                imag_min = (imag_max + imag_min) / 2.0;
            }
            if (ch == KEY_DOWN) {
                imag_max = (imag_max + imag_min) / 2.0;
            }
            if (ch == KEY_RIGHT) {
                real_min = (real_max + real_min) / 2.0;
            }
            if (ch == KEY_LEFT) {
                real_max = (real_max + real_min) / 2.0;
            }
            MandelbrotSet m = MandelbrotSet(real_min, real_max, imag_min, imag_max, nx, ny);
            m.showGrid();
        }
        else {
            if (ch == KEY_ESC){
                stop = true;
            }
            else {
                cout << "Invalid answer" << endl;
            }
        }
    }
    return 0;
}; 