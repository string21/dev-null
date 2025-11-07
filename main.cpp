#include <iostream>
#include <iomanip>

class Token {
public:
    char kind;
    double value;
    int resultIndex = -1;
    bool isMerged = false;

    Token(){};
    Token(char k, double v) : kind{k}, value{v}{};

    void print_token() {
        std::cout << "kind is " << kind << " value is " << value << std::endl;
    }
};

void print(std::string s) {
    std::cout << "\n" << s << "\n";
}

// noob reminder that this is a normal function with return type of Token
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

    for (Token t : my_toks) {
        if (t.kind != '8') {
            std::cout << t.kind;
        } else {
            std::cout << t.value;
        }
    }


    // get the number of * and / in my_toks
    int multi_div_count {0};

    for (Token t : my_toks) {
        if (t.kind == '*' || t.kind == '/') {
            ++multi_div_count;
        }
    }

    std::cout << "\nthere are " << multi_div_count << "* and / in the given equation...\n";


    std::cout << "\n\nfinal output ==============\n\n";

    for (int i = 1; i <= multi_div_count; ++i) {
        double res {};
        std::vector<Token> new_toks;

        bool completed_one_pass = false;
        for (int i = 0; i < my_toks.size(); ++i) {
            if (!completed_one_pass && (my_toks[i].kind == '*' || my_toks[i].kind == '/')) {
                completed_one_pass = true;
                int left = i-1;
                int right = i+1;

                if (my_toks[i].kind == '*') {
                    res = my_toks[left].value * my_toks[right].value;
                } else if (my_toks[i].kind == '/') {
                    res = my_toks[left].value / my_toks[right].value;
                }

                new_toks.pop_back();
                Token temp('8', res);
                new_toks.push_back(temp);
                i+=2;
            }
            new_toks.push_back(my_toks[i]);
        }    
        my_toks = new_toks;
    }

     // get the number of * and / in my_toks
    int add_sub_count {0};

    for (Token t : my_toks) {
        if (t.kind == '+' || t.kind == '-') {
            ++add_sub_count;
        }
    }

    std::cout << "\nthere are " <<  add_sub_count << "+ and - in the given equation...\n";


    for (int i = 1; i <= add_sub_count; ++i) {
        double res {};
        std::vector<Token> new_toks;

        bool completed_one_pass = false;
        for (int i = 0; i < my_toks.size(); ++i) {
            if (!completed_one_pass && (my_toks[i].kind == '+' || my_toks[i].kind == '-')) {
                completed_one_pass = true;
                int left = i-1;
                int right = i+1;

                if (my_toks[i].kind == '+') {
                    res = my_toks[left].value + my_toks[right].value;
                } else if (my_toks[i].kind == '-') {
                    res = my_toks[left].value - my_toks[right].value;
                }

                new_toks.pop_back();
                Token temp('8', res);
                new_toks.push_back(temp);
                i+=2;
            }
            new_toks.push_back(my_toks[i]);
        }    
        my_toks = new_toks;
    }

    //pop 1 last extra
    my_toks.pop_back();

    std::cout << "size of the final my_toks is " << my_toks.size() << "\n";
    std::cout << "final value " << my_toks[my_toks.size()-1].value << "\n";


    std::cout << std::fixed << std::setprecision(2);
    for (Token t : my_toks) {
        std::cout << t.value << ", ";
    }

}