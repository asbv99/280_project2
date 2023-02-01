#include <cassert>
#include "Image.h"
#include "Matrix.h"

// REQUIRES: img points to an Image
//           0 < width <= MAX_MATRIX_WIDTH
//           0 < height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
  //assert(false);
    
    (*img).width = width;
    (*img).height = height;
    
    Matrix_init(&(*img).red_channel, width, height);
    Matrix_init(&(*img).green_channel, width, height);
    Matrix_init(&(*img).blue_channel, width, height);
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is)
{
  //assert(false);
    std::string PPM;
    int width, height, intensity;

    is >> PPM >> width >> height >> intensity;
    Image_init(img, width, height);

    int red, green, blue;
    int row = 0;
    int col = 0;
    
    while(is >> red >> green >> blue)
    {
        *Matrix_at(&(*img).red_channel, row, col) = red;
        *Matrix_at(&(*img).green_channel, row, col) = green;
        *Matrix_at(&(*img).blue_channel, row, col) = blue;
        ++col;
       
        if(col == width)
        {
            ++row;
            col = 0;
        }
    }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  //assert(false); // TODO Replace with your implementation!
    
    os << "P3" << "\n";
    os << (*img).width << " " << (*img).height << "\n";
    os << 255 << "\n";

    for(int row = 0; row < Image_height(img); ++row)
    {
        for(int col = 0; col < Image_width(img); ++col)
        {
            os << *Matrix_at(&(*img).red_channel, row, col) << " ";
            os << *Matrix_at(&(*img).green_channel, row, col) << " ";
            os << *Matrix_at(&(*img).blue_channel, row, col) << " ";
        }
        os << "\n";
    }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  //assert(false); // TODO Replace with your implementation!
    
    return (*img).width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  //assert(false); // TODO Replace with your implementation!
    
    return (*img).height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  //assert(false); // TODO Replace with your implementation!
   
    Pixel color;
    color.r = *Matrix_at(&(*img).red_channel, row, column);
    color.g = *Matrix_at(&(*img).green_channel, row, column);
    color.b = *Matrix_at(&(*img).blue_channel, row, column);
    return color;
    
//    int index = (row * (*img).width) + column;
//    int *prt = (*img).red_channel;
//    int *address = (prt + index);
//    return *address;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets th e pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  //assert(false); // TODO Replace with your implementation!
    
    int *Red = Matrix_at(&(*img).red_channel, row, column);
    int *Green = Matrix_at(&(*img).green_channel, row, column);
    int *Blue = Matrix_at(&(*img).blue_channel, row, column);
    
    *Red = color.r;
    *Green = color.g;
    *Blue = color.b;

}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  //assert(false); // TODO Replace with your implementation!
    
    Matrix_fill(&(*img).red_channel, color.r);
    Matrix_fill(&(*img).green_channel, color.g);
    Matrix_fill(&(*img).blue_channel, color.b);
    
}
