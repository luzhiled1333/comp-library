#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/geometry/common/class/internal/matrix.hpp"

namespace luz {

  template < usize d, class T >
  class Vector: public internal::Mat< d, 1, T > {
    using internal_mat = internal::Mat< d, 1, T >;

   public:
    using internal::Mat< d, 1, T >::Mat;

    Vector(const internal_mat &mat): internal_mat::Mat(mat) {}

    const T &x() const {
      return this->as[0];
    }
    const T &y() const {
      return this->as[1];
    }
    const T &z() const {
      return this->as[2];
    }

    T &x() {
      return this->as[0];
    }
    T &y() {
      return this->as[1];
    }
    T &z() {
      return this->as[2];
    }

    T norm() const {
      T result{};
      for (T a: this->as) result += a * a;
      return result;
    }
  };

} // namespace luz
