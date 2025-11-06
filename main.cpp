#include <iostream>

class Token {
public:
    char kind;
    double value;

    Token(){};
    Token(char k, double y):kind{k},value{y}{};

    void print_token() {
        std::cout << "kind is " << kind << " value is " << value << std::endl;
    }
};

void print(std::string s) {
    std::cout << "\n" << s << "\n";
}


Token get_token() {
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
            t.value = 0;
            break;
        case '1':
            t.kind = '8';
            t.value = 1;
            break;
        case '2':
            t.kind = '8';
            t.value = 2;
            break;
        case '3':
            t.kind = '8';
            t.value = 3;
            break;
        case '4':
            t.kind = '8';
            t.value = 4;
            break;
        case '5':
            t.kind = '8';
            t.value = 5;
            break;
        case '6':
            t.kind = '8';
            t.value = 6;
            break;
        case '7':
            t.kind = '8';
            t.value = 7;
            break;
        case '8':
            t.kind = '8';
            t.value = 8;
            break;
        case '9':
            t.kind = '8';
            t.value = 9;
            break;
        default:
            t.kind = 'x';
    }
    return t;
}

int main() {
    std::cout << std::endl;
    std::cout << std::endl;

    std::string build_number {};
    std::vector<Token> my_toks;

    while (std::cin) {
        
        Token temp = get_token();

        if (temp.kind != '8' && build_number.length() > 0) {
            Token x('8', std::stod(build_number));
            my_toks.push_back(x);
            build_number = "";
        }

        if (temp.kind == '8') {
            build_number += std::to_string(int(temp.value));
        } else if (temp.kind == 'x') {
            break;
        } else {
            my_toks.push_back(temp);
        }
    }

    // std::cout << "my tokens ==============\n";
    // for (Token t : my_toks) {∏
    //     t.print_token();
    // }

    std::cout << "final output ==============\n";
    double result {};
    bool isFirstOperation = true;
    for (int i=0; i < my_toks.size(); ++i) {
        if (isFirstOperation) {
            if (my_toks[i].kind == '+') {
                isFirstOperation = false;
                result = my_toks[i-1].value + my_toks[i+1].value;
            }
        } else {
            if (my_toks[i].kind == '+') {
                result = result + my_toks[i+1].value;
            }
        }
    }
    std::cout << "result is " << result << std::endl;
    std::cout << "\n";
}


