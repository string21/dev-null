#include <iostream>
#include <cmath>
#include <vector>
#include <exception>

// ill start using std:: instead of relying on "using namespace std" to avoid polluting the global namespace

// quad formulas:
    // x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    // x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
// quad equation: (a * x * x) + (b * x) + c

void welcomeMsg();
std::vector<double> getUserInputs();
void printResult(std::vector<double> inputs);
void expect(bool pre_or_postcondition, std::string e);
void error(std::string e);

int main () {
    try {
        welcomeMsg();
        std::vector<double> inputs = getUserInputs();
        printResult(inputs);
    } catch (std::exception& e) { // catch all types of exceptions, not just runtime_error
        std::cerr << "ERROR: " << e.what();
    } catch (...) {
        std::cerr << "Oppps... Unknown Error Found";
    }
}

void welcomeMsg() {
    std::cout << "\nlet's solve some quadratic equations!\n"
              << "please supply us with variables a, b and c to start.\n"
              << "type them now and make sure to separate them using space:  ";
}

std::vector<double> getUserInputs() {
    double a, b, c = {};
    std::cin >> a >> b >> c;
    expect(std::cin.good(), "Invalid User Input");
    return {a, b, c};
}

// this is a bigger function just to finish this...
void printResult(std::vector<double> inputs) {
    double a = inputs[0];
    double b = inputs[1];
    double c = inputs[2];

    expect((b*b - 4*a*c) > 0, "MATH: No Real Roots");
    double x1 = (-b + std::sqrt(b*b - 4*a*c)) / (2*a);
    double x2 = (-b - std::sqrt(b*b - 4*a*c)) / (2*a);

    double verify_x1 = (a * x1 * x1) + (b * x1) + c;
    double verify_x2 = (a * x2 * x2) + (b * x2) + c;

    std::cout << "x1 is " << x1 << ", plugged into the quadratic equation: " << verify_x1 << "\n"
              << "x2 is " << x2 << ", plugged into the quadratic equation: " << verify_x2 << "\n";
}

void expect(bool pre_or_postcondition, std::string e) {
    if (!pre_or_postcondition) error(e);
}

void error(std::string e) {
    throw std::runtime_error {e};
}