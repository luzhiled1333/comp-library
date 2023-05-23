#pragma once

#include "src/geometry/common/class/column-vector.hpp"

namespace luz::geometry::common {

  template < class T >
  class Vector2d: public ColumnVector< 2, T > {
    using c_vec = ColumnVector< 2, T >;

   public:
    Vector2d(const c_vec &vec): c_vec::ColumnVector(vec) {}

    const T &x() const {
      return this->as[0];
    }
    const T &y() const {
      return this->as[1];
    }

    T &x() {
      return this->as[0];
    }
    T &y() {
      return this->as[1];
    }
  };

} // namespace luz::geometry::common
