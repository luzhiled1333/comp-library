#include "matrix.hpp"

int main() {
  int k = 5;

  luz::Matrix< 3, 3, int > mat;
  luz::Matrix< 3, 3, int > uku(5 * mat);
  uku = mat * k;
}
