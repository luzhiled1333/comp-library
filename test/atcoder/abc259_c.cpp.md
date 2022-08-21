---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':warning:'
    path: src/sequence/run-length-encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (\u9023\u9577\u5727\u7E2E\
      , Run Length Encoding, RLE)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_c
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_c
  bundledCode: "#line 1 \"test/atcoder/abc259_c.cpp\"\n// verification-helper: PROBLEM\
    \ https://atcoder.jp/contests/abc259/tasks/abc259_c\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\
    \n\nnamespace luz {\n\n  template <typename T1, typename T2>\n  inline bool chmax(T1\
    \ &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\n  template <typename\
    \ T1, typename T2>\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a\
    \ = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { ++i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rep(const usize f, const usize l) noexcept\n\
    \      : f(std::min(f, l)), l(l) {}\n    constexpr auto begin() const noexcept\
    \ { return f; }\n    constexpr auto end() const noexcept { return l; }\n  };\n\
    \n  struct rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept : i(i) {}\n      void operator++() noexcept { --i; }\n   \
    \   constexpr usize operator*() const noexcept { return i; }\n      constexpr\
    \ bool operator!=(const itr x) const noexcept { return i != x.i; }\n    };\n \
    \   const itr f, l;\n    constexpr rrep(const usize f, const usize l) noexcept\n\
    \      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr auto begin() const\
    \ noexcept { return f; }\n    constexpr auto end() const noexcept { return l;\
    \ }\n  };\n\n} // namespace luz\n#line 2 \"src/sequence/run-length-encoding.hpp\"\
    \n\n#line 4 \"src/sequence/run-length-encoding.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n\nnamespace luz::impl {\n\n  template< typename\
    \ T >\n  std::vector< std::pair< T, usize > > rle(const std::vector< T > &vs)\
    \ {\n    std::vector< std::pair< T, usize > > result;\n    for (const auto &v:\
    \ vs) {\n      if (result.empty() or result.back().first != v) {\n        result.emplace_back(v,\
    \ 0);\n      }\n      result.back().second++;\n    }\n\n    return result;\n \
    \ }\n\n} // namespace luz::impl\n\nnamespace luz {\n\n  template< typename T >\n\
    \  std::vector< std::pair< T, usize > > run_length_encoding(const std::vector<\
    \ T > &vs) {\n    return impl::rle(vs);\n  }\n  \n  std::vector< std::pair< char,\
    \ usize > > run_length_encoding(const std::string &s) {\n    std::vector< char\
    \ > cs(s.begin(), s.end());\n    return impl::rle(cs);\n  }\n\n} // namespace\
    \ luz\n#line 7 \"test/atcoder/abc259_c.cpp\"\n\n#line 9 \"test/atcoder/abc259_c.cpp\"\
    \n#include <iostream>\n#line 11 \"test/atcoder/abc259_c.cpp\"\n\nnamespace luz\
    \ {\n\n  void main_() {\n    std::string s, t;\n    std::cin >> s >> t;\n\n  \
    \  auto ss = run_length_encoding(s);\n    auto ts = run_length_encoding(t);\n\n\
    \    usize n = std::min(ss.size(), ts.size());\n    for (usize i: rep(0, n)) {\n\
    \      auto &[sc, scnt] = ss[i];\n      auto &[tc, tcnt] = ts[i];\n\n      if\
    \ (scnt >= 2) {\n        chmin(tcnt, scnt);\n      }\n    }\n\n    if (ss == ts)\
    \ {\n      std::cout << \"Yes\" << std::endl;\n    } else {\n      std::cout <<\
    \ \"No\" << std::endl;\n    }\n\n  }\n\n} // namespace luz\n\nint main() {\n \
    \ luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_c\n\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/change-minmax.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/sequence/run-length-encoding.hpp\"\
    \n\n#include <string>\n#include <iostream>\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    std::string s, t;\n    std::cin >> s >> t;\n\n\
    \    auto ss = run_length_encoding(s);\n    auto ts = run_length_encoding(t);\n\
    \n    usize n = std::min(ss.size(), ts.size());\n    for (usize i: rep(0, n))\
    \ {\n      auto &[sc, scnt] = ss[i];\n      auto &[tc, tcnt] = ts[i];\n\n    \
    \  if (scnt >= 2) {\n        chmin(tcnt, scnt);\n      }\n    }\n\n    if (ss\
    \ == ts) {\n      std::cout << \"Yes\" << std::endl;\n    } else {\n      std::cout\
    \ << \"No\" << std::endl;\n    }\n\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/change-minmax.hpp
  - src/cpp-template/header/rep.hpp
  - src/sequence/run-length-encoding.hpp
  isVerificationFile: false
  path: test/atcoder/abc259_c.cpp
  requiredBy: []
  timestamp: '2022-08-22 07:19:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc259_c.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc259_c.cpp
- /library/test/atcoder/abc259_c.cpp.html
title: test/atcoder/abc259_c.cpp
---
