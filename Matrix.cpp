#include <cassert>
#include "Matrix.h"

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height)
{
    //assert(false);
    
    (*mat).width = width;
    (*mat).height = height;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os)
{
  //assert(false);
    
    os << (*mat).width << " " << (*mat).height << "\n";

    const int *ptr = (*mat).data;
    while(ptr < (*mat).data + (*mat).width * (*mat).height)
    {
        if((ptr - (*mat).data) % (*mat).width == (*mat).width - 1)
        {
            os << *ptr << " " << "\n";
        }
        else
        {
            os << *ptr << " ";
        }
        ++ptr;
    }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat)
{
    //assert(false);

    return (*mat).width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat)
{
   //assert(false);
    
    return (*mat).height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr)
{
  //assert(false);
    
    int row = (ptr - (*mat).data) / (*mat).width;
    return row;
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr)
{
  //assert(false);

    int col = (ptr - (*mat).data) % (*mat).width;
    return col;
}


// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column)
{
//  assert(false);
    
    int index = (row * (*mat).width) + column;
    int *address = &(*mat).data[index];
    return address;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column)
{
//  assert(false);
    
    const int index = (row * (*mat).width) + column;
    const int *ptr = (*mat).data;
    const int *address = (ptr + index);
    return address;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value)
{
   // assert(false);
    
    int *fill = (*mat).data;
    while(fill < (*mat).data + (*mat).width * (*mat).height)
    {
        *fill = value;
        ++fill;
    }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value)
{
  //assert(false);
  
    int *ptr = (*mat).data;
    //int index = ptr - (*mat).data;
    int totalsize = (*mat).width * (*mat).height;
    while(ptr < (*mat).data + (*mat).width * (*mat).height)
    {
        if(Matrix_column(mat, ptr) == (*mat).width - 1 || Matrix_column(mat, ptr) == 0 || ptr > ((*mat).data + totalsize - (*mat).width - 1) || ptr < (*mat).data + (*mat).width)
        {
            *ptr = value;
        }
         ++ptr;
    }
}
             

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat)
{
  //assert(false);
    
    const int *ptr = (*mat).data;
    int max = *ptr;
    while(ptr < (*mat).data + (*mat).width * (*mat).height)
    {
        if(*ptr > max)
        {
            max = *ptr;
        }
        ++ptr;
    }
    return max;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row, int column_start, int column_end)
{
 // assert(false);
    
    int min = Matrix_max(mat);
    const int *ptr = (*mat).data;
    int col;
    
    ptr = Matrix_at(mat, row, column_start);
    while(ptr < Matrix_at(mat, row, column_end + 1))
    {
        if(*ptr < min){
            min = *ptr;
            col = Matrix_column(mat,ptr);
        }
        ++ptr;

    }
    return col;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row, int column_start, int column_end)
{
  //assert(false);
    
//    int min = Matrix_max(mat);
//    const int *ptr = (*mat).data;
//    ptr = Matrix_at(mat, row, column_start);
//    while(ptr < Matrix_at(mat, row, column_end + 1))
//    {
//        if(*ptr < min){
//            min = *ptr;
//        }
//        ++ptr;
//    }
    return *Matrix_at(mat, row , Matrix_column_of_min_value_in_row(mat, row, column_start, column_end));
}
