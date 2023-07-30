---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-max.hpp
    title: chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-min.hpp
    title: chmin
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/fast-ios.hpp
    title: Fast I/O
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: input
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/io-set.hpp
    title: specify output precision
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/make-vector.hpp
    title: make vector
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/pair-ios.hpp
    title: pair I/O
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"test/aoj/itp1_1_a.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/cpp-template/header/change-max.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T1, typename T2 >\n  inline bool\
    \ chmax(T1 &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/change-min.hpp\"\n\nnamespace luz {\n\
    \n  template < typename T1, typename T2 >\n  inline bool chmin(T1 &a, T2 b) {\n\
    \    return a > b and (a = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/fast-ios.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void set_fast_ios() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/input.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/input.hpp\"\
    \n\n#line 6 \"src/cpp-template/header/input.hpp\"\n\nnamespace luz {\n\n  template\
    \ < typename T = i64 >\n  T input() {\n    T tmp;\n    std::cin >> tmp;\n    return\
    \ tmp;\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/io-set.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 4 \"src/cpp-template/header/io-set.hpp\"\n\n#include\
    \ <iomanip>\n#line 7 \"src/cpp-template/header/io-set.hpp\"\n\nnamespace luz {\n\
    \n  void io_set(usize precision) {\n    std::cout << std::fixed << std::setprecision(precision);\n\
    \    std::cerr << std::fixed << std::setprecision(precision);\n  }\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/make-vector.hpp\"\n\n#line 4 \"src/cpp-template/header/make-vector.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  std::vector<\
    \ T > make_vector(usize a, T b) {\n    return std::vector< T >(a, b);\n  }\n\n\
    \  template < typename... Ts >\n  auto make_vector(usize a, Ts... ts) {\n    return\
    \ std::vector< decltype(make_vector(ts...)) >(\n        a, make_vector(ts...));\n\
    \  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/pair-ios.hpp\"\n\
    \n#line 4 \"src/cpp-template/header/pair-ios.hpp\"\n#include <utility>\n\nnamespace\
    \ luz {\n\n  template < typename T1, typename T2 >\n  std::ostream &operator<<(std::ostream\
    \ &os, std::pair< T1, T2 > p) {\n    os << \"(\" << p.first << \", \" << p.second\
    \ << \")\";\n    return os;\n  }\n\n  template < typename T1, typename T2 >\n\
    \  std::istream &operator>>(std::istream &is, std::pair< T1, T2 > &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n  }\n\n} // namespace luz\n#line 2\
    \ \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rep(const usize f, const usize l)\
    \ noexcept\n        : f(std::min(f, l)),\n          l(l) {}\n    constexpr auto\
    \ begin() const noexcept {\n      return f;\n    }\n    constexpr auto end() const\
    \ noexcept {\n      return l;\n    }\n  };\n\n  struct rrep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        --i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rrep(const usize f, const usize l)\
    \ noexcept\n        : f(l - 1),\n          l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept {\n      return f;\n    }\n    constexpr auto end()\
    \ const noexcept {\n      return l;\n    }\n  };\n\n} // namespace luz\n#line\
    \ 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#line 7 \"src/cpp-template/header/vector-ios.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename T >\n  std::ostream &operator<<(std::ostream &os,\n   \
    \                        const std::vector< T > vs) {\n    for (usize i: rep(0,\
    \ vs.size())) {\n      os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n \
    \   }\n    return os;\n  }\n\n  template < typename T >\n  std::istream &operator>>(std::istream\
    \ &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n\
    \    return is;\n  }\n\n} // namespace luz\n#line 4 \"test/aoj/itp1_1_a.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    std::cout << \"Hello World\" << std::endl;\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::set_fast_ios();\n  luz::io_set(15);\n\
    \n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/cpp-template/header/template-header.hpp\"\n\nnamespace luz {\n\
    \n  void main_() {\n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} //\
    \ namespace luz\n\nint main() {\n  luz::set_fast_ios();\n  luz::io_set(15);\n\n\
    \  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/header/change-max.hpp
  - src/cpp-template/header/change-min.hpp
  - src/cpp-template/header/fast-ios.hpp
  - src/cpp-template/header/input.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/io-set.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/make-vector.hpp
  - src/cpp-template/header/pair-ios.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/vector-ios.hpp
  isVerificationFile: true
  path: test/aoj/itp1_1_a.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp1_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp1_1_a.test.cpp
- /verify/test/aoj/itp1_1_a.test.cpp.html
title: test/aoj/itp1_1_a.test.cpp
---
