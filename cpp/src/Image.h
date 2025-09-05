// src/Image.h
#pragma once
#include <vector>


class Image
{
    private:
        int height_;
        int width_;
        std::vector<int> data_;

    public:
    Image(); //Default constructor (image with 0h x 0w)
    Image( const int& height_, const int& width_); //Constructor with parameters

    int getHeight() const; //Returns the height of the Image
    int getWidth() const; //Returns the width of the Image
                          
    bool indexValid( const int& row, const int& column, const int& channel ) const; //Checks if row,column,channel are in legal limits (ret true of yes, ret false of not)
    int index( const int& row, const int& column, const int& channel ) const; //Returns the index into the data vector for the location specified by row, column, and channel.
    int getChannel( const int& row, const int& column, const int& channel ) const; //Returns an int of the value in the data vector at the location specified
    void setHeight( const int& height_ ); //Change the height of the Image
    void setWidth( const int& width_ ); //Change the width of the Image
    void setChannel( const int& row, const int& column, const int& channel, const int& value ); //Change the value of the location specifified
};
