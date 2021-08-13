#include <iostream>
#include "Mandelbrot.h"

int main() {
    cout << "Start with real axis [-2, 2] and imaginary axis [-2, 2]:" << endl;
    MandelbrotSet m = MandelbrotSet((double) -2.0, (double) 2.0, (double) -2.0, (double) 2.0, (int) 200, (int) 50);
    m.showGrid();
    bool stop = false;
    char ans;
    double zoom;
    double real_min;
    double real_max;
    double imag_min;
    double imag_max;
    double nx;
    double ny;
    while (!stop) {
        cout << "Continue? (y/n): " << endl;
        cin >> ans;
        if (ans == 'y'){
            cout << "Lower limit for real axis: " << endl;
            cin >> real_min;
            cout << "Upper limit for real axis: " << endl;
            cin >> real_max;
            cout << "Lower limit for imaginary axis: " << endl;
            cin >> imag_min;
            cout << "Upper limit for imaginary axis: " << endl;
            cin >> imag_max;
            nx = m.nx;
            ny = m.ny;
            MandelbrotSet m = MandelbrotSet(real_min, real_max, imag_min, imag_max, nx, ny);
            cout << m.real_min << endl;
            m.showGrid();
        }
        else {
            if (ans == 'n'){
                stop = true;
            }
            else {
                cout << "Invalid answer" << endl;
            }
        }

    }
    return 0;
}; 