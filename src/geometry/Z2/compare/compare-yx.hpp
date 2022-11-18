#include "src/geometry/Z2/class/vector.hpp"

namespace luz::Z2 {

  template < typename Z >
  class CompareYX {
   public:
    bool operator()(const Vector< Z > &v0,
                    const Vector< Z > &v1) const noexcept {
      if (v0.y() != v1.y()) return v0.y() < v1.y();
      return v0.x() < v1.x();
    }
  };

} // namespace luz::Z2
