#include "character.h"

Character::Character()
{
    gender = "";
    name="";
    job="";
    race="";

    ac=0;
    health=100;
    alive=true;

    str=dex=con=intel=wis=cha=10;
}

void Character::print_stats()
{

}
