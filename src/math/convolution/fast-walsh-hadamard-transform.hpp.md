---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept : i(i) {}\n \
    \     void operator++() noexcept { ++i; }\n      constexpr usize operator*() const\
    \ noexcept { return i; }\n      constexpr bool operator!=(const itr x) const noexcept\
    \ { return i != x.i; }\n    };\n    const itr f, l;\n    constexpr rep(const usize\
    \ f, const usize l) noexcept\n      : f(std::min(f, l)), l(l) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n \
    \     constexpr itr(const usize i) noexcept : i(i) {}\n      void operator++()\
    \ noexcept { --i; }\n      constexpr usize operator*() const noexcept { return\
    \ i; }\n      constexpr bool operator!=(const itr x) const noexcept { return i\
    \ != x.i; }\n    };\n    const itr f, l;\n    constexpr rrep(const usize f, const\
    \ usize l) noexcept\n      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n} // namespace luz\n#line 5 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n \n  template< typename\
    \ T >\n  void impl_fwht(std::vector< T > &f, bool is_inverse_transform) {\n  \
    \  const usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    usize i = 1;\n\
    \    while (i < n) {\n      usize j = 0;\n      while (j < n) {\n        for (usize\
    \ k: rep(0, i)) {\n          T s = f[j + k], t = f[j + k + i];\n          f[j\
    \ + k    ] = s + t;\n          f[j + k + i] = s - t;\n        }\n \n        j\
    \ += (i << 1);\n      }\n \n      i = i << 1;\n    }\n \n    if (not is_inverse_transform)\
    \ return;\n \n    T n_inv = T(1) / T(n);\n    for (auto &x: f) x *= n_inv;\n \
    \ }\n \n  template< typename T >\n  void fast_walsh_hadamard_transform(std::vector<\
    \ T > &f) {\n    impl_fwht(f, false);\n  }\n \n  template< typename T >\n  void\
    \ fast_walsh_hadamard_inverse_transform(std::vector< T > &f) {\n    impl_fwht(f,\
    \ true);\n  }\n \n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/rep.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n \n  template< typename T >\n  void impl_fwht(std::vector<\
    \ T > &f, bool is_inverse_transform) {\n    const usize n = f.size();\n    assert((n\
    \ & (n - 1)) == 0);\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n\
    \      while (j < n) {\n        for (usize k: rep(0, i)) {\n          T s = f[j\
    \ + k], t = f[j + k + i];\n          f[j + k    ] = s + t;\n          f[j + k\
    \ + i] = s - t;\n        }\n \n        j += (i << 1);\n      }\n \n      i = i\
    \ << 1;\n    }\n \n    if (not is_inverse_transform) return;\n \n    T n_inv =\
    \ T(1) / T(n);\n    for (auto &x: f) x *= n_inv;\n  }\n \n  template< typename\
    \ T >\n  void fast_walsh_hadamard_transform(std::vector< T > &f) {\n    impl_fwht(f,\
    \ false);\n  }\n \n  template< typename T >\n  void fast_walsh_hadamard_inverse_transform(std::vector<\
    \ T > &f) {\n    impl_fwht(f, true);\n  }\n \n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: false
  path: src/math/convolution/fast-walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '2022-07-21 13:11:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc212_h.test.cpp
documentation_of: src/math/convolution/fast-walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/src/math/convolution/fast-walsh-hadamard-transform.hpp
- /library/src/math/convolution/fast-walsh-hadamard-transform.hpp.html
title: src/math/convolution/fast-walsh-hadamard-transform.hpp
---
