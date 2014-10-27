#ifndef STREAMMANIPULATOR_H
#define STREAMMANIPULATOR_H

#include <iostream>

class StreamManipulator {
    public:
        StreamManipulator(int integer = 0);
        ~StreamManipulator() {}
        void setNumber(int num);
        void showInDecimal();
        void showInOctal();
        void showInHexadecimal();
        void printInPrecision(double target, int precision);
        void convertFahrenToCelsis(int FahrenTemp);
    private:
        int value_;
};

#endif
