#include <iostream>

class Token {
public:
    char kind;
    double value;
    Token(){};
    Token(char k):kind{k},value{0.0}{};
    Token(char k, double y):kind{k},value{y}{};

    void print_token() {
        std::cout << "kind is " << kind << " value is " << value << std::endl;
    }
};

void print(std::string s) {
    std::cout << "\n" << s << "\n";
}


Token get_token() {

    std::string buildNum {};

    while (true) {
        Token t;
        char input;
        std::cin >> input;
        switch (input) {
            case '+':
                t.kind = '+';
                break;
            case '-':
                t.kind = '-';
                break;
            case '*':
                t.kind = '*';
                break;
            case '/':
                t.kind = '/';
                break;
            case '0':
                t.kind = '8';
                break;
            case '1':
                t.kind = '8';
                break;
            case '2':
                t.kind = '8';
                break;
            default:
                t.kind = 'x';
        }

        if (t.kind == '8') {
            std::cout << "type is " << t.kind << std::endl;
            buildNum += input;
            std::cout << "built num is " << buildNum << std::endl;
        } else {
            std::cout << "type is " << t.kind << std::endl;
            return t;
        }



    }

}

int main() {


    while (std::cin) {
        Token test = get_token();
        test.print_token();
    }




}
