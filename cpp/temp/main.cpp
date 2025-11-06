#include <iostream>

// im trying to learn class real quick so i can understand this token concept being presented by bjarn

class Car {
public:
    std::string make;
    std::string model;
};

int main () {

    Car someCar;
    someCar.make = "Honda";
    someCar.model = "Civic";

    std::cout << "My car is not a " << someCar.make << " " << someCar.model << std::endl;

}