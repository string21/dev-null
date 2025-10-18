#include <iostream>

using namespace  std;

int main () {

    cout << "enter name and age: ";
    string name;
    double age;

    cin >> name >> age;

    cout << "hello, " << name << "! you are " << age*12 << " months old!";

    return 0;
}