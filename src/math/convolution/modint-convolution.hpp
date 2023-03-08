#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/utility/bit/bit-width.hpp"
#include "src/utility/bit/count-trailing-0s.hpp"

#include <cassert>
#include <vector>

namespace luz::internal {

  template < class mint >
  class ButterflyInfo {
   public:
    ButterflyInfo() {
      if (not roots.empty()) {
        return;
      }

      u32 mod = mint::get_mod();
      assert(mod >= 3 && mod % 2 == 1);
      u32 tmp        = mod - 1;
      usize max_base = 0;
      while (tmp % 2 == 0) {
        tmp >>= 1;
        max_base++;
      }
      mint root = 2;
      while (root.pow((mod - 1) >> 1) == mint(1)) {
        root += 1;
      }
      assert(root.pow(mod - 1) == mint(1));
      assert(max_base >= 2);
      roots.resize(max_base + 1);
      iroots.resize(max_base + 1);
      rate3.resize(max_base + 1);
      irate3.resize(max_base + 1);

      roots[max_base]  = root.pow((mod - 1) >> max_base);
      iroots[max_base] = mint(1) / roots[max_base];
      for (usize i: rrep(0, max_base)) {
        roots[i]  = roots[i + 1] * roots[i + 1];
        iroots[i] = iroots[i + 1] * iroots[i + 1];
      }
      mint prod = 1, iprod = 1;
      for (usize i: rep(0, max_base - 2)) {
        rate3[i]  = roots[i + 3] * prod;
        irate3[i] = iroots[i + 3] * iprod;
        prod *= iroots[i + 3];
        iprod *= roots[i + 3];
      }
    }
    static std::vector< mint > roots, iroots, rate3, irate3;
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

  template < typename mint >
  void butterfly(std::vector< mint > &vs) {
    usize n = vs.size();
    assert((n & (n - 1)) == 0);
    usize h = countr_zero(n);
    ButterflyInfo< mint > info;
    assert(h < info.iroots.size());
    usize len = 0;
    mint imag = info.roots[2];
    if (h & 1) {
      usize p = 1 << (h - 1);
      for (usize i: rep(0, p)) {
        mint r    = vs[i + p];
        vs[i + p] = vs[i] - r;
        vs[i] += r;
      }
      len++;
    }
    while (len + 1 < h) {
      usize p = 1 << (h - len - 2);
      for (usize i: rep(0, p)) {
        mint a0        = vs[i + 0 * p];
        mint a1        = vs[i + 1 * p];
        mint a2        = vs[i + 2 * p];
        mint a3        = vs[i + 3 * p];
        mint a1na3imag = (a1 - a3) * imag;
        mint a0a2      = a0 + a2;
        mint a1a3      = a1 + a3;
        mint a0na2     = a0 - a2;
        vs[i + 0 * p]  = a0a2 + a1a3;
        vs[i + 1 * p]  = a0a2 - a1a3;
        vs[i + 2 * p]  = a0na2 + a1na3imag;
        vs[i + 3 * p]  = a0na2 - a1na3imag;
      }
      mint rot = info.rate3[0];
      for (usize s: rep(1, 1 << len)) {
        usize offset = s << (h - len);
        mint rot2    = rot * rot;
        mint rot3    = rot2 * rot;
        for (usize i: rep(0, p)) {
          mint a0                = vs[i + offset + 0 * p];
          mint a1                = vs[i + offset + 1 * p] * rot;
          mint a2                = vs[i + offset + 2 * p] * rot2;
          mint a3                = vs[i + offset + 3 * p] * rot3;
          mint a1na3imag         = (a1 - a3) * imag;
          mint a0a2              = a0 + a2;
          mint a1a3              = a1 + a3;
          mint a0na2             = a0 - a2;
          vs[i + offset + 0 * p] = a0a2 + a1a3;
          vs[i + offset + 1 * p] = a0a2 - a1a3;
          vs[i + offset + 2 * p] = a0na2 + a1na3imag;
          vs[i + offset + 3 * p] = a0na2 - a1na3imag;
        }
        rot *= info.rate3[__builtin_ctz(~s)];
      }
      len += 2;
    }
  }

  template < typename mint >
  void butterfly_inv(std::vector< mint > &vs) {
    usize n = vs.size();
    assert((n & (n - 1)) == 0);
    usize h = countr_zero(n);
    ButterflyInfo< mint > info;
    assert(h < info.iroots.size());
    usize len  = h;
    mint iimag = info.iroots[2];
    while (len > 1) {
      usize p = 1 << (h - len);
      for (usize i: rep(0, p)) {
        mint a0         = vs[i + 0 * p];
        mint a1         = vs[i + 1 * p];
        mint a2         = vs[i + 2 * p];
        mint a3         = vs[i + 3 * p];
        mint a2na3iimag = (a2 - a3) * iimag;
        mint a0na1      = a0 - a1;
        mint a0a1       = a0 + a1;
        mint a2a3       = a2 + a3;
        vs[i + 0 * p]   = a0a1 + a2a3;
        vs[i + 1 * p]   = (a0na1 + a2na3iimag);
        vs[i + 2 * p]   = (a0a1 - a2a3);
        vs[i + 3 * p]   = (a0na1 - a2na3iimag);
      }
      mint irot = info.irate3[0];
      for (usize s: rep(1, 1 << (len - 2))) {
        usize offset = s << (h - len + 2);
        mint irot2   = irot * irot;
        mint irot3   = irot2 * irot;
        for (usize i: rep(0, p)) {
          mint a0                = vs[i + offset + 0 * p];
          mint a1                = vs[i + offset + 1 * p];
          mint a2                = vs[i + offset + 2 * p];
          mint a3                = vs[i + offset + 3 * p];
          mint a2na3iimag        = (a2 - a3) * iimag;
          mint a0na1             = a0 - a1;
          mint a0a1              = a0 + a1;
          mint a2a3              = a2 + a3;
          vs[i + offset + 0 * p] = a0a1 + a2a3;
          vs[i + offset + 1 * p] = (a0na1 + a2na3iimag) * irot;
          vs[i + offset + 2 * p] = (a0a1 - a2a3) * irot2;
          vs[i + offset + 3 * p] = (a0na1 - a2na3iimag) * irot3;
        }
        irot *= info.irate3[__builtin_ctz(~s)];
      }
      len -= 2;
    }
    if (len > 0) {
      usize p = 1 << (h - 1);
      for (usize i: rep(0, p)) {
        mint ajp = vs[i] - vs[i + p];
        vs[i] += vs[i + p];
        vs[i + p] = ajp;
      }
    }
  }

} // namespace luz::internal

namespace luz {

  template < typename T >
  std::vector< T > modint_convolution(std::vector< T > xs,
                                      std::vector< T > ys) {
    assert(not xs.empty() and not ys.empty());
    usize n = xs.size(), m = ys.size();
    usize s = 1 << bit_width(n + m - 2);
    xs.resize(s);
    ys.resize(s);
    internal::butterfly(xs);
    internal::butterfly(ys);
    T s_inv = T(1) / s;
    for (usize i: rep(0, s)) {
      xs[i] *= ys[i] * s_inv;
    }
    internal::butterfly_inv(xs);
    xs.resize(n + m - 1);
    return xs;
  }

} // namespace luz
