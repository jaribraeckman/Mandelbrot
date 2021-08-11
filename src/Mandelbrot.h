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
        vector<vector<ComplexNumber>> Grid;
        MandelbrotSet();
};