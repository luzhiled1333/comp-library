#pragma once

#include "src/geometry/R2/utility/equals.hpp"

#include <vector>

namespace luz::R2 {

  template < typename R >
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

    friend bool equals(const Vector &v0, const Vector &v1) {
      return equals(v0.x(), v1.x()) and equals(v0.y(), v1.y());
    }

    Vector &operator+=(const Vector &v) {
      x_ += v.x_;
      y_ += v.y_;
      return *this;
    }
    Vector &operator-=(const Vector &v) {
      x_ -= v.x_;
      y_ -= v.y_;
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

    Vector &operator*=(const R r) {
      x_ *= r;
      y_ *= r;
      return *this;
    }
    Vector &operator/=(const R r) {
      x_ /= r;
      y_ /= r;
      return *this;
    }

    Vector operator*(const R r) const {
      return Vector(*this) *= r;
    }
    Vector operator/(const R r) const {
      return Vector(*this) /= r;
    }

    friend Vector operator*(const R r, const Vector &v) {
      return Vector(v) *= r;
    }
  };

  template < typename R >
  using Vectors = std::vector< Vector< R > >;

} // namespace luz::R2
