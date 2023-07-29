#pragma once

#include "src/geometry/R2/numbers/sign.hpp"
#include "src/geometry/R2/utility/sign.hpp"

namespace luz::R2 {

  template < typename R >
  bool equals(R r0, R r1) {
    return sign(r1 - r0) == numbers::sign::zero;
  }

} // namespace luz::R2
