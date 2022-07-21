---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/fast-walsh-hadamard-transform.hpp\"\n\n\
    #include <cassert>\n\nnamespace luz {\n \n  template< typename T >\n  void impl_fwht(std::vector<\
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
  code: "#pragma once\n\n#include <cassert>\n\nnamespace luz {\n \n  template< typename\
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
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/fast-walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '2022-07-21 12:23:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/fast-walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/src/convolution/fast-walsh-hadamard-transform.hpp
- /library/src/convolution/fast-walsh-hadamard-transform.hpp.html
title: src/convolution/fast-walsh-hadamard-transform.hpp
---
