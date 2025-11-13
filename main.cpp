#include <iostream>

/*
    Redo the “Bulls and Cows” game from exercise 12 in Chapter 4
    to use four letters rather than four digits.

    It did not say to use class but I will try.
*/

void error(std::string s) {
    throw std::runtime_error {s};
}

class Bullycow {
    public:
        int count_bulls(std::vector<char> given, std::string guess);
        int count_cows(std::vector<char> given, std::string guess);
        int get_bull_count();
    private:
        int bull_counter {};
        int cow_counter {};
};

int Bullycow::count_bulls(std::vector<char> given, std::string guess) {
        bull_counter = 0; // reset to zero!
        for (int i=0; i<given.size(); ++i) {
            if (given[i] == guess[i]) {
                ++bull_counter;
            }
        }
    return bull_counter;
}

int Bullycow::get_bull_count() {
    return bull_counter;
}

int main() {

    Bullycow bc;
    std::vector<char> given = {'b', 'c', 'g', 'u'};
    std::string guess {};
    
    std::cout << "enter your guess\n";

    while(true) {        
        std::cout << "> "; //print prompt
        std::cin >> guess;
        if(!std::cin)
            error("bad 'cin << guess' operation");
        if(guess == "exit")
            break;

        bc.count_bulls(given, guess);
        std::cout << bc.get_bull_count() << " bulls have been found lol\n";
        
    }

    


}