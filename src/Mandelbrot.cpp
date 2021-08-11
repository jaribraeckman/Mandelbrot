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


