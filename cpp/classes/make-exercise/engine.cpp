#include <iostream>
#include <cstdlib>
#include "engine.h"

static const char* ENGINE_OPTIONS[] = { "454 Big Block", "4-Cylinder", "Hybrid", "EV" };
static const int ENGINE_COUNT = 4;

Engine::Engine()
{
    type = ENGINE_OPTIONS[std::rand() % ENGINE_COUNT];
}

Engine::Engine(const std::string& t) : type(t) {}

void Engine::print() const
{
    std::cout << "Engine: " << type << "\n";
}
