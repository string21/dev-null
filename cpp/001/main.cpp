#include <iostream>

using namespace std;

int main() {

    double d = 0;

    while (cin >> d) {
        int i = d;
        char c = i;

        cout << "the original double is " << d << "\n";
        cout << "double converted to int is " << i << "\n";
        cout << "int value of char is " << c << "\n";

    }

    return 0;

}


// enabled warning in your IDE will help with type safety and other bugs  --- i think it is some kind of a -wall compiler option --- look into this