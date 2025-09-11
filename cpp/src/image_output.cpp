// src/image_output.cpp
#include "image_menu.h"
#include <fstream>
#include <iostream>


void drawAsciiImage( std::istream& is, std::ostream& os, const Image& image )
{
    (void)is; //to avoid unused parameter warnings in compiler;
    const int height = image.getHeight();
    const int width = image.getWidth();

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            const int R = image.getChannel(row, column, 0);
            const int G = image.getChannel(row, column, 1);
            const int B = image.getChannel(row, column, 2);

            const double S = (R+G+B)/765.0;

            char nChar;

            if      (S >= 1.0) {nChar = '@';}
            else if (S >= 0.9) {nChar = '#';}
            else if (S >= 0.8) {nChar = '%';}
            else if (S >= 0.7) {nChar = '*';}
            else if (S >= 0.6) {nChar = '|';}
            else if (S >= 0.5) {nChar = '+';}
            else if (S >= 0.4) {nChar = ';';}
            else if (S >= 0.3) {nChar = '~';}
            else if (S >= 0.2) {nChar = '-';}
            else if (S >= 0.1) {nChar = '.';}
            else               {nChar = ' ';}

            os << nChar;
        }
        os << '\n';
    }
}

void writeUserImage( std::istream& is, std::ostream& os, const PPM& p )
{
    std::string filename = getString(is, os, "Output filename? ");

    //writing the pixel data
    std::ofstream output_file("out.ppm",std::ios::binary);
    if (!output_file) {
        std::cerr << "Error opening File" << std::endl;
        return;
    }

    p.writeStream(output_file);
    output_file.close();
} 
