#include <string>

class Character
{
    public:
    //protected:
    //default is private
    //

    std::string gender;
    std::string name;
    std::string job;
    std::string race;

    int health;
    bool alive;

    //stats
    int str, dex, con, intel, wis, cha;
    
    void print_stats();

};
