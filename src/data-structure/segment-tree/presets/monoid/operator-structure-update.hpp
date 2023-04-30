#pragma once

namespace luz::monoid {

  template < typename T, T ID >
  class RangeUpdateQueryMonoid {

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return b == ID ? a : b;
    }

    static constexpr T identity() {
      return ID;
    }
  };

} // namespace luz::monoid
