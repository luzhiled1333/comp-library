#pragma once

#include "src/geometry/common/class/column-vector.hpp"

namespace luz {

  template < class T >
  class Vector2d: public ColumnVector< 2, T > {
    using c_vec = ColumnVector< 2, T >;
    using internal_mat = internal::Mat< d, 1, T >;

   public:
    using internal::Mat< d, 1, T >::Mat;

    Vector2d(const c_vec &vec): c_vec::ColumnVector(vec) {}
    Vector2d(const internal_mat &mat): internal_mat::Mat(mat) {}

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

} // namespace luz
