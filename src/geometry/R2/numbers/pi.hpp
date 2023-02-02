#pragma once

#include <cmath>

namespace luz::R2 {

  long double pi() {
    static long double PI = acosl(-1);
    return PI;
  }

} // namespace luz::R2
