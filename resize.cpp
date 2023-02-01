#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <string>
#include "processing.h"
#include "Matrix.h"
#include "Image.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 4 && argc !=5)
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]" << endl;
        cout << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return -1;
    }

    int width = atoi(argv[3]);
    int height = 0;
    
    if(argc == 5)
    {
        height = atoi(argv[4]);
    }
    
    string in = argv[1];
    ifstream is(in);
    
    Image *image = new Image;
    Image_init(image, is);
    
    if(argc == 4)
    {
        height = Image_height(image);
    }
    else if(height > Image_height(image) || width > Image_width(image))
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]" << endl;
        cout << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return -1;
    }
    
    seam_carve(image, width, height);
    
    string out = argv[2];
    ofstream os(out);
    
    Image_print(image, os);
    delete image;
    os.close();
    is.close();
}
