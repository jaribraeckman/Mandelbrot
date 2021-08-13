#include "Mandelbrot.h"

ComplexNumber::ComplexNumber(double r, double i){
    this->real = r;
    this->imag = i;
    this->modulus = calcModulus();
}

double ComplexNumber::calcModulus(){
    return sqrt(pow(real, 2) + pow(imag, 2));
}

void ComplexNumber::determineMandelbrot(){
    if (modulus > 2.0){
        inMandelbrot = false;
    }
    else {
        ComplexNumber z = ComplexNumber(0.0, 0.0);
        int i = 0;
        while (i <= 1000 && z.calcModulus() <= 2.0){
            z.update(*this);
            i++;
        }
        if (z.calcModulus() > 2.0){
            inMandelbrot = false;
        }
        else {
            inMandelbrot = true;
        }
    }
}

void ComplexNumber::update(ComplexNumber c) {
    double real_temp = real * real - imag * imag + c.real;
    imag = 2 * real * imag + c.imag;
    real = real_temp;
}

MandelbrotSet::MandelbrotSet(double r_min, double r_max, double i_min, double i_max, int nmx, int nmy){  
    this->real_min = r_min;
    this->real_max = r_max;
    this->imag_min = i_min;
    this->imag_max = i_max;
    this->nx = nmx;
    this->ny = nmy;
    constructGrid();
}

void MandelbrotSet::constructGrid(){
    for (int i = 0; i < nx; i++){
        double re = real_min + ((double) i + 0.5) * (real_max - real_min) / (double) nx;
        grid.push_back(vector<ComplexNumber>());
        for (int j = 0; j < ny; j++){
            double im = imag_min + ((double) j + 0.5) * (imag_max - imag_min) / (double) ny;
            grid[i].push_back(ComplexNumber(re, im));
            // Check if part of Mandelbrot set
            grid[i][j].determineMandelbrot();
        }
    }
}

void MandelbrotSet::showGrid(){
    vector<vector<char>> ch;
    for (int i = 0; i < nx; i++){
        ch.push_back(vector<char>());
        for (int j = 0; j < ny; j++){
            if (grid[i][j].inMandelbrot){
                ch[i].push_back('x');
            }
            else {
                ch[i].push_back('-');
            }
        }
    }
    for (int j = ny - 1; j >= 0; j--){
        for (int i = 0; i < nx; i++){
            cout << ch[i][j];
        }
        cout << endl;
    }
}

