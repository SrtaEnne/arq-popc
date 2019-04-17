#include <iostream>
#include <math.h>
#include <string>

float squareRoot (float number) {
    float guess = 1;

    while (fabs(number / guess - guess) > 0.000001)
        guess = (guess + number / guess) / 2.0;

    return guess;
}

int main (int argc, char *argv[]) {
    int number = std::stoi(argv[1]);
    std::cout << squareRoot(number) << std::endl;
}