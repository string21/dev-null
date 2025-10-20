#include <iostream>

using namespace  std;

bool validateAge(int age);

int main () {

    cout << "\n\n********* some letter app *********\n\n";
    string first_name;
    cout << "Enter the name of the person you want to write to: ";
    getline(cin, first_name);

    string another_friend_name;
    cout << "Enter the name of another friend: ";
    getline(cin, another_friend_name);

    int age;

    do {
        cout << "Enter age of your recipient: ";
        cin >> age;
        bool isValidAge = validateAge(age);
        if (!isValidAge) {
            cout << "you're kidding...";
        } else {
            break;
        }
    } while(true);

    cout << "\nDear " << first_name << ",\n\n";

    cout << "\tHow are you? I miss you.\n" << "Lorem ipsum dotor sit amet blah blah blah.\n";

    cout << "Have you seen " << another_friend_name << " lately?\n";

    cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if (age < 12) {
        cout << "Next year you will be " << age+1 << ".\n";
    } else if (age == 17) {
        cout << "Next year you will be able to vote.\n";
    } else if (age > 70) {
        cout << "Are you retired?\n";
    }

    cout << "\nYours sincerely,\n";
    cout << "___________________\n";
    cout << "___________________\n";
    cout << "string21";

    cout << "\n\n********* some letter app *********\n\n";

    return 0;
}

bool validateAge(int age) {
    return age <=0 || age >= 110 ? false :  true; // too complex or not readable, use simpler if?
}