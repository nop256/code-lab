#include <iostream>
#include <cstdlib>
#include "wheels.h"

static const char* WHEEL_OPTIONS[] = { "steel", "alloy", "chrome", "off-road" };
static const int WHEEL_COUNT = 4;

Wheels::Wheels()
{
    type = WHEEL_OPTIONS[std::rand() % WHEEL_COUNT];
}

Wheels::Wheels(const std::string& t) : type(t) {}

void Wheels::print() const
{
    std::cout << "Wheels: " << type << "\n";
}
