#ifndef ENGINE_H
#define ENGINE_H

#include <string>

struct Engine
{
    std::string type;
    Engine();                        // random from 4 options
    explicit Engine(const std::string& t);
    void print() const;
};

#endif
