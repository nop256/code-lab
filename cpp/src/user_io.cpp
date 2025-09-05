// src/user_io.cpp
#include <iostream>
#include "image_menu.h"

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt )
{
    os<<prompt;
    std::string response;
    is>>response;
    return response;
}
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt )
{
    os<<prompt;
    int value;
    is>>value;
    return value;
}
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt )
{
    os<<prompt;
    double decimal;
    is>>decimal;
    return decimal;
}
int askQuestions3(std::istream& is, std::ostream& os)
{
    std::string color = getString(is, os, "What is your favorite color? ");
    int x = getInteger(is, os, "What is your favorite integer? ");
    double d = getDouble(is, os, "What is your favorite number? ");
    for (int i=1;i<=x;i++)
    {
        os<<i<<' '<<color<<' '<<d<<'\n';
    }
    return x;
}
