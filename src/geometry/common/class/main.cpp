#include "matrix.hpp"

int main() {
  int k = 5;

  luz::Matrix< 3, 3, int > mat;
  luz::Matrix< 3, 3, int > uku(5 * mat);
  uku = mat * k;

  luz::Vector< 3, int > vec;
  luz::Vector< 3, int > latte(3 * vec);
  latte = latte * k;
}
