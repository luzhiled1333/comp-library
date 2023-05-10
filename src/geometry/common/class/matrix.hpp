#pragma once

#include "src/geometry/common/class/internal/matrix.hpp"

namespace luz {

  template < usize r, usize c, class T >
  class Matrix: public internal::Mat< r, c, T > {
    using internal_mat = internal::Mat< r, c, T >;

   public:
    using internal_mat::Mat;

    Matrix(const internal_mat &mat): internal_mat::Mat(mat) {}
  };

} // namespace luz
