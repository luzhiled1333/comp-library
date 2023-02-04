#pragma once

#include <cmath>

namespace luz::R2 {

  long double &eps() {
    static long double EPS = 1e-10;
    return EPS;
  }

  void set_eps(long double EPS) {
    eps() = EPS;
  }

} // namespace luz::R2
