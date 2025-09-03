#ifndef CAR_H
#define CAR_H

#include "body.h"
#include "engine.h"
#include "wheels.h"

struct Car
{
    Body body;
    Engine engine;
    Wheels wheels;

    Car();                                          // random parts
    Car(const Body& b, const Engine& e, const Wheels& w);

    void print() const;
};

#endif
