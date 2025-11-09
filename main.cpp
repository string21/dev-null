#include <iostream>

double factorial(double num) {
    double result {num--};
    while (num >= 1) {
        result = result * num--;
    }
    return result; 
}

int main() {
    std::cout << "factorial is " << factorial(3) << "\n";
}   