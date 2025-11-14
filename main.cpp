#include <iostream>

// didn't handle all inputs and errors
// quick solve for chapter 5 exercise 7 



// the correct solution

void test () {
    int total = 0;
    std::string test = "123";
    for (char t : test) {
        total = total * 10 + (t - '0');
    }
    std::cout << total << " is now converted to int.\n\n**********\n\n";
}




void error(std::string s) {
    throw std::runtime_error {s};
}

class Money {
public:
    int thousand_count {};
    int hundred_count {};
    int ten_count {};
    int one_count {};

    void update_count(int sum) {
        if (sum >= 1000) {
            thousand_count = std::floor(sum/1000); 
        } else if (sum >= 100) {
            hundred_count = std::floor(sum/100); 
        } else if (sum >= 10) {
            ten_count = std::floor(sum/10); 
        } else if (sum >= 1) {
            one_count = std::floor(sum/1); 
        } 
    }
};

int main() {

    test();
    

    Money m;

    std::cout << "enter an integer:\n> "; // print prompt

    std::string input {};
    std::cin >> input;

    int sum {};
    int total {};
    
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input.size() - i; ++j) {
            if (j == 0) {
                sum += (input[i] - '0');
            } else {
                sum *= 10;
            }
        }

        // std::cout << "sum is " << sum << "\n";

        m.update_count(sum);
        total += sum;
        sum = 0;
    }

    if (total > 0)
        std::cout << total << " is ";

    bool started = false;

    if(m.thousand_count > 0) {
        started = true;
        std::cout << m.thousand_count << " thousands";
    }

    if(m.hundred_count > 0) {
        if (started) {
            std::cout << " and ";
        }
        started = true;
        std::cout << m.hundred_count << " hundreds";
    }

    if (m.ten_count > 0) {
        if (started) {
            std::cout << " and ";
        }
        started = true;
        std::cout << m.ten_count << " tens";
    }

    if (m.one_count > 0) {
        if (started) {
            std::cout << " and ";
        }
        std::cout << m.one_count << " ones";
    }

    if (total > 0)
        std::cout << ".\n";

}