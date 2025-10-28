#include <iostream>
#include <vector>
using namespace std;

class Bad_range {};

int main() {
    cout << "testing vector range error\n";
    vector<int> nums = {
        1,2,3,4,5
    };

    try {
        for(int i=0; i<=nums.size(); ++i) {
            if (i == nums.size())
                throw Bad_range{};
            cout << nums[i] << "  ";
        }
    } catch (Bad_range) {
        cerr << "out of range --- testing errores";
    }

}