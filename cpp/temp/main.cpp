#include <iostream>
#include <random>

void error(std::string e);
void expect(bool correctExpectation, std::string e);
int random_int(int a, int b);
void print_welcome_msg();
std::vector<int> generateRandomSet();
std::vector<int> get_user_input();
int get_bull_count(std::vector<int> number_to_be_guessed, std::vector<int> user_input);
int get_cow_count(std::vector<int> number_to_be_guessed, std::vector<int> user_input);

int main() {
    print_welcome_msg();
    std::vector<int> number_to_be_guessed = generateRandomSet();
    int bull_count = 0;
    int cow_count = 0;
    do {
        try {
            std::vector<int> user_input = get_user_input();
            bull_count = get_bull_count(number_to_be_guessed, user_input);
            cow_count = get_cow_count(number_to_be_guessed, user_input);
            std::cout << "bulls: " << bull_count << "\n";
            std::cout << "cows: " << cow_count << "\n";
            if (bull_count == 4) {
                std::cout << "you found all the bulls!!\n";
                std::string decision {};
                while (true) {
                    try {
                        std::cout << "do you want to play again? (y or n):  " << std::endl;
                        std::cin >> decision;
                        expect(std::cin.good() && (decision == "y" || decision == "n"), "y or n only");
                        if (decision == "y") {
                            bull_count = 0;
                            number_to_be_guessed = generateRandomSet();
                            break;
                        } else {
                            std::cout << "bye bye...";
                            break;
                        }
                    } catch (std::runtime_error& e) {
                        std::cerr << "RUNTIME ERROR: " << e.what() << "\n";
                    }
                }
            }
        } catch (std::runtime_error& e) {
            std::cerr << "RUNTIME ERROR: " << e.what() << "\n";
        }
    } while (bull_count != 4);
}
int get_bull_count(std::vector<int> number_to_be_guessed, std::vector<int> user_input) {
    int bull_counter {};
    for (int i = 0; i < number_to_be_guessed.size(); ++i) {
        if (number_to_be_guessed[i] == user_input[i])
            ++bull_counter;
    }
    return bull_counter;
}
int get_cow_count(std::vector<int> number_to_be_guessed, std::vector<int> user_input) {
    int cow_counter {};
    for (int i = 0; i < number_to_be_guessed.size(); ++i) {
        for (int j = 0; j < user_input.size(); ++j) {
            if (i != j && number_to_be_guessed[i] == user_input[j]) {
                ++cow_counter;
            }
        }
    }
    return cow_counter;
}
std::vector<int> get_user_input() {
    std::cout << "Enter 4 numbers (e.g. 4352) to guess:  " << std::endl;
    std::string userInput {};
    std::cin >> userInput;
    expect(std::cin.good(), "failed cin operation");
    std::vector<int> validInputs;
    for (char input : userInput) {
        if (input - '0' >= 1 && input - '0' <= 9) {
            validInputs.push_back(input - '0');
        }
    }
    expect(validInputs.size() == 4, "invalid user input");
    return validInputs;
}
std::vector<int> generateRandomSet() {
    std::vector<int> rando_set;
    while (rando_set.size() < 4) {
        int temp = random_int(1, 9);
        bool isFound = false;
        for (int r : rando_set) {
            if (temp == r) isFound = true;
        }
        if (!isFound) {
            // std::cout << "adding: " << temp << "\n";
            rando_set.push_back(temp);
        }
    }
    return rando_set;
}
void print_welcome_msg() {
    std::cout << "*** Let's play Bulls and Cows! ***\n";
}
int random_int(int a, int b) {
    static unsigned seed = time(nullptr);
    static std::default_random_engine theEngine(seed);
    std::uniform_int_distribution<int> theDistribution(a, b);
    return theDistribution(theEngine);
}
void error(std::string e) {
    throw std::runtime_error {e};
}
void expect(bool correctExpectation, std::string e) {
    if (!correctExpectation) error(e);
}