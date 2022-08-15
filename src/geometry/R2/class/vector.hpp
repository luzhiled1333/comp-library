#pragma once

#include <vector>

namespace luz {
namespace R2 {

  template< typename R >
  class Vector {

    R x_, y_;

   public:
    Vector(): x_(0), y_(0) {}
    Vector(R x, R y): x_(x), y_(y) {}

    R x() const {
      return x_;
    }

    R y() const {
      return y_;
    }

    bool operator==(const Vector &v) const {
      return x_ == v.x_ and y_ == v.y_;
    }
    bool operator!=(const Vector &v) const {
      return x_ != v.x_ or  y_ != v.y_;
    }

    Vector &operator+=(const Vector &v) {
      x_ += v.x_; y_ += v.y_;
      return *this;
    }
    Vector &operator-=(const Vector &v) {
      x_ -= v.x_; y_ -= v.y_;
      return *this;
    }

    Vector operator+(const Vector &v) const {
      return Vector(*this) += v;
    }
    Vector operator-(const Vector &v) const {
      return Vector(*this) -= v;
    }

    Vector operator+() const {
      return *this;
    }
    Vector operator-() const {
      return Vector() - *this;
    }

  };

  template< typename R >
  using Vectors = std::vector< Vector<R> >;

} // namespace R2
} // namespace luz
