#ifndef WHEELS_H
#define WHEELS_H

#include <string>

struct Wheels
{
    std::string type;
    Wheels();                        // random from 4 options
    explicit Wheels(const std::string& t);
    void print() const;
};

#endif
