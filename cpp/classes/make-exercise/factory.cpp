#include <iostream>
#include <ctime>
#include <cstdlib>
#include "car.h"

int main()
{
    // Seed randomness once for the process
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Your car:\n";
    Car random_car;
    random_car.print();


    return 0;
}
