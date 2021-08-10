#pragma once
#include <iostream>
#include <vector>

using namespace std;

class ComplexNumber {
    public:
        double real;
        double imag;
        bool bounded;
        ComplexNumber(double r, double i);
        void inMandelbrot();
};