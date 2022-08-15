#pragma once

#include "src/geometry/Z2/class/vector.hpp"
#include "src/geometry/Z2/operation/square.hpp"

namespace luz {

namespace Z2 {

  template <typename Z>
  Z square_norm(Vector<Z> v) {
    return square(v.x()) + square(v.y());
  }

}// namespace Z2

}// namespace luz
