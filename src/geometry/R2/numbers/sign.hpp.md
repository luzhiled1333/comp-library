---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/R2/class/circle.hpp
    title: src/geometry/R2/class/circle.hpp
  - icon: ':warning:'
    path: src/geometry/R2/class/line.hpp
    title: src/geometry/R2/class/line.hpp
  - icon: ':x:'
    path: src/geometry/R2/class/point.hpp
    title: src/geometry/R2/class/point.hpp
  - icon: ':warning:'
    path: src/geometry/R2/class/polygon.hpp
    title: src/geometry/R2/class/polygon.hpp
  - icon: ':warning:'
    path: src/geometry/R2/class/segment.hpp
    title: src/geometry/R2/class/segment.hpp
  - icon: ':x:'
    path: src/geometry/R2/class/vector.hpp
    title: src/geometry/R2/class/vector.hpp
  - icon: ':x:'
    path: src/geometry/R2/utility/equals.hpp
    title: src/geometry/R2/utility/equals.hpp
  - icon: ':x:'
    path: src/geometry/R2/utility/sign.hpp
    title: src/geometry/R2/utility/sign.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: unit-test/geometry/R2/class/vector-and-point.test.cpp
    title: unit-test/geometry/R2/class/vector-and-point.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/R2/numbers/sign.hpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/geometry/R2/numbers/sign.hpp\"\n\nnamespace luz::numbers::sign\
    \ {\n\n  constexpr i32 negative = -1;\n  constexpr i32 zero     = 0;\n  constexpr\
    \ i32 positive = +1;\n\n} // namespace luz::numbers::sign\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n\nnamespace\
    \ luz::numbers::sign {\n\n  constexpr i32 negative = -1;\n  constexpr i32 zero\
    \     = 0;\n  constexpr i32 positive = +1;\n\n} // namespace luz::numbers::sign\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/geometry/R2/numbers/sign.hpp
  requiredBy:
  - src/geometry/R2/utility/sign.hpp
  - src/geometry/R2/utility/equals.hpp
  - src/geometry/R2/class/segment.hpp
  - src/geometry/R2/class/polygon.hpp
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/line.hpp
  - src/geometry/R2/class/circle.hpp
  - src/geometry/R2/class/vector.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - unit-test/geometry/R2/class/vector-and-point.test.cpp
documentation_of: src/geometry/R2/numbers/sign.hpp
layout: document
redirect_from:
- /library/src/geometry/R2/numbers/sign.hpp
- /library/src/geometry/R2/numbers/sign.hpp.html
title: src/geometry/R2/numbers/sign.hpp
---
