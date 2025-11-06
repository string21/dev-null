#include <iostream>

// im trying to learn class real quick so i can understand this token concept being presented by bjarn

class Car {
public:
    std::string make;
    std::string model;

    Car(){}
    Car(std::string m): make{m}, model{"1 param test"}{}
    Car(std::string m, std::string m2): make{m}, model{m2} {
        if (make == "Honda")
            make = "Honda for real tho?";
    }


    void printCar() {
        std::cout << "Make: " << make << "\n";
        std::cout << "Model: " << model << "\n";
    }
};

int main () {

    Car someCar;
    someCar.make = "Honda";
    someCar.model = "Civic";
    std::cout << "My car is not a " << someCar.make << " " << someCar.model << std::endl;
    someCar.printCar();

    Car car1param("Ford");
    car1param.printCar();

    Car carWithTwoParams("Honda", "Accord");
    carWithTwoParams.printCar();

}