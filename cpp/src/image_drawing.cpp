// src/image_drawing.cpp
#include "image_menu.h"

void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image )
{
    const int height = getInteger(is,os, "Image height? "); 
    const int width = getInteger(is,os, "Image width? "); 

    image.setHeight(height);
    image.setWidth(width);

    const int h = image.getHeight();
    const int w = image.getWidth();

    int red=0;
    int blue=0;
    int green=0;
    //int mid=h/2;

    for (int row=0; row<h; row++){ //r=current row # in loop, h=image height
        for (int column=0; column<w; column++){
            //red: top-half=0, bottom-half=255
            if (row<(h/2)) red=0;
            else red=255;
            if (column<(w/2)) blue=0;
            else blue=255;
            green=((2*row)+(2*column)%256);
            //const int red  = ( row < ( h/2 ) ) ? 0 : 255;//ternary operator: (row < (height/2 (halfway-point)) ) ? return 0 if_true (top) : return 255 if_false(bottom)
            //blue: left-half=0 right-half=255
            //const int blue = ( column < ( w/2 ) ) ? 0 : 255;//ternary operator (column < (width/2 (halfway-point)) ) then return 0(left-half), else return 255(right-half)
            //const int green = (2*row + 2*column) % 256;//calculated exactly as in instructions
                                                       //
            image.setChannel(row, column, 0, red);
            image.setChannel(row, column, 1, green);
            image.setChannel(row, column, 2, blue);
        }
    }
}

void stripedDiagonalPattern( std::istream& is, std::ostream& os, PPM& p )
{
    const int h = getInteger(is,os,"Image height? ");
    const int w = getInteger(is,os,"Image width? ");


    p.setHeight(h);
    p.setWidth(w);

    int _mcv = (h + w)/3;
    if (_mcv > 255) _mcv = 255;
    p.setMaxColorValue(_mcv);

//    std::cout<<_mcv<<"\n"; //FOR TESTING/DEBUGGING
    
    for (int row=0; row<h; row++){
        for (int col=0; col<w; col++){
            int r=0, g=0, b=0;

            //red
            if (row < (h/2) ) {
                //top-half
                r = 0;
            } else {
                //bottom-half
                if (row % 3 == 0) {
                    r = 0;                //multiple of 3
                } else {
                    r = _mcv;             //non-multiple of 3=mcv
                }
            }

            //green
            g = (row + w - col - 1) / (_mcv + 1); //green = remainder of (row+width-column-1)

            //blue
            if (col < r) {
                b = 0;                  //bluie pixel=0 if column # is less than row number (loop iteration values)
            } else {
                b = _mcv;               //blue = mcv in all other cases.
            }
            p.setPixel(row,col,r,g,b);
        }
    }
}
