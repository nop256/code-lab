// src/controllers.cpp
#include "image_menu.h"

int assignment1( std::istream& is, std::ostream& os )
{
    return askQuestions3(is, os); //from user_io.cpp
}

int assignment2( std::istream& is, std::ostream& os )
{
    Image image;
    diagonalQuadPattern(is, os, image);
    drawAsciiImage(is, os, image);
    return 0;
}

int assignment3( std::istream& is, std::ostream& os )
{
    PPM ppm;
    stripedDiagonalPattern(is,os,ppm);
    writeUserImage(is,os,ppm);
    return 0;
}
