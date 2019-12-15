#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <chrono>


int main() {

    std::default_random_engine
          generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0,100);
    std::vector<int> data(100, 0);

    for(size_t i=0; i<100; i++) {
        data[i]=i;
    }







    return 0;
}

