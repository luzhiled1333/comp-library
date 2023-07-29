---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/modint-convolution.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/sequence/wildcard-pattern-matching.hpp
    title: "\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9\u30D1\u30BF\u30FC\u30F3\u30DE\
      \u30C3\u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/bit-width.hpp
    title: "\u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
      \u6700\u5C0F\u306Ebit\u5E45 (bit_width)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc307/tasks/abc307_ex
    links:
    - https://atcoder.jp/contests/abc307/tasks/abc307_ex
    - https://atcoder.jp/contests/abc307/tasks/abc307_h
  bundledCode: "#line 1 \"test/atcoder/abc307_h/main.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_h\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_ex\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n\nnamespace luz {\n\n  template < u32 mod >\n  class StaticPrimeModInt\
    \ {\n    using modint = StaticPrimeModInt;\n\n    u32 v;\n\n   public:\n    StaticPrimeModInt():\
    \ v(0) {}\n\n    template < typename T >\n    StaticPrimeModInt(T v_) {\n    \
    \  i64 x = (i64)(v_ % (i64)mod);\n      if (x < 0) x += mod;\n      v = (u32)x;\n\
    \    }\n\n    u32 val() const {\n      return v;\n    }\n\n    modint &operator+=(const\
    \ modint &rhs) {\n      v += rhs.v;\n      if (v >= mod) v -= mod;\n      return\
    \ *this;\n    }\n\n    modint &operator-=(const modint &rhs) {\n      v += mod\
    \ - rhs.v;\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n    modint\
    \ &operator*=(const modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v % mod);\n\
    \      return *this;\n    }\n\n    modint &operator/=(const modint &rhs) {\n \
    \     *this *= rhs.inverse();\n      return *this;\n    }\n\n    modint operator+()\
    \ const {\n      return *this;\n    }\n\n    modint operator-() const {\n    \
    \  return modint() - *this;\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) += rhs;\n    }\n\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ -= rhs;\n    }\n\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\
    \n    friend bool operator==(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v == rhs.v;\n    }\n\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\n      return lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n)\
    \ const {\n      assert(0 <= n);\n      modint x = *this, r = 1;\n      while\
    \ (n) {\n        if (n & 1) r *= x;\n        x *= x;\n        n >>= 1;\n     \
    \ }\n      return r;\n    }\n\n    modint inverse() const {\n      assert(v !=\
    \ 0);\n      return pow(mod - 2);\n    }\n\n    static constexpr u32 get_mod()\
    \ {\n      return mod;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os,\n                                    const modint &m) {\n      os << m.val();\n\
    \      return os;\n    }\n  };\n\n  using modint998244353  = StaticPrimeModInt<\
    \ 998244353 >;\n  using modint1000000007 = StaticPrimeModInt< 1000000007 >;\n\n\
    } // namespace luz\n#line 2 \"src/sequence/wildcard-pattern-matching.hpp\"\n\n\
    #line 2 \"src/math/convolution/modint-convolution.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n        ++i;\n\
    \      }\n      constexpr usize operator*() const noexcept {\n        return i;\n\
    \      }\n      constexpr bool operator!=(const itr x) const noexcept {\n    \
    \    return i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rep(const\
    \ usize f, const usize l) noexcept\n        : f(std::min(f, l)),\n          l(l)\
    \ {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n  \
    \  constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n  struct\
    \ rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const usize i)\
    \ noexcept: i(i) {}\n      void operator++() noexcept {\n        --i;\n      }\n\
    \      constexpr usize operator*() const noexcept {\n        return i;\n     \
    \ }\n      constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rrep(const usize\
    \ f, const usize l) noexcept\n        : f(l - 1),\n          l(std::min(f, l)\
    \ - 1) {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n\
    \    constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n}\
    \ // namespace luz\n#line 2 \"src/utility/bit/bit-width.hpp\"\n\n#line 2 \"src/utility/bit/popcount.hpp\"\
    \n\n#line 4 \"src/utility/bit/popcount.hpp\"\n\n#line 6 \"src/utility/bit/popcount.hpp\"\
    \n\nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x\
    \ >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) &\
    \ 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x\
    \ * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n#line 4 \"src/utility/bit/bit-width.hpp\"\
    \n\n#line 6 \"src/utility/bit/bit-width.hpp\"\n\nnamespace luz {\n\n  usize bit_width(u64\
    \ x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x == 0) {\n      return\
    \ 0;\n    }\n\n#ifdef __GNUC__\n    return 64 - __builtin_clzll(x);\n#endif\n\n\
    \    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x\
    \ |= x >> 16;\n    x |= x >> 32;\n    return popcount(x);\n  }\n\n} // namespace\
    \ luz\n#line 6 \"src/math/convolution/modint-convolution.hpp\"\n\n#line 8 \"src/math/convolution/modint-convolution.hpp\"\
    \n#include <vector>\n\nnamespace luz::internal {\n\n  template < typename modint\
    \ >\n  class ButterflyInfo {\n   public:\n    ButterflyInfo() {\n      if (not\
    \ roots.empty()) {\n        return;\n      }\n\n      u32 mod = modint::get_mod();\n\
    \      assert(mod >= 3 && mod % 2 == 1);\n      u32 tmp        = mod - 1;\n  \
    \    usize max_base = 0;\n      while (tmp % 2 == 0) {\n        tmp >>= 1;\n \
    \       max_base++;\n      }\n      modint root = 2;\n      while (root.pow((mod\
    \ - 1) >> 1) == modint(1)) {\n        root += 1;\n      }\n      assert(root.pow(mod\
    \ - 1) == modint(1));\n      assert(max_base >= 2);\n      roots.resize(max_base\
    \ + 1);\n      iroots.resize(max_base + 1);\n      rate3.resize(max_base + 1);\n\
    \      irate3.resize(max_base + 1);\n\n      roots[max_base]  = root.pow((mod\
    \ - 1) >> max_base);\n      iroots[max_base] = modint(1) / roots[max_base];\n\
    \      for (usize i: rrep(0, max_base)) {\n        roots[i]  = roots[i + 1] *\
    \ roots[i + 1];\n        iroots[i] = iroots[i + 1] * iroots[i + 1];\n      }\n\
    \      modint prod = 1, iprod = 1;\n      for (usize i: rep(0, max_base - 2))\
    \ {\n        rate3[i]  = roots[i + 3] * prod;\n        irate3[i] = iroots[i +\
    \ 3] * iprod;\n        prod *= iroots[i + 3];\n        iprod *= roots[i + 3];\n\
    \      }\n    }\n    static std::vector< modint > roots, iroots, rate3, irate3;\n\
    \  };\n  template < typename modint >\n  std::vector< modint > ButterflyInfo<\
    \ modint >::roots =\n      std::vector< modint >();\n  template < typename modint\
    \ >\n  std::vector< modint > ButterflyInfo< modint >::iroots =\n      std::vector<\
    \ modint >();\n  template < typename modint >\n  std::vector< modint > ButterflyInfo<\
    \ modint >::rate3 =\n      std::vector< modint >();\n  template < typename modint\
    \ >\n  std::vector< modint > ButterflyInfo< modint >::irate3 =\n      std::vector<\
    \ modint >();\n\n  template < typename modint >\n  void butterfly(std::vector<\
    \ modint > &vs) {\n    usize n = vs.size();\n    assert((n & (n - 1)) == 0);\n\
    \    usize h = bit_width(n) - 1;\n    ButterflyInfo< modint > info;\n    assert(h\
    \ < info.iroots.size());\n    usize len   = 0;\n    modint imag = info.roots[2];\n\
    \    if (h & 1) {\n      usize p = 1 << (h - 1);\n      for (usize i: rep(0, p))\
    \ {\n        modint r  = vs[i + p];\n        vs[i + p] = vs[i] - r;\n        vs[i]\
    \ += r;\n      }\n      len++;\n    }\n    while (len + 1 < h) {\n      usize\
    \ p = 1 << (h - len - 2);\n      for (usize i: rep(0, p)) {\n        modint a0\
    \        = vs[i + 0 * p];\n        modint a1        = vs[i + 1 * p];\n       \
    \ modint a2        = vs[i + 2 * p];\n        modint a3        = vs[i + 3 * p];\n\
    \        modint a1na3imag = (a1 - a3) * imag;\n        modint a0a2      = a0 +\
    \ a2;\n        modint a1a3      = a1 + a3;\n        modint a0na2     = a0 - a2;\n\
    \        vs[i + 0 * p]    = a0a2 + a1a3;\n        vs[i + 1 * p]    = a0a2 - a1a3;\n\
    \        vs[i + 2 * p]    = a0na2 + a1na3imag;\n        vs[i + 3 * p]    = a0na2\
    \ - a1na3imag;\n      }\n      modint rot = info.rate3[0];\n      for (usize s:\
    \ rep(1, 1 << len)) {\n        usize offset = s << (h - len);\n        modint\
    \ rot2  = rot * rot;\n        modint rot3  = rot2 * rot;\n        for (usize i:\
    \ rep(0, p)) {\n          modint a0              = vs[i + offset + 0 * p];\n \
    \         modint a1              = vs[i + offset + 1 * p] * rot;\n          modint\
    \ a2              = vs[i + offset + 2 * p] * rot2;\n          modint a3      \
    \        = vs[i + offset + 3 * p] * rot3;\n          modint a1na3imag       =\
    \ (a1 - a3) * imag;\n          modint a0a2            = a0 + a2;\n          modint\
    \ a1a3            = a1 + a3;\n          modint a0na2           = a0 - a2;\n  \
    \        vs[i + offset + 0 * p] = a0a2 + a1a3;\n          vs[i + offset + 1 *\
    \ p] = a0a2 - a1a3;\n          vs[i + offset + 2 * p] = a0na2 + a1na3imag;\n \
    \         vs[i + offset + 3 * p] = a0na2 - a1na3imag;\n        }\n        rot\
    \ *= info.rate3[__builtin_ctz(~s)];\n      }\n      len += 2;\n    }\n  }\n\n\
    \  template < typename modint >\n  void butterfly_inv(std::vector< modint > &vs)\
    \ {\n    usize n = vs.size();\n    assert((n & (n - 1)) == 0);\n    usize h =\
    \ bit_width(n) - 1;\n    ButterflyInfo< modint > info;\n    assert(h < info.iroots.size());\n\
    \    usize len    = h;\n    modint iimag = info.iroots[2];\n    while (len > 1)\
    \ {\n      usize p = 1 << (h - len);\n      for (usize i: rep(0, p)) {\n     \
    \   modint a0         = vs[i + 0 * p];\n        modint a1         = vs[i + 1 *\
    \ p];\n        modint a2         = vs[i + 2 * p];\n        modint a3         =\
    \ vs[i + 3 * p];\n        modint a2na3iimag = (a2 - a3) * iimag;\n        modint\
    \ a0na1      = a0 - a1;\n        modint a0a1       = a0 + a1;\n        modint\
    \ a2a3       = a2 + a3;\n        vs[i + 0 * p]     = a0a1 + a2a3;\n        vs[i\
    \ + 1 * p]     = (a0na1 + a2na3iimag);\n        vs[i + 2 * p]     = (a0a1 - a2a3);\n\
    \        vs[i + 3 * p]     = (a0na1 - a2na3iimag);\n      }\n      modint irot\
    \ = info.irate3[0];\n      for (usize s: rep(1, 1 << (len - 2))) {\n        usize\
    \ offset = s << (h - len + 2);\n        modint irot2 = irot * irot;\n        modint\
    \ irot3 = irot2 * irot;\n        for (usize i: rep(0, p)) {\n          modint\
    \ a0              = vs[i + offset + 0 * p];\n          modint a1             \
    \ = vs[i + offset + 1 * p];\n          modint a2              = vs[i + offset\
    \ + 2 * p];\n          modint a3              = vs[i + offset + 3 * p];\n    \
    \      modint a2na3iimag      = (a2 - a3) * iimag;\n          modint a0na1   \
    \        = a0 - a1;\n          modint a0a1            = a0 + a1;\n          modint\
    \ a2a3            = a2 + a3;\n          vs[i + offset + 0 * p] = a0a1 + a2a3;\n\
    \          vs[i + offset + 1 * p] = (a0na1 + a2na3iimag) * irot;\n          vs[i\
    \ + offset + 2 * p] = (a0a1 - a2a3) * irot2;\n          vs[i + offset + 3 * p]\
    \ = (a0na1 - a2na3iimag) * irot3;\n        }\n        irot *= info.irate3[__builtin_ctz(~s)];\n\
    \      }\n      len -= 2;\n    }\n    if (len > 0) {\n      usize p = 1 << (h\
    \ - 1);\n      for (usize i: rep(0, p)) {\n        modint ajp = vs[i] - vs[i +\
    \ p];\n        vs[i] += vs[i + p];\n        vs[i + p] = ajp;\n      }\n    }\n\
    \  }\n\n} // namespace luz::internal\n\nnamespace luz {\n\n  template < typename\
    \ modint >\n  std::vector< modint > modint_convolution(std::vector< modint > f,\n\
    \                                           std::vector< modint > g) {\n    assert(not\
    \ f.empty() and not g.empty());\n    usize n = f.size(), m = g.size();\n    usize\
    \ s = 1 << bit_width(n + m - 2);\n    f.resize(s);\n    g.resize(s);\n    internal::butterfly(f);\n\
    \    internal::butterfly(g);\n    modint s_inv = modint(1) / s;\n    for (usize\
    \ i: rep(0, s)) {\n      f[i] *= g[i] * s_inv;\n    }\n    internal::butterfly_inv(f);\n\
    \    f.resize(n + m - 1);\n    return f;\n  }\n\n} // namespace luz\n#line 5 \"\
    src/sequence/wildcard-pattern-matching.hpp\"\n\n#line 8 \"src/sequence/wildcard-pattern-matching.hpp\"\
    \n\nnamespace luz {\n\n  // [warning] false positive occur expect O(1/M)\n  //\
    \           when values are randomized\n  // [note] try to use multiple mods if\
    \ necessary\n  template < class modint, class T, class Iter >\n  std::vector<\
    \ i32 > wildcard_pattern_matching(Iter f1, Iter l1,\n                        \
    \                       Iter f2, Iter l2,\n                                  \
    \             const T wildcard) {\n    usize n = l1 - f1, m = l2 - f2;\n    assert(m\
    \ <= n);\n\n    std::vector< modint > as(n), bs(n), cs(n), ss(m), ts(m), us(m);\n\
    \n    for (Iter iter = f1; iter != l1; ++iter) {\n      modint x(*iter == wildcard\
    \ ? 0 : *iter);\n      modint y(*iter == wildcard ? 0 : 1);\n      usize i = iter\
    \ - f1;\n      as[i]   = y * x * x;\n      bs[i]   = y * x * -2;\n      cs[i]\
    \   = y;\n    }\n\n    for (Iter iter = f2; iter != l2; ++iter) {\n      modint\
    \ x(*iter == wildcard ? 0 : *iter);\n      modint y(*iter == wildcard ? 0 : 1);\n\
    \      usize i = l2 - iter - 1;\n      ss[i]   = y;\n      ts[i]   = y * x;\n\
    \      us[i]   = y * x * x;\n    }\n\n    auto f = modint_convolution(as, ss);\n\
    \    auto g = modint_convolution(bs, ts);\n    auto h = modint_convolution(cs,\
    \ us);\n\n    std::vector< i32 > result(n - m + 1);\n    for (usize i: rep(0,\
    \ result.size())) {\n      usize j = i + m - 1;\n      modint x(f[j] + g[j] +\
    \ h[j]);\n      if (x.val() == 0) result[i] = 1;\n    }\n\n    return result;\n\
    \  }\n\n} // namespace luz\n#line 7 \"test/atcoder/abc307_h/main.test.cpp\"\n\n\
    #line 9 \"test/atcoder/abc307_h/main.test.cpp\"\n\nnamespace luz {\n\n  void main_()\
    \ {\n    using mint = modint998244353;\n\n    usize l, w;\n    std::string s;\n\
    \n    std::cin >> l >> w >> s;\n    s += std::string(w - 1, '.');\n    s += s.substr(0,\
    \ w - 1);\n\n    std::string p;\n    std::cin >> p;\n\n    auto wpm = wildcard_pattern_matching<\
    \ mint >(\n        s.begin(), s.end(), p.begin(), p.end(), '_');\n\n    std::cout\
    \ << std::count(wpm.begin(), wpm.end(), 1) << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_h\n\
    // verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_ex\n\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n#include \"src/sequence/wildcard-pattern-matching.hpp\"\n\n#include <iostream>\n\
    \nnamespace luz {\n\n  void main_() {\n    using mint = modint998244353;\n\n \
    \   usize l, w;\n    std::string s;\n\n    std::cin >> l >> w >> s;\n    s +=\
    \ std::string(w - 1, '.');\n    s += s.substr(0, w - 1);\n\n    std::string p;\n\
    \    std::cin >> p;\n\n    auto wpm = wildcard_pattern_matching< mint >(\n   \
    \     s.begin(), s.end(), p.begin(), p.end(), '_');\n\n    std::cout << std::count(wpm.begin(),\
    \ wpm.end(), 1) << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  - src/sequence/wildcard-pattern-matching.hpp
  - src/math/convolution/modint-convolution.hpp
  - src/cpp-template/header/rep.hpp
  - src/utility/bit/bit-width.hpp
  - src/utility/bit/popcount.hpp
  isVerificationFile: true
  path: test/atcoder/abc307_h/main.test.cpp
  requiredBy: []
  timestamp: '2023-07-29 18:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc307_h/main.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc307_h/main.test.cpp
- /verify/test/atcoder/abc307_h/main.test.cpp.html
title: test/atcoder/abc307_h/main.test.cpp
---
