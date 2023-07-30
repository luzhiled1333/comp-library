---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/ccw.hpp
    title: src/geometry/Z2/operation/ccw.hpp
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
  bundledCode: "#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\
    \nnamespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/geometry/Z2/constants/ccw-constants.hpp\"\
    \n\nnamespace luz::Z2::constants::ccw {\n\n  constexpr i32 COUNTER_CLOCKWISE =\
    \ +1;\n  constexpr i32 CLOCKWISE         = -1;\n  constexpr i32 ONLINE_BACK  \
    \     = +2; // c-a-b\n  constexpr i32 ONLINE_FRONT      = -2; // a-b-c\n  constexpr\
    \ i32 ON_SEGMENT        = 0;  // a-c-b\n\n} // namespace luz::Z2::constants::ccw\n"
  code: "#include \"src/cpp-template/header/int-alias.hpp\"\n\nnamespace luz::Z2::constants::ccw\
    \ {\n\n  constexpr i32 COUNTER_CLOCKWISE = +1;\n  constexpr i32 CLOCKWISE    \
    \     = -1;\n  constexpr i32 ONLINE_BACK       = +2; // c-a-b\n  constexpr i32\
    \ ONLINE_FRONT      = -2; // a-b-c\n  constexpr i32 ON_SEGMENT        = 0;  //\
    \ a-c-b\n\n} // namespace luz::Z2::constants::ccw\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/geometry/Z2/constants/ccw-constants.hpp
  requiredBy:
  - src/geometry/Z2/operation/ccw.hpp
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
documentation_of: src/geometry/Z2/constants/ccw-constants.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/constants/ccw-constants.hpp
- /library/src/geometry/Z2/constants/ccw-constants.hpp.html
title: src/geometry/Z2/constants/ccw-constants.hpp
---
