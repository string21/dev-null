
#include <iostream>

void error(std::string s) {
    throw std::runtime_error {s};
}

class Token {
    public:
        Token(){};
        Token(char k) : kind{k}, value{0.0}{};
        Token(char k, double v) : kind{k}, value{v}{};
        char kind;
        double value;
};


class Token_stream {
    public:
        Token get();
        void putback(Token t);

    private:
        bool full = false;
        Token buffer;
};

void Token_stream::putback(Token t) {
    if (full) {
        error("buffer is full");
    } else {
        std::cout << "buffer is not full, putting back process starting here...\n";
        buffer = t;
        full = true;

        std::cout << "you have sucessfully stored in the buffer:\n";
        std::cout << "buffer kind: " << buffer.kind << "\n";
        std::cout << "buffer value: " << buffer.value << "\n";
    }
};

Token Token_stream::get() {

    

    if (full) {
        full = false;
        return buffer;
    }

    Token t;
    char ch{};
    std::cin >> ch;

    switch(ch) {
        case '+': case '-': case '*': case '/':
        case '(': case ')': case '!':
        {
            t.kind = ch;
            break;
        }

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
        {
            std::cin.putback(ch);
            double temp{}; 
            std::cin >> temp;
            t.kind = '8';
            t.value = temp;
            break;
        }

        default:
        {
            t.kind = 'x';
        }
    }

    std::cout << "you are getting back a token with the following attributes:\n";
    std::cout << "---- kind is " << t.kind << "\n";
    std::cout << "---- value is " << t.value << "\n";
    
    
}

int main() {
    
    Token_stream ts;

    Token a = ts.get();
    ts.putback(a);

    Token b = ts.get();
    Token c = ts.get();
    
    
    
    
    


    
    
}