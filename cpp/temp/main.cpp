#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <exception>
#include <stdexcept>

// modded to find adjacent diffs
// i did find and replace to change most ints to double..
// i must have converted some that need to stay int like iterators and stuff

void print_welcome_message();
int get_n_to_add();
std::vector<double> get_numbers();
void processResult(int n, std::vector<double> numbers);
void error(std::string e);
void expect(bool checkExpectation, std::string e);

int main() {
    try {
        print_welcome_message();
        std::cout << "enter the number of double number values you want to add:  ";
        int n = get_n_to_add();
        std::vector<double> numbers = get_numbers();
        processResult(n, numbers);
    } catch (std::runtime_error& e) {
        std::cerr << "runtime: " << e.what();
    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what();
    } catch (...) {
        std::cerr << "Oppppps..... Unknown error";
    }
}

// bigger function just to complete the exercise....
void processResult(int n, std::vector<double> numbers) {
    expect(numbers.size() >= n,"not enough numbers were entered");
    double sum = 0.0;
    std::vector<double> diffs;
    for (int i = 0; i < n; ++i) {
        sum+=numbers[i];
        if (i < n-1)
            diffs.push_back(numbers[i+1] - numbers[i]);
    }

    std::cout << "\nthe target numbers:  ";
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << "  ";
    }

    std::cout << "\nsum is " << sum;

    std::cout << "\ndiffs are:  ";
    for (double d : diffs) {
        std::cout << d << "  ";
    }



}

std::vector<double> get_numbers() {
    std::cout << "start entering the double numbers, enter '|' to stop...\n";
    std::vector<double> numbers;
    std::string temp = {};
    while (true) {
        std::cin >> temp;
        expect(std::cin.good(), "input operation failed...");
        if (temp == "|")
            break;
        try {
            numbers.push_back(std::stod(temp));
        } catch (std::invalid_argument& e) {
            std::cerr << "INSIDE LOOP INVALID ARG ERROR: " << e.what() << "\n";
        }
    }
    return numbers;
}

int get_n_to_add() {
    int n = 0;
    std::cin >> n;
    expect(std::cin.good(), "input operation failed...");
    expect(n > 0, "variable 'n' must be greater than zero...");
    return n;
}

void print_welcome_message() {
    std::cout << "let's add some doubles, shall we?\n";
}

void error(std::string e) {
    throw std::runtime_error(e);
}

void expect(bool checkExpectation, std::string e) {
    if (!checkExpectation) error(e);
}