#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/geometry/Z2/class/polygon.hpp"
#include "src/geometry/Z2/class/segment.hpp"

namespace luz::Z2 {

  template < typename Z >
  Segments< Z > polygon_to_segments(const Polygon< Z > &poly) {
    usize n = poly.size();

    Segments< Z > segments(n);
    for (usize i: rep(0, n)) {
      segments[i] = Segment< Z >(poly[i], poly[next_idx(i, n)]);
    }

    return segments;
  }

} // namespace luz::Z2
