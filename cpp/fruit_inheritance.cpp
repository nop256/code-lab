#include <iostream>
#include <string>

// Base class
class Fruit
{
public:
    std::string name;
    std::string color;

    // initializer constructor
    Fruit(const std::string& name_in, const std::string& color_in) : name(name_in), color(color_in)   
    {
        std::cout << "Fruit constructor called\n";
    }

    void print()
    {
        std::cout << "This is a " << color << " " << name << ".\n";
    }
};

// Derived class
class Pear : public Fruit
{
public:
    int size;

    // Pear constructor calls Fruit constructor
    Pear(int s) : Fruit("pear", "green"), size(s)
    {
        std::cout << "Pear constructor called\n";
    }
};

int main()
{
    Pear p(5);
    p.print();
    std::cout << "Size: " << p.size << std::endl;

    return 0;
}

