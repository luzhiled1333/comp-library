#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/math/convolution/fast-walsh-hadamard-transform.hpp"

#include <cassert>
#include <vector>

namespace luz {

template <typename T>
std::vector<T> bitwise_xor_convolution(std::vector<T> f, std::vector<T> g) {
  assert(f.size() == g.size());

  T inv2    = T(1) / T(2);
  auto zeta = [](T &lo, T &hi) {
    T x = lo + hi;
    T y = lo - hi;
    lo  = x;
    hi  = y;
  };
  auto mobius = [inv2](T &lo, T &hi) {
    T x = lo + hi;
    T y = lo - hi;
    lo  = x * inv2;
    hi  = y * inv2;
  };

  fast_walsh_hadamard_transform(f, zeta);
  fast_walsh_hadamard_transform(g, zeta);
  for (usize i: rep(0, f.size())) {
    f[i] *= g[i];
  }
  fast_walsh_hadamard_transform(f, mobius);
  return f;
}

}// namespace luz
