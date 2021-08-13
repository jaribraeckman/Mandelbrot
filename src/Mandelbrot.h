#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ComplexNumber {
    public:
        double real;
        double imag;
        double modulus;
        bool inMandelbrot;
        ComplexNumber(double r, double i);
        double calcModulus();
        void determineMandelbrot();
        void update(ComplexNumber c);
};

class MandelbrotSet {
    public:
        double real_min;
        double real_max;
        double imag_min;
        double imag_max;
        int nx;
        int ny;
        vector<vector<ComplexNumber>> grid;
        MandelbrotSet(double real_min, double real_max, double imag_min, double imag_max, int nx, int ny);
        void constructGrid();
        void showGrid();
};