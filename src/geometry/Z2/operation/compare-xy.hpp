#include "src/geometry/Z2/class/vector.hpp"

namespace luz::Z2 {

  template< typename Z >
  bool compare_xy(const Vector< Z > &v0, const Vector< Z > &v1) {
    if (v0.x() != v1.x()) return v0.x() < v1.x();
    return v0.y() < v1.y();
  }

}
