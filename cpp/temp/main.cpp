#include <iostream>
#include <exception>
#include <string>
#include <vector>

int getUserInput();
std::vector<int> get_n_fibonacci(int userInput);
void expect(bool acceptable, std::string e);
void error(std::string e);
int get_largest_int_fibo();


int main() {

    std::cout << "\nhow many numbers in the fibonacci series do you want to display:  ";
    int userInput = getUserInput();
    std::vector<int> fibo = get_n_fibonacci(userInput);
    std::cout << "\n";
    for (int f : fibo) {
        std:: cout << f << " ";
    }
    std::cout << "\n\n";

    get_largest_int_fibo();
    std::cout << "\n";
}

int get_largest_int_fibo() {
    int a = 1;
    int b = 0;
    int temp = 0;
    while (true) {
        if (a + b < 0) {
            std::cout << temp << " is the largest number in the fibonacci series that can fit into an int var ...";
            break;
        }
        temp = a + b;
        a = b;
        b = temp;
    }
    return temp;
}


std::vector<int> get_n_fibonacci(int userInput) {
    int a = 1;
    int b = 0;
    int temp = 0;
    std::vector<int> fibo_series;
    for (int i = 0; i < userInput; ++i) {
        fibo_series.push_back(a+b);
        temp = a + b;
        a = b;
        b = temp;
    }
    return fibo_series;
}

int getUserInput() {
    int userInput = 0;
    std::cin >> userInput;
    expect(std::cin.good() && userInput > 0, "positive integer only!!!!");
    return userInput;
}

void expect(bool acceptable, std::string e) {
    if (!acceptable) error(e);
}

void error(std::string e) {
    throw std::runtime_error {e};
}

