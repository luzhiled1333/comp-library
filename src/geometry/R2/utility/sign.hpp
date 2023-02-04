#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/geometry/R2/numbers/eps.hpp"
#include "src/geometry/R2/numbers/sign.hpp"

namespace luz::R2 {

  template < typename R >
  i32 sign(R r) {
    if (r < -eps()) return numbers::sign::negative;
    if (r > +eps()) return numbers::sign::positive;
    return numbers::sign::zero;
  }

} // namespace luz::R2
