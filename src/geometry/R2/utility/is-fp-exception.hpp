#pragma once

#include <cmath>

namespace luz::R2 {

  template < typename R >
  bool is_fp_exception(R r) {
    return std::isinf(r) or std::isnan(r);
  }

} // namespace luz::R2
