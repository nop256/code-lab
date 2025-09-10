// src/PPM.h
#pragma once
#include <"Image.h">
#include <ostream>
//#include <iosfwd> //this one, or ostream?


class PPM : public Image
{
    public:
        int mcv_;
        
        PPM( );// : Image(), mcv_(1) {} //Default constructor, default mcv of 1
        PPM( const int& height, const int& width );// : Image(height,width), mcv_(1) {} //mcv set to 1, Image portion initialized with height and width parameters

        int getMaxColorValue( ) const; /*Returns maximum color value of the PPM*/
        bool valueValid( const int& value ) const; /*Checks if value is a legal color for image. Meaning, at least 0 and no more than MCV. Returns true if legal, else False.*/
        void setMaxColorValue( const int& max_color_value ); /*Change the max color value of PPM. Only values 1 to 255, inclusive. If the value is not accepted, make no changes.*/
        void setChannel( const int& row, const int& column, const int& channel, const int& value );/*If `value` is valid (use valueValid method above), then call Image::setChannel() passing in the parameters row, column, channel, value). if value is NOT valid, do nothing.*/
        void setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue );/*Set all three channels for the specified pixel. Should use setChannel to do the work.*/
        void writeStream(std::ostream& os) const;/*Writes the PPM data to the output stream `os`. Uses the format mentioned above. The first line of data is ASCII text, and the rest is binary data.*/
};
