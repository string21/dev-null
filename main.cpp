#include <iostream>

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

    std::cout << "final output ==============\n";

    std::vector<double> results;
    int index {0};

    // loop * and /
    double lval {};
    double rval {};

    for (int i = 0; i < my_toks.size(); ++i) {
        if (my_toks[i].isMerged == false && (my_toks[i].kind == '*' || my_toks[i].kind == '/')) {
            
            // std::cout << "we are doing " << my_toks[i].kind << "\n";

            int left = i-1;
            int right = i+1;

            //check left
            if (my_toks[left].isMerged) {
                lval = results[my_toks[left].resultIndex];
            } else {
                lval = my_toks[left].value;
            }
            
            //check right
            if (my_toks[right].isMerged) {
                rval = results[my_toks[right].resultIndex];
            } else {
                rval = my_toks[right].value;
            }

            if (my_toks[left].resultIndex != -1) {
                for (Token& m : my_toks) {
                    if (m.resultIndex == my_toks[left].resultIndex) {
                        m.resultIndex = index;
                        m.isMerged = true;
                    }
                }
            }

            if (my_toks[right].resultIndex != -1) {
                for (Token& m : my_toks) {
                    if (m.resultIndex == my_toks[right].resultIndex) {
                        m.resultIndex = index;
                        m.isMerged = true;
                    }
                }
            }

            // update index
            my_toks[left].resultIndex = index;
            my_toks[i].resultIndex = index;
            my_toks[right].resultIndex = index;
            my_toks[left].isMerged = true;
            my_toks[i].isMerged = true;
            my_toks[right].isMerged = true;

            if (my_toks[i].kind == '*' ) {
                std::cout << lval*rval << "\n";
                results.push_back(lval*rval);
                lval = lval*rval;
            }

            if (my_toks[i].kind == '/' ) {
                std::cout << lval/rval << "\n";
                results.push_back(lval/rval);
                lval = lval/rval;
            }
            
            index += 1;
 
        }
    }

    
    for (double r : results) {
        std::cout << r << " ";
    } std::cout << "\n";
    

    for (int i = 0; i < my_toks.size(); ++i) {
        if (my_toks[i].isMerged == false && (my_toks[i].kind == '+' || my_toks[i].kind == '-')) {
            
            // std::cout << "we are doing " << my_toks[i].kind << "\n";

            int left = i-1;
            int right = i+1;

            //check left
            if (my_toks[left].isMerged) {
                lval = results[my_toks[left].resultIndex];
            } else {
                lval = my_toks[left].value;
            }
            
            //check right
            if (my_toks[right].isMerged) {
                rval = results[my_toks[right].resultIndex];
            } else {
                rval = my_toks[right].value;
            }

            if (my_toks[left].resultIndex != -1) {
                for (Token& m : my_toks) {
                    if (m.resultIndex == my_toks[left].resultIndex) {
                        m.resultIndex = index;
                        m.isMerged = true;
                    }
                }
            }

            if (my_toks[right].resultIndex != -1) {
                for (Token& m : my_toks) {
                    if (m.resultIndex == my_toks[right].resultIndex) {
                        m.resultIndex = index;
                        m.isMerged = true;
                    }
                }
            }

            // update index
            my_toks[left].resultIndex = index;
            my_toks[i].resultIndex = index;
            my_toks[right].resultIndex = index;
            my_toks[left].isMerged = true;
            my_toks[i].isMerged = true;
            my_toks[right].isMerged = true;

            if (my_toks[i].kind == '+' ) {
                std::cout << lval+rval << "\n";
                results.push_back(lval+rval);
                lval = lval+rval;
            }

            if (my_toks[i].kind == '-' ) {
                std::cout << lval-rval << "\n";
                results.push_back(lval-rval);
                lval = lval-rval;
            }

            index += 1;
 
        }
    }


    std::cout << "test here end >> " << results[results.size()-1] << "\n\n";

    for (double r : results) {
        std::cout << r << " ";
    } std::cout << "\n";

    std::cout << std::endl;
    std::cout << std::endl;
}


