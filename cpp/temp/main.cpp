#include <iostream>
using namespace std;

int main () {
    try {

        // find and correct the errors

        // number 1
        // Cout << "Success!\n";
        // cout << "Success!\n";

        // number 2
        // cout << "Success!\n;
        // cout << "Success!\n";

        // number 3
        // cout << "Success" << !\n"
        // cout << "Success" << "!\n";

        // number 4
        // cout << success << ’\n’;
        // cout << "success" << "\n";

        // number 5
        // string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
        // string res = "7";
        // vector<string> v(10);
        // v[5] = res;
        // cout << "Success!\n";

        // number 6
        // vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
        // vector<int> v(10);
        // v[5] = 9;
        // if (v[5]!=7)
        //     cout << "Success!\n";

        // number 7
        // if (cond) cout << "Success!\n"; else cout << "Fail!\n";
        // bool cond = 1 < 2;
        // if (cond) cout << "Success!\n"; else cout << "Fail!\n";

        // number 8
        // bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
        // bool c = false; if (!c) cout << "Success!\n"; else cout << "Fail!\n";

        // number 9
        // string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
        /*string s = "ape";
        bool c = "fool" > s;
        if (c) cout << "Success!\n";*/

        // number 10
        // string s = "ape"; if (s=="fool") cout << "Success!\n";
        // string s = "ape"; if (s!="fool") cout << "Success!\n";

        // number 11
        // string s = "ape"; if (s=="fool") cout < "Success!\n";
        // string s = "ape"; if (s!="fool") cout << "Success!\n";

        // number 12
        // string s = "ape"; if (s+"fool") cout < "Success!\n";
        // string s = "ape"; if (s != "fool") cout << "Success!\n";

        // number 13
        // vector<char> v(5); for (int i = 0; 0<v.size(); ++i) ; cout << "Success!\n";
        // vector<char> v(5);
        // for (int i = 0; i < v.size(); ++i)
        //     cout << "Success!\n";

        // number 14
        // vector<char> v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";
        // vector<char> v(5);
        // for (int i = 0; i < v.size(); ++i) // or 1 up to <= vector size
        //     cout << "Success!\n";

        // number 15
        // string s = "Success!\n"; for (int i = 0; i<6; ++i) cout << s[i];
        // string s = "Success!\n";
        // for (int i = 0; i<=7; ++i)
        //     cout << s[i];

        // number 16
        // if (true) then cout << "Success!\n"; else cout << "Fail!\n";
        // if (true)
        //     cout << "Success!\n";
        // else
        //     cout << "Fail!\n";

        // number 17
        // int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
        // int x = 2000;
        // char c = x;
        // if (c==(char)2000) cout << "Success!\n"; // narrowed int literal down to char

        // number 18
        // string s = "Success!\n"; for (int i = 0; i<10; ++i) cout << s[i];
        // string s = "Success!\n";
        // for (int i = 0; i<s.size()-1; ++i) cout << s[i]; // intentionally removed the newline here

        // number 19
        // vector v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";
        // vector<int> v(5);
        // for (int i = 0; i < v.size(); ++i)
        //     cout << "Success!\n";

        // number 20
        // int i = 0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
        // int i = 0; int j = 9;
        // while (i<j) {
        //     if (i<j) cout << "Success!\n";
        //     ++i;
        // }

        // number 21
        // int x = 2; double d = 5/(x−2); if (d==2*x+0.5) cout << "Success!\n";
        // int x = 2;
        // double d = 5/(x*2);
        // if (d==(x*2)/(x/0.5)) cout << "Success!\n";

        // number 22
        // string<char> s = "Success!\n"; for (int i = 0; i<=10; ++i) cout << s[i];
        // string s = "Success!\n";
        // for (int i = 0; i<s.size(); ++i)
        //     cout << s[i];

        // number 23
        // int i = 0; while (i<10) ++j; if (j<i) cout << "Success!\n";
        // int i = 0;
        // while (i<10) {
        //
        //     cout << "Success!\n";
        //     ++i;
        // }

        // number 24
        // int x = 4; double d = 5/(x−2); if (d=2*x+0.5) cout << "Success!\n";
        // int x = 4;
        // double d = 5/(x-2);
        // if (d!=2*x+0.5)
        //         cout << "Success!\n";
        // here assigment opeation is hiding in the selection / conditional

        // number 25
        // cin << "Success!\n";
        cout << "Success!\n"; // this is the last item in the list of errors i need ot fix.......

        // DONE.........

    } catch(exception& e) {
        cerr << "ERROR: " << e.what();
    } catch (...) {
        cerr << "ERROR: " << "unknown exception here!!";
    }
}