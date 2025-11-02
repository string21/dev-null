#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <exception>
#include <stdexcept>

// key takeaway.... loop is like a good place to try and catch errors so it does not interrupt the user journey..
// just make sure to handle the exception you encounter there within the loop gracefully
// and dont terminate if it makes sense that the program must continue -- if that makes sense....
// oh... so it's actually called recoverable errors?!

void print_welcome_message();
short get_n_to_add();
std::vector<int> get_numbers();
void processResult(short n, std::vector<int> numbers);
void error(std::string e);
void expect(bool checkExpectation, std::string e);

int main() {
    try {
        print_welcome_message();
        std::cout << "enter the number of integers you want to add:  ";
        short n = get_n_to_add();
        std::vector<int> numbers = get_numbers();
        processResult(n, numbers);
    } catch (std::runtime_error& e) {
        std::cerr << "runtime: " << e.what();
    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what();
    } catch (...) {
        std::cerr << "Oppppps..... Unknown error";
    }
}

void processResult(short n, std::vector<int> numbers) {
    expect(numbers.size() >= n,"not enough numbers were entered");
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << "  ";
        // this only handles the if numbers[i] is a positive number ... underflow is not considered here..
        expect(numbers[i] <= std::numeric_limits<int>::max() - sum, "integer overflow");
        sum+=numbers[i];
    }
    std::cout << "\nsum is " << sum;
}

std::vector<int> get_numbers() {
    std::cout << "start entering the int numbers, enter '|' to stop...\n";
    std::vector<int> numbers;
    std::string temp = {};
    while (true) {
        std::cin >> temp;
        expect(std::cin.good(), "input operation failed...");
        if (temp == "|")
            break;
        try {
            numbers.push_back(std::stoi(temp));
        } catch (std::invalid_argument& e) {
            std::cerr << "INSIDE LOOP INVALID ARG ERROR: " << e.what() << "\n";
        }
    }
    return numbers;
}

short get_n_to_add() {
    short n = 0;
    std::cin >> n;
    expect(std::cin.good(), "input operation failed...");
    expect(n > 0, "variable 'n' must be greater than zero...");
    return n;
}

void print_welcome_message() {
    std::cout << "let's add some integers, shall we?\n";
}

void error(std::string e) {
    throw std::runtime_error(e);
}

void expect(bool checkExpectation, std::string e) {
    if (!checkExpectation) error(e);
}