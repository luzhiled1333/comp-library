---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/fast-ios.hpp
    title: src/cpp-template/header/fast-ios.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/includes.hpp
    title: src/cpp-template/header/includes.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: src/cpp-template/header/input.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/io-set.hpp
    title: src/cpp-template/header/io-set.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/make-vector.hpp
    title: src/cpp-template/header/make-vector.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/pair-ios.hpp
    title: src/cpp-template/header/pair-ios.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: src/cpp-template/header/rep.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: src/cpp-template/header/type-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/vector-ios.hpp
    title: src/cpp-template/header/vector-ios.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/cpp-template/header/includes.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cstddef>\n#include <cstdint>\n#include <iomanip>\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n#line 2 \"src/cpp-template/header/template-header.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\nnamespace luz {\n\n\
    \  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32\
    \ = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n  \n} // namespace luz\n#line 4 \"src/cpp-template/header/template-header.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\nnamespace luz {\n\n  struct\
    \ rep {\n    struct itr {\n      usize i;\n      constexpr itr(const usize i)\
    \ noexcept : i(i) {}\n      void operator++() noexcept { ++i; }\n      constexpr\
    \ usize operator*() const noexcept { return i; }\n      constexpr bool operator!=(const\
    \ itr x) const noexcept { return i != x.i; }\n    };\n    const itr f, l;\n  \
    \  constexpr rep(const usize f, const usize l) noexcept\n      : f(std::min(f,\
    \ l)), l(l) {}\n    constexpr auto begin() const noexcept { return f; }\n    constexpr\
    \ auto end() const noexcept { return l; }\n  };\n\n  struct rrep {\n    struct\
    \ itr {\n      usize i;\n      constexpr itr(const usize i) noexcept : i(i) {}\n\
    \      void operator++() noexcept { --i; }\n      constexpr usize operator*()\
    \ const noexcept { return i; }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept { return i != x.i; }\n    };\n    const itr f, l;\n    constexpr rrep(const\
    \ usize f, const usize l) noexcept\n      : f(l - 1), l(std::min(f, l) - 1) {}\n\
    \    constexpr auto begin() const noexcept { return f; }\n    constexpr auto end()\
    \ const noexcept { return l; }\n  };\n\n} // namespace luz\n#line 6 \"src/cpp-template/header/template-header.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/fast-ios.hpp\"\n\nnamespace luz {\n\n  void\
    \ set_fast_ios() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/io-set.hpp\"\n\n\
    namespace luz {\n\n  void io_set(usize precision) {\n    std::cout << std::fixed\
    \ << std::setprecision(precision);\n    std::cerr << std::fixed << std::setprecision(precision);\n\
    \  }\n\n} // namespace luz\n#line 9 \"src/cpp-template/header/template-header.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/input.hpp\"\n\nnamespace luz {\n\n  template<\
    \ typename T = i64 > T input() {\n    T tmp;\n    std::cin >> tmp;\n    return\
    \ tmp;\n  }\n\n} // namespace luz\n#line 11 \"src/cpp-template/header/template-header.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\nnamespace luz {\n\n  template< typename T >\n  std::ostream &operator<<(std::ostream\
    \ &os, std::vector< T > &vs) {\n    for (usize i: rep(0, vs.size())) {\n     \
    \ os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n    }\n    return os;\n\
    \  }\n\n  template< typename T >\n  std::istream &operator>>(std::istream &is,\
    \ std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n    return\
    \ is;\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/pair-ios.hpp\"\
    \n\nnamespace luz {\n\n  template< typename T1, typename T2 >\n  std::ostream\
    \ &operator<<(std::ostream &os, std::pair < T1, T2 > &p) {\n    os << \"(\" <<\
    \ p.first << \", \" << p.second << \")\";\n    return os;\n  }\n\n  template<\
    \ typename T1, typename T2 >\n  std::istream &operator>>(std::istream &is, std::pair<\
    \ T1, T2 > &p) {\n    is >> p.first >> p.second;\n    return is;\n  }\n\n} //\
    \ namespace luz\n#line 14 \"src/cpp-template/header/template-header.hpp\"\n\n\
    #line 2 \"src/cpp-template/header/make-vector.hpp\"\n\nnamespace luz {\n\n  template\
    \ <typename T>\n  std::vector<T> make_vector(usize a, T b) {\n    return std::vector<T>(a,\
    \ b);\n  }\n\n  template <typename... Ts>\n  auto make_vector(usize a, Ts... ts)\
    \ {\n    return std::vector<decltype(make_vector(ts...))>(a, make_vector(ts...));\n\
    \  }\n\n} // namespace luz\n#line 16 \"src/cpp-template/header/template-header.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\nnamespace luz {\n\
    \n  template <typename T1, typename T2>\n  inline bool chmax(T1 &a, T2 b) {\n\
    \    return a < b and (a = b, true);\n  }\n\n  template <typename T1, typename\
    \ T2>\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n#line 18 \"src/cpp-template/header/template-header.hpp\"\
    \n"
  code: '#include "src/cpp-template/header/includes.hpp"


    #include "src/cpp-template/header/type-alias.hpp"


    #include "src/cpp-template/header/rep.hpp"


    #include "src/cpp-template/header/fast-ios.hpp"

    #include "src/cpp-template/header/io-set.hpp"


    #include "src/cpp-template/header/input.hpp"


    #include "src/cpp-template/header/vector-ios.hpp"

    #include "src/cpp-template/header/pair-ios.hpp"


    #include "src/cpp-template/header/make-vector.hpp"


    #include "src/cpp-template/header/change-minmax.hpp"

    '
  dependsOn:
  - src/cpp-template/header/includes.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/fast-ios.hpp
  - src/cpp-template/header/io-set.hpp
  - src/cpp-template/header/input.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/cpp-template/header/pair-ios.hpp
  - src/cpp-template/header/make-vector.hpp
  - src/cpp-template/header/change-minmax.hpp
  isVerificationFile: false
  path: src/cpp-template/header/template-header.hpp
  requiredBy:
  - src/cpp-template/template.cpp
  timestamp: '2022-06-18 23:58:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1-1-a.test.cpp
documentation_of: src/cpp-template/header/template-header.hpp
layout: document
redirect_from:
- /library/src/cpp-template/header/template-header.hpp
- /library/src/cpp-template/header/template-header.hpp.html
title: src/cpp-template/header/template-header.hpp
---
