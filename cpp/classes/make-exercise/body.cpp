#include <iostream>
#include <cstdlib>
#include "body.h"

static const char* BODY_OPTIONS[] = { "sedan", "4x4", "SUV", "Roadster" };
static const int BODY_COUNT = 4;

Body::Body()
{
    type = BODY_OPTIONS[std::rand() % BODY_COUNT];
}

Body::Body(const std::string& t) : type(t) {}

void Body::print() const
{
    std::cout << "Body:   " << type << "\n";
}
