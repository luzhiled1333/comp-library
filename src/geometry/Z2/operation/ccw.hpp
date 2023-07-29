#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/geometry/Z2/class/vector.hpp"
#include "src/geometry/Z2/constants/ccw-constants.hpp"
#include "src/geometry/Z2/operation/cross-product.hpp"
#include "src/geometry/Z2/operation/inner-product.hpp"
#include "src/geometry/Z2/operation/square-norm.hpp"

namespace luz::Z2::impl_ccw {

  using namespace constants::ccw;

  template < typename Z >
  i32 ccw(const Vector< Z > &a, Vector< Z > b, Vector< Z > c) {
    b -= a;
    c -= a;

    Z cp = cross_product(b, c);
    if (cp > 0) return COUNTER_CLOCKWISE;
    if (cp < 0) return CLOCKWISE;
    if (inner_product(b, c) < 0) return ONLINE_BACK;
    if (square_norm(b) < square_norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
  }

} // namespace luz::Z2::impl_ccw

namespace luz::Z2 {

  template < typename Z >
  i32 ccw(const Vector< Z > &a, const Vector< Z > &b,
          const Vector< Z > &c) {
    return impl_ccw::ccw(a, b, c);
  }

} // namespace luz::Z2
