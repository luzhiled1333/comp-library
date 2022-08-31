#pragma once

#include <cmath>

namespace luz {
  namespace R2 {

    long double pi() {
      static long double PI = acosl(-1);
      return PI;
    }

  } // namespace R2
} // namespace luz
