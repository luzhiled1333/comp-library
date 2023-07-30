---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1181.test.cpp
    title: test/aoj/1181.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/class/dice.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include\
    \ <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr {\n      usize\
    \ i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n      void operator++()\
    \ noexcept {\n        ++i;\n      }\n      constexpr usize operator*() const noexcept\
    \ {\n        return i;\n      }\n      constexpr bool operator!=(const itr x)\
    \ const noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f,\
    \ l;\n    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
    \ l)),\n          l(l) {}\n    constexpr auto begin() const noexcept {\n     \
    \ return f;\n    }\n    constexpr auto end() const noexcept {\n      return l;\n\
    \    }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       --i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rrep(const usize f, const usize l) noexcept\n        : f(l - 1),\n\
    \          l(std::min(f, l) - 1) {}\n    constexpr auto begin() const noexcept\
    \ {\n      return f;\n    }\n    constexpr auto end() const noexcept {\n     \
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/utility/class/dice.hpp\"\
    \n\n#include <array>\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\
    \n  template < typename T >\n  class Dice {\n    // +x, -x, +y, -y, +z, -z\n \
    \   std::vector< T > dice;\n\n    static constexpr std::array< std::array< T,\
    \ 4 >, 6 > rot{\n        {{2, 5, 3, 4},\n         {4, 3, 5, 2},\n         {4,\
    \ 1, 5, 0},\n         {0, 5, 1, 4},\n         {0, 3, 1, 2},\n         {2, 1, 3,\
    \ 0}}};\n\n    void rotate(const std::array< T, 4 > &idxs) {\n      for (usize\
    \ i: rep(1, 4)) {\n        std::swap(dice[idxs[i - 1]], dice[idxs[i]]);\n    \
    \  }\n    }\n\n    void internal_rotate(usize base, isize count) {\n      if (count\
    \ != 0) {\n        bool neg = count < 0;\n        rotate(rot[base + neg]);\n \
    \       internal_rotate(base, count + (neg ? +1 : -1));\n      }\n    }\n\n  \
    \  isize count_minimize(isize count) {\n      return (count % 4 + 5) % 4 - 1;\n\
    \    }\n\n   public:\n    Dice(): dice(6) {}\n    Dice(T px, T nx, T py, T ny,\
    \ T pz, T nz)\n        : dice({px, nx, py, ny, pz, nz}) {}\n\n    void rotate_x(isize\
    \ count) {\n      internal_rotate(0, count_minimize(count));\n    }\n    void\
    \ rotate_y(isize count) {\n      internal_rotate(2, count_minimize(count));\n\
    \    }\n    void rotate_z(isize count) {\n      internal_rotate(4, count_minimize(count));\n\
    \    }\n\n    void rotate_by_id(usize idx) {\n      rotate(rot[idx]);\n    }\n\
    \n    T &right() {\n      return dice[0];\n    }\n    T &left() {\n      return\
    \ dice[1];\n    }\n    T &back() {\n      return dice[2];\n    }\n    T &front()\
    \ {\n      return dice[3];\n    }\n    T &top() {\n      return dice[4];\n   \
    \ }\n    T &bottom() {\n      return dice[5];\n    }\n\n    T &face_id(usize idx)\
    \ {\n      assert(idx < 6);\n      return dice[idx];\n    }\n\n    void normalize_as_top_front(T\
    \ t, T f) {\n      for (usize i: rep(0, 6)) {\n        if (top() == t) {\n   \
    \       for ([[maybe_unused]] usize _: rep(0, 4)) {\n            if (front() ==\
    \ f) return;\n            rotate_z(1);\n          }\n        }\n\n        rotate_by_id(2\
    \ * (i & 1));\n      }\n\n      assert(false);\n    }\n  };\n\n  template < typename\
    \ T >\n  std::vector< Dice< T > > dice_enumeration(Dice< T > dice) {\n    std::vector<\
    \ Dice< T > > result;\n\n    for (usize i: rep(0, 6)) {\n      for ([[maybe_unused]]\
    \ usize _: rep(0, 4)) {\n        result.emplace_back(dice);\n        dice.rotate_z(1);\n\
    \      }\n\n      dice.rotate_by_id(2 * (i & 1));\n    }\n\n    return result;\n\
    \  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  class Dice\
    \ {\n    // +x, -x, +y, -y, +z, -z\n    std::vector< T > dice;\n\n    static constexpr\
    \ std::array< std::array< T, 4 >, 6 > rot{\n        {{2, 5, 3, 4},\n         {4,\
    \ 3, 5, 2},\n         {4, 1, 5, 0},\n         {0, 5, 1, 4},\n         {0, 3, 1,\
    \ 2},\n         {2, 1, 3, 0}}};\n\n    void rotate(const std::array< T, 4 > &idxs)\
    \ {\n      for (usize i: rep(1, 4)) {\n        std::swap(dice[idxs[i - 1]], dice[idxs[i]]);\n\
    \      }\n    }\n\n    void internal_rotate(usize base, isize count) {\n     \
    \ if (count != 0) {\n        bool neg = count < 0;\n        rotate(rot[base +\
    \ neg]);\n        internal_rotate(base, count + (neg ? +1 : -1));\n      }\n \
    \   }\n\n    isize count_minimize(isize count) {\n      return (count % 4 + 5)\
    \ % 4 - 1;\n    }\n\n   public:\n    Dice(): dice(6) {}\n    Dice(T px, T nx,\
    \ T py, T ny, T pz, T nz)\n        : dice({px, nx, py, ny, pz, nz}) {}\n\n   \
    \ void rotate_x(isize count) {\n      internal_rotate(0, count_minimize(count));\n\
    \    }\n    void rotate_y(isize count) {\n      internal_rotate(2, count_minimize(count));\n\
    \    }\n    void rotate_z(isize count) {\n      internal_rotate(4, count_minimize(count));\n\
    \    }\n\n    void rotate_by_id(usize idx) {\n      rotate(rot[idx]);\n    }\n\
    \n    T &right() {\n      return dice[0];\n    }\n    T &left() {\n      return\
    \ dice[1];\n    }\n    T &back() {\n      return dice[2];\n    }\n    T &front()\
    \ {\n      return dice[3];\n    }\n    T &top() {\n      return dice[4];\n   \
    \ }\n    T &bottom() {\n      return dice[5];\n    }\n\n    T &face_id(usize idx)\
    \ {\n      assert(idx < 6);\n      return dice[idx];\n    }\n\n    void normalize_as_top_front(T\
    \ t, T f) {\n      for (usize i: rep(0, 6)) {\n        if (top() == t) {\n   \
    \       for ([[maybe_unused]] usize _: rep(0, 4)) {\n            if (front() ==\
    \ f) return;\n            rotate_z(1);\n          }\n        }\n\n        rotate_by_id(2\
    \ * (i & 1));\n      }\n\n      assert(false);\n    }\n  };\n\n  template < typename\
    \ T >\n  std::vector< Dice< T > > dice_enumeration(Dice< T > dice) {\n    std::vector<\
    \ Dice< T > > result;\n\n    for (usize i: rep(0, 6)) {\n      for ([[maybe_unused]]\
    \ usize _: rep(0, 4)) {\n        result.emplace_back(dice);\n        dice.rotate_z(1);\n\
    \      }\n\n      dice.rotate_by_id(2 * (i & 1));\n    }\n\n    return result;\n\
    \  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/utility/class/dice.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1181.test.cpp
documentation_of: src/utility/class/dice.hpp
layout: document
redirect_from:
- /library/src/utility/class/dice.hpp
- /library/src/utility/class/dice.hpp.html
title: src/utility/class/dice.hpp
---
