#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/geometry/common/class/internal/matrix.hpp"

namespace luz::geometry::common {

  template < usize d, class T >
  class ColumnVector: public internal::Mat< d, 1, T > {
    using internal_mat = internal::Mat< d, 1, T >;

   public:
    using internal::Mat< d, 1, T >::Mat;

    ColumnVector(const internal_mat &mat): internal_mat::Mat(mat) {}

    T norm() const {
      T result{};
      for (T a: this->as) result += a * a;
      return result;
    }
  };

} // namespace luz::geometry::common
