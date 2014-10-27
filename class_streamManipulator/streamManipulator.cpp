#include <iostream>
#include "streamManipulator.h"
#include <iomanip>
using std::cout;
using std::endl;
using std::showbase;
using std::setprecision;

StreamManipulator::StreamManipulator(int integer) {
    value_ = integer;
}
void StreamManipulator::showInDecimal() {
    cout << "As a decimal number " << value_ << endl;
}
void StreamManipulator::showInOctal() {
    cout << std::showbase << std::oct
         << "As an octal number " << value_ << endl;
    cout << std::dec;    // transform to default decimal
}
void StreamManipulator::showInHexadecimal() {
    cout << std::showbase << std::hex
         << "As a hexadecimal number " << value_ << endl;
    cout << std::dec;    // transform to default decimal
}
void StreamManipulator::setNumber(int num) {
    value_ = num;
}
void StreamManipulator::printInPrecision(double target, int p) {
    cout << std::dec << "Rounded to " << p << " digit(s) is ";
    cout << std::fixed << std::setprecision(p) << target << endl;
}
void StreamManipulator::convertFahrenToCelsis(int fTemp) {
    cout << "After converting:\n" << fTemp << "===>";
    cout << std::setprecision(3) << (fTemp - 32) / 1.8 << endl;
}
