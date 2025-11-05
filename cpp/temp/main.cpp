#include <iostream>

void error(std::string e) {
    throw std::runtime_error {e};
}

int main() {
    std::cout << "enter an expression, we can handle + - * /\n"
              << "end the expression with x (e.g., 1 + 2 * 3 x)    <--- separate by space\n";

    double lvalue = 0;
    double rvalue = 0;
    std::cin >> lvalue;
    if (!std::cin)
        error("no left value operand");

    for (char the_operator {}; std::cin >> the_operator;) {
        std::cout << "operator is " << the_operator << "\n";

        if (the_operator != 'x') {
            std::cout << "operator is not x, so i need a right value... " << "\n";
            std::cin >> rvalue;
        }
        std::cout << "value of rvalue is " << rvalue << " before a cin test!\h";
        if (!std::cin) {
            error("no right value operand");
        }

        switch (the_operator) {
            case '+':
                lvalue += rvalue;
                break;
            case '-':
                lvalue -= rvalue;
                break;
            case '*':
                lvalue *= rvalue;
                break;
            case '/':
                lvalue /= rvalue;
                break;
            default:
                std::cout << "result is " << lvalue;
                return 0;
        }//switch
    }//for
    error("bad expression"); // means we did not reach return 0
}//main