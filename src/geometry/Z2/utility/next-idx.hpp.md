---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
    title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/utility/next-idx.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/geometry/Z2/utility/next-idx.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  inline usize next_idx(usize idx, usize size) {\n    return idx\
    \ + 1 == size ? 0 : idx + 1;\n  }\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  inline usize next_idx(usize idx, usize size) {\n    return idx\
    \ + 1 == size ? 0 : idx + 1;\n  }\n\n} // namespace luz::Z2\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/geometry/Z2/utility/next-idx.hpp
  requiredBy:
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  timestamp: '2022-11-18 16:59:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
documentation_of: src/geometry/Z2/utility/next-idx.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/utility/next-idx.hpp
- /library/src/geometry/Z2/utility/next-idx.hpp.html
title: src/geometry/Z2/utility/next-idx.hpp
---