#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/geometry/R2/numbers/sign.hpp"
#include "src/geometry/R2/utility/sign.hpp"

namespace luz::R2 {

  template < typename R >
  i32 equals(R r0, R r1) {
    return sign(r1 - r0) == numbers::sign::zero;
  }

} // namespace luz::R2
