#include <algorithm>
#include <numeric>
#include <tuple>
#include <type_traits>

#include "src/geometry/Z2/class/line.hpp"

namespace luz::Z2 {

  template< typename Z >
  std::tuple< Z, Z, Z > normalize_l(const Line<Z> &l) {
    static_assert(std::is_signed<Z>::value == true);
    Z a = l.p1().y() - l.p0().y();
    Z b = l.p0().x() - l.p1().x();
    {
      Z g = std::gcd(a, b);
      a /= g;
      b /= g;
    }
    Z c = a * l.p0().x() + b * l.p0().y();

    std::tuple< Z, Z, Z > p(+a, +b, +c), m(-a, -b, -c);
    return std::max(p, m);
  }

} // namespace luz::Z2
