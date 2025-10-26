#include <iostream>
using namespace std;

void rewardChecker(int grainCountToCheck, vector<unsigned long long> grainPerSquare);

int main () {
    vector<unsigned long long> grainPerSquare = {};
    unsigned long long grainCount = 1;
    constexpr short chessSquares = 64;

    for (int i = 1; i <= chessSquares; ++i) {
        grainPerSquare.push_back(grainCount);
        grainCount*=2;
    }

    rewardChecker(1000, grainPerSquare);
    rewardChecker(1000000, grainPerSquare);
    rewardChecker(1000000000, grainPerSquare);
}

void rewardChecker(int grainCountToCheck, vector<unsigned long long> grainPerSquare) {
    int accumulator = {};
    for (int i = 0; i < grainPerSquare.size(); ++i) {
        accumulator += grainPerSquare[i];
        if (accumulator >= grainCountToCheck) {
            cout << "it takes about " << i+1 << " squares to give the chess inventor " << grainCountToCheck << " grains of rice.\n";
            cout << i+1 << " squares amounts to a total of " << accumulator << " grains of rice\n\n";
            break;
        }
    }
}