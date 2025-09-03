#include <iostream>
#include "car.h"

Car::Car() : body(), engine(), wheels() {}

Car::Car(const Body& b, const Engine& e, const Wheels& w)
    : body(b), engine(e), wheels(w)
{}

void Car::print() const
{
    std::cout << "Car configuration:\n";
    body.print();
    engine.print();
    wheels.print();
}
