#include <iostream>
#include <random>

/*
    Redo the “Bulls and Cows” game from exercise 12 in Chapter 4
    to use four letters rather than four digits.

    It did not say to use class but I will try.
*/

void error(std::string s) {
    throw std::runtime_error {s};
}

int rando(int min, int max) {
    static unsigned the_seed = time(nullptr);
    static std::default_random_engine the_engine(the_seed);
    std::uniform_int_distribution<int> the_distrib(min, max);
    return the_distrib(the_engine);
}

class Bullycow {
    public:
        std::vector<char> generate_given();
        int set_bull_count(std::vector<char> given, std::string guess);
        int get_bull_count();
        int set_cow_count(std::vector<char> given, std::string guess);
        int get_cow_count();
    private:
        int bull_counter {};
        int cow_counter {};
        bool validateGuess(std::vector<char> given, std::string guess);
};

std::vector<char> Bullycow::generate_given() {
    std::vector<char> given;
    given.push_back(rando('a', 'z'));
    given.push_back(rando('a', 'z'));
    given.push_back(rando('a', 'z'));
    given.push_back(rando('a', 'z'));
    return given;
}

bool Bullycow::validateGuess(std::vector<char> given, std::string guess) {
    if (given.size() == guess.size())
        return false;
    error("given and guess must be equal in len");
    return true; // satisfy compiler
}

int Bullycow::set_bull_count(std::vector<char> given, std::string guess) {
        validateGuess(given, guess);
        bull_counter = 0; // reset to zero!
        for (int i=0; i<given.size(); ++i) {
            if (given[i] == guess[i]) {
                ++bull_counter;
            }
        }
    return bull_counter;
}

int Bullycow::set_cow_count(std::vector<char> given, std::string guess) {
        validateGuess(given, guess);
        cow_counter = 0; // reset to zero!
        for (int i=0; i<given.size(); ++i) {
            for (int j=0; j<guess.size(); ++j) {
                if (i != j && given[i] == guess[j]) {
                    ++cow_counter;
                } 
            }
        }
    return cow_counter;
}

int Bullycow::get_bull_count() {
    return bull_counter;
}

int Bullycow::get_cow_count() {
    return cow_counter;
}

int main() {
    Bullycow bc;
    std::vector<char> given = bc.generate_given();
    std::string guess {};
    std::cout << "enter your guess\n";

    while(true) {      
        try {
            std::cout << "> "; //print prompt
            std::cin >> guess; 
            if(!std::cin)
                error("bad 'cin << guess' operation");
            if(guess == "exit")
                break;

            bc.set_bull_count(given, guess);
            bc.set_cow_count(given, guess);

            if (bc.get_bull_count() == given.size()) {
                std::cout << "you won! you found all " << bc.get_bull_count() << " bulls!\n";
                break;
            } else {
                std::cout << bc.get_bull_count() << " bull/s found\n";
                std::cout << bc.get_cow_count() << " cow/s found\n";
            }
        } catch (std::exception& e) {
            std::cerr << "error: " << e.what() << "\n";
        }
    }
}