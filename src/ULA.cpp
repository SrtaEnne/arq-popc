#include "ULA.h"

ULA::ULA() {
    c = false;
}
        
void ULA::readA (float _a) {
    a = _a;
}

void ULA::readB (float _b) {
    b = _b;
}

float ULA::writeResult () {
    return(s);
}

void ULA::op (int ulaOP) {
    switch (ulaOP) {
        case 0:
        s = a + b;
        break;

        case 1:
        s = a - b;
        break;

        case 2:
        s = a / b;
        break;

        case 3:
        c = a > b;
        break;

        default:
        break;
    }
}

bool ULA::getCond () {
    return(c);
}