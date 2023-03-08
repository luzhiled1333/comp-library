#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz::internal {

  template < class T >
  struct ButterflyInfo {
    static std::vector< T > roots, iroots, rate3, irate3;

    ButterflyInfo() {
      if (not roots.empty()) {
        return;
      }

      const usize mod = T::get_mod();
      assert(mod >= 3 && mod % 2 == 1);
      usize tmp      = mod - 1;
      usize max_base = 0;
      while (tmp % 2 == 0) {
        tmp >>= 1;
        max_base++;
      }
      T root = 2;
      while (root.pow((mod - 1) >> 1) == T(1)) {
        root += 1;
      }
      assert(root.pow(mod - 1) == T(1));

      roots.resize(max_base + 1);
      iroots.resize(max_base + 1);
      rate3.resize(max_base + 1);
      irate3.resize(max_base + 1);

      roots[max_base]  = root.pow((mod - 1) >> max_base);
      iroots[max_base] = T(1) / roots[max_base];
      for (usize i: rrep(0, max_base)) {
        roots[i]  = roots[i + 1] * roots[i + 1];
        iroots[i] = iroots[i + 1] * iroots[i + 1];
      }
      T prod = 1, iprod = 1;
      for (usize i: rep(0, max_base - 2)) {
        rate3[i]  = roots[i + 3] * prod;
        irate3[i] = iroots[i + 3] * iprod;
        prod *= iroots[i + 3];
        iprod *= roots[i + 3];
      }
    }
  };
  template < typename mint >
  std::vector< mint > ButterflyInfo< mint >::roots =
      std::vector< mint >();
  template < typename mint >
  std::vector< mint > ButterflyInfo< mint >::iroots =
      std::vector< mint >();
  template < typename mint >
  std::vector< mint > ButterflyInfo< mint >::rate3 =
      std::vector< mint >();
  template < typename mint >
  std::vector< mint > ButterflyInfo< mint >::irate3 =
      std::vector< mint >();

  template < typename T >
  void butterfly(std::vector< T > &a) {
    usize n = a.size();
    assert((n & (n - 1)) == 0);
    usize h = __builtin_ctz(n);
    ButterflyInfo< T > info;
    usize len = 0;
    T imag    = info.roots[2];
    if (h & 1) {
      usize p = 1 << (h - 1);
      for (usize i: rep(0, p)) {
        T r      = a[i + p];
        a[i + p] = a[i] - r;
        a[i] += r;
      }
      len++;
    }
    while (len + 1 < h) {
      usize p = 1 << (h - len - 2);
      for (usize i: rep(0, p)) {
        T a0         = a[i + 0 * p];
        T a1         = a[i + 1 * p];
        T a2         = a[i + 2 * p];
        T a3         = a[i + 3 * p];
        T a1na3imag  = (a1 - a3) * imag;
        T a0a2       = a0 + a2;
        T a1a3       = a1 + a3;
        T a0na2      = a0 - a2;
        a[i + 0 * p] = a0a2 + a1a3;
        a[i + 1 * p] = a0a2 - a1a3;
        a[i + 2 * p] = a0na2 + a1na3imag;
        a[i + 3 * p] = a0na2 - a1na3imag;
      }
      T rot = info.rate3[0];
      for (usize s: rep(1, 1 << len)) {
        usize offset = s << (h - len);
        T rot2       = rot * rot;
        T rot3       = rot2 * rot;
        for (usize i: rep(0, p)) {
          T a0                  = a[i + offset + 0 * p];
          T a1                  = a[i + offset + 1 * p] * rot;
          T a2                  = a[i + offset + 2 * p] * rot2;
          T a3                  = a[i + offset + 3 * p] * rot3;
          T a1na3imag           = (a1 - a3) * imag;
          T a0a2                = a0 + a2;
          T a1a3                = a1 + a3;
          T a0na2               = a0 - a2;
          a[i + offset + 0 * p] = a0a2 + a1a3;
          a[i + offset + 1 * p] = a0a2 - a1a3;
          a[i + offset + 2 * p] = a0na2 + a1na3imag;
          a[i + offset + 3 * p] = a0na2 - a1na3imag;
        }
        rot *= info.rate3[__builtin_ctz(~s)];
      }
      len += 2;
    }
  }

  template < typename T >
  void butterfly_inv(std::vector< T > &a) {
    usize n = a.size();
    assert((n & (n - 1)) == 0);
    usize h = __builtin_ctz(n);
    ButterflyInfo< T > info;
    usize len = h;
    T iimag   = info.iroots[2];
    while (len > 1) {
      usize p = 1 << (h - len);
      for (usize i: rep(0, p)) {
        T a0         = a[i + 0 * p];
        T a1         = a[i + 1 * p];
        T a2         = a[i + 2 * p];
        T a3         = a[i + 3 * p];
        T a2na3iimag = (a2 - a3) * iimag;
        T a0na1      = a0 - a1;
        T a0a1       = a0 + a1;
        T a2a3       = a2 + a3;
        a[i + 0 * p] = a0a1 + a2a3;
        a[i + 1 * p] = (a0na1 + a2na3iimag);
        a[i + 2 * p] = (a0a1 - a2a3);
        a[i + 3 * p] = (a0na1 - a2na3iimag);
      }
      T irot = info.irate3[0];
      for (usize s: rep(1, 1 << (len - 2))) {
        usize offset = s << (h - len + 2);
        T irot2      = irot * irot;
        T irot3      = irot2 * irot;
        for (usize i: rep(0, p)) {
          T a0                  = a[i + offset + 0 * p];
          T a1                  = a[i + offset + 1 * p];
          T a2                  = a[i + offset + 2 * p];
          T a3                  = a[i + offset + 3 * p];
          T a2na3iimag          = (a2 - a3) * iimag;
          T a0na1               = a0 - a1;
          T a0a1                = a0 + a1;
          T a2a3                = a2 + a3;
          a[i + offset + 0 * p] = a0a1 + a2a3;
          a[i + offset + 1 * p] = (a0na1 + a2na3iimag) * irot;
          a[i + offset + 2 * p] = (a0a1 - a2a3) * irot2;
          a[i + offset + 3 * p] = (a0na1 - a2na3iimag) * irot3;
        }
        irot *= info.irate3[__builtin_ctz(~s)];
      }
      len -= 2;
    }
    if (len > 0) {
      usize p = 1 << (h - 1);
      for (usize i: rep(0, p)) {
        T ajp = a[i] - a[i + p];
        a[i] += a[i + p];
        a[i + p] = ajp;
      }
    }
  }

} // namespace luz::internal

namespace luz {

  template < typename T >
  std::vector< T > modint_convolution(std::vector< T > f,
                                      std::vector< T > g) {
    assert(not f.empty() and not g.empty());
    usize n = f.size(), m = g.size();
    usize s = 1;
    while (s < n + m - 1) s <<= 1;
    f.resize(s);
    g.resize(s);
    internal::butterfly(f);
    internal::butterfly(g);
    T s_inv = T(1) / s;
    for (usize i: rep(0, s)) {
      f[i] *= g[i] * s_inv;
    }
    internal::butterfly_inv(f);
    f.resize(n + m - 1);
    return f;
  }

} // namespace luz
