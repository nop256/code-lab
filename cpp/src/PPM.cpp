// src/PPM.cpp
#include "PPM.h"

PPM::PPM() : Image(), mcv_(1) {} /*Creating the PPM object of type PPM class with all default constructors*/
PPM::PPM(const int& height, const int& width) : Image(height, width), mcv_(1) {}

int PPM::getMaxColorValue( ) const { return mcv_; }
bool PPM::valueValid( const int& value ) const
{
    if (0 <= value <= mcv_) return true;
    return false;
}

void PPM::setMaxColorValue( const int& max_color_value ) const
{
    if (1 <= max_color_value <= 255) mcv_=max_color_value;
}
void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value )
{
    if (valueValid(value)) {
        Image::setChannel(row, column, channel, value);
    }
}
void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue )
{
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}
