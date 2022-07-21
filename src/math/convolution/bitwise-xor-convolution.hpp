#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/math/convolution/fast-walsh-hadamard-transform.hpp"

#include <vector>
#include <cassert>

namespace luz {

  template< typename T >
  std::vector< T > bitwise_xor_convolution(std::vector< T > f, std::vector< T > g) {
    assert(f.size() == g.size());

    fast_walsh_hadamard_transform(f);
    fast_walsh_hadamard_transform(g);
    for (usize i: rep(0, f.size())) {
      f[i] *= g[i];
    }
    fast_walsh_hadamard_inverse_transform(f);
    return f;
  }

} // namespace luz
