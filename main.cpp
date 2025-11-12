#include <iostream>

/*
    Exercise 20 in Chapter 3:
        [1] Write a program where you first enter a set of name- and-value pairs, such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.
        [2] Modify the program from the previous exercise so that once you have entered the name-and-value pairs, you ask for values: In a loop, when you enter a name, the program will output the corresponding score or name not found.
        [3] Modify the program from the previous exercise so that once you have entered the name-and-value pairs, you ask for names: In a loop, when you enter a value, the program will output all the names with that score or score not found.
*/

/*
    Define a class Name_value that holds a string and a value.
    Rework exercise 20 in Chapter 3 to use a vector<Name_value>
    instead of two vectors.
*/

void error(std::string s) {
    throw std::runtime_error {s};
}

class Name_value {
    public:
        std::string name {};
        int value {};
        // not sure if doing in-class initializaiton here like this is ok...
};

int main() {
    std::cout << "Enter name and value pair:" << "\n";
    std::vector<Name_value> pair;

    while(true) {
        try {
            std::cout << "> "; // print prompt
            Name_value temp;
            std::cin >> temp.name >> temp.value;
            if (!std::cin)
                error("bad cin operation");
            
            if (temp.name == "NoName" && temp.value == 0)
                break;
            else
                pair.push_back(temp);
        } catch (std::exception& e) {
            std::cerr << "error: " << e.what() << "\n";
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
        } catch (...) {
            std::cerr << "error: unknown exception has been caught" << "\n"; // terminate program
        }
    }

    for (Name_value p : pair) {
        std::cout << "Name is " << p.name << " with value of " << p.value << "\n";
    }

    // quick solve -- not trying to catch errors here
    std::cout << "Enter a name and I shall give your their score lol" << "\n";
    std::cout << "> ";
    std::string name {};
    std::cin >> name;
    bool isFound = false;
    for (Name_value p : pair) {
        if (name == p.name) {
            isFound = true;
            std::cout << "Name is " << p.name << " with value of " << p.value << "\n";    
        }
    }
    if (!isFound)
        std::cout << "name not found...";


    
    
}