#include <iostream>
#include <limits>

/*
    This program should have error checking.
    Make sure that all erroneous inputs will generate good error messages.
*/

void error(std::string s) {
    throw std::runtime_error {s};
}

void clear_buffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_factorial(int num) {
    // Base case: If num is 1 or 0, the factorial is 1
    if (num <= 1) {
        return 1;
    }
    // Recursive step: num * factorial of (num - 1)
    return num * get_factorial(num - 1);
}

//P(a, b) = (a!) / ((a - b)!)
int get_permutation(int a, int b) {
    int result{};
    result = (get_factorial(a)) / (get_factorial(a - b));
    return result;
}

//C(a, b) = (P(a, b)) / (b!)
int get_combination(int a, int b, int permutation) {
    int result{};
    result = (permutation) / (get_factorial(b));
    return result;
}

int main() {

    int a{};
    int b{};
    char choice{};
    
    while(true) {
        try{

            std::cout << "\nenter two numbers:\n> ";
            std::cin >> a >> b;
            if (!std::cin)
                error("bad cin operation");
            break;

        } catch(std::exception& e) {

            std::cerr << "\nerror: " << e.what() << "\n";
            std::cin.clear();
            clear_buffer();

        }
    }

    clear_buffer();

    while(true) {
        try{    

            std::cout << "\ntype 'p' to get permutation or 'c' for combination:\n> ";
            std::cin >> choice;
            if (!std::cin)
                error("bad cin operation");
        
            std::cout << "\n";
        
            if (choice == 'p') {
                std::cout << "permutation is " << get_permutation(a, b);
            } else if (choice == 'c') {
                std::cout << "combination is " << get_combination(a, b, get_permutation(a, b));
            } else {
                error("invalid choice");
            }
        
            std::cout << "\n\n";
            break;

        } catch(std::exception& e) {

            std::cerr << "error: " << e.what() << "\n";
            std::cin.clear();
            clear_buffer();

        }
    }
}