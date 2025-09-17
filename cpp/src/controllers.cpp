// src/controllers.cpp
#include "image_menu.h"

int assignment1( std::istream& is, std::ostream& os )
{
    return askQuestions3(is, os); //from user_io.cpp
}

int assignment2( std::istream& is, std::ostream& os )
{
    Image image;
    diagonalQuadPattern(is, os, image); //from image_drawing.cpp
    drawAsciiImage(is, os, image); //from image_output.cpp
    return 0;
}

int assignment3( std::istream& is, std::ostream& os )
{
    PPM ppm;
    stripedDiagonalPattern(is,os,ppm); //from image_drawing.cpp
    writeUserImage(is,os,ppm); //from image_output.cpp
    return 0;
}

// inquisitor - practice-exam1
int inquisitor(std::istream& is, std::ostream& os)
{
    return askInquisitorQuestions(is,os);
}

// ASCII - practice-exam1
int simple_squares_ascii(std::istream& is, std::ostream& os)
{
    Image image;
    simpleSquaresPattern(is,os,image);
    drawAsciiImage(is,os,image);

    return 0;
}
