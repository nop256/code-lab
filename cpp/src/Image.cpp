// src/Image.cpp
#include "Image.h"

Image::Image()
    : height_(0), width_(0), data_(0) {}
Image::Image( const int& height, const int& width )
    : height_(height >= 0 ? height : 0),
      width_(width >= 0 ? width : 0),
      data_( (height_ * width_ * 3) ) {}

int Image::getHeight() const //gets the Height of the Image
{ 
    return height_;
}

int Image::getWidth() const //gets the Width of the Image 
{ 
    return width_; 
}

bool Image::indexValid(const int& row, const int& column, const int& channel ) const //indexValid method for checks and verifications
{
    if (row < 0 || row >= height_) return false; //row must be non-negative and rows start counting a 0, so if row==height: it's out of bounds. 
    if (column < 0 || column >= width_) return false; //column must be non-negative
    if (channel < 0 || channel >= 3) return false; //channels can only be 3 options, so 0, 1, or 2. 3 options non-inclusive
    return true;
}

int Image::index(const int& row, const int& column, const int& channel) const //returns index into the data vector for the location
{
    return (row * width_ * 3 + column * 3) + channel;
}

int Image::getChannel( const int& row, const int& column, const int& channel ) const //returns int of the value in the data vector at specified by location
{
    if (!indexValid(row,column,channel)) {
        return -1;
    }
    return data_[ index(row,column,channel)]; 
}
void Image::setHeight( const int& height )
{
    if (height<0) return;
    height_ = height;
    data_.resize(height_ * width_ * 3);
}

void Image::setWidth( const int& width )
{
    if (width<0) return;
    width_ = width;
    data_.resize(height_ * width_ * 3);
}

void Image::setChannel( const int& row, const int& column, const int& channel, const int& value )
{
    if (!indexValid(row,column,channel)) {
        return;
    }
        data_[index(row,column,channel)] = value;
}

