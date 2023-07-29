#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/math/convolution/modint-convolution.hpp"

#include <cassert>
#include <vector>

namespace luz {

  // [warning] false positive occur expect O(1/M)
  //           when values are randomized
  // [note] try to use multiple mods if necessary
  template < class modint, class T, class Iter >
  std::vector< i32 > wildcard_pattern_matching(Iter f1, Iter l1,
                                               Iter f2, Iter l2,
                                               const T wildcard) {
    usize n = l1 - f1, m = l2 - f2;
    assert(m <= n);

    std::vector< modint > as(n), bs(n), cs(n), ss(m), ts(m), us(m);

    for (Iter iter = f1; iter != l1; ++iter) {
      modint x(*iter == wildcard ? 0 : *iter);
      modint y(*iter == wildcard ? 0 : 1);
      usize i = iter - f1;
      as[i]   = y * x * x;
      bs[i]   = y * x * -2;
      cs[i]   = y;
    }

    for (Iter iter = f2; iter != l2; ++iter) {
      modint x(*iter == wildcard ? 0 : *iter);
      modint y(*iter == wildcard ? 0 : 1);
      usize i = l2 - iter - 1;
      ss[i]   = y;
      ts[i]   = y * x;
      us[i]   = y * x * x;
    }

    auto f = modint_convolution(as, ss);
    auto g = modint_convolution(bs, ts);
    auto h = modint_convolution(cs, us);

    std::vector< i32 > result(n - m + 1);
    for (usize i: rep(0, result.size())) {
      usize j = i + m - 1;
      modint x(f[j] + g[j] + h[j]);
      if (x.val() == 0) result[i] = 1;
    }

    return result;
  }

} // namespace luz
