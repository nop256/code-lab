#ifndef BODY_H
#define BODY_H

#include <string>

struct Body
{
    std::string type;
    Body();                          // random from 4 options
    explicit Body(const std::string& t);
    void print() const;
};

#endif
