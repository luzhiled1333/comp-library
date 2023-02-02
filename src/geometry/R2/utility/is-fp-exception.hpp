#pragma once

namespace luz::R2 {

  template < typename R >
  bool is_fp_exception(R r) {
    return isinf(r) or is(nan)
  }

} // namespace luz::R2
