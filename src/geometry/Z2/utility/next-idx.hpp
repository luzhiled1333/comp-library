#include "src/cpp-template/header/type-alias.hpp"

namespace luz::Z2 {

  inline usize next_idx(usize idx, usize size) {
    return idx + 1 == size ? 0 : idx + 1;
  }

} // namespace luz::Z2
