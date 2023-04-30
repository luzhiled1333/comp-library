#pragma once

namespace luz::monoid {

  template < typename T >
  class RangeSumQueryMonoid {

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return a + b;
    }

    static constexpr T identity() {
      return T();
    }
  };

} // namespace luz::monoid
