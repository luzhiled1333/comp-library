#pragma once

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

    // TODO: consider EPS
    // bool operator==(const Vector &v) const {
    //   return x_ == v.x_ and y_ == v.y_;
    // }
    // bool operator!=(const Vector &v) const {
    //   return x_ != v.x_ or  y_ != v.y_;
    // }

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
  };

  template < typename R >
  using Vectors = std::vector< Vector< R > >;

} // namespace luz::R2
