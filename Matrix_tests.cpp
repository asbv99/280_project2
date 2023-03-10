#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(Matrix_column_of_min_value_in_row)             //Matrix_column_of_min_value_in_row
{
    Matrix *mat = new Matrix;
    
    const int width = 5;
    const int height = 5;
    int row = 2;
    int column0 = 1;
    int column1 = 2;
    int column_start = 1;
    int column_end = 3;
    int value = 1;

    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *Matrix_at(mat, row, column0) = 5;
    *Matrix_at(mat, row, column1) = 2;
    
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, row, column_start, column_end), 3);
    
    delete mat;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
