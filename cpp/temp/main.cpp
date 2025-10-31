#include <iostream>
#include <random>
#include <chrono>

int random_int(int min, int max);

int main() {
    random_int(1, 6);
}

int random_int(int min, int max) {

    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine theEngine(seed);
    std::uniform_int_distribution<int> someDist(min,max);

    std::cout << someDist(theEngine);

    return 0;
}
