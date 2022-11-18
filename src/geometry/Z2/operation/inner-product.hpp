#include "src/geometry/Z2/class/vector.hpp"

namespace luz::Z2 {

  template < typename Z >
  Z inner_product(const Vector< Z > &a, const Vector< Z > &b) {
    return a.x() * b.x() + a.y() * b.y();
  }

} // namespace luz::Z2
