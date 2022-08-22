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
  - icon: ':heavy_check_mark:'
    path: src/sequence/run-length-encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (\u9023\u9577\u5727\u7E2E\
      , Run Length Encoding, RLE)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_c
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_c
  bundledCode: "#line 1 \"test/atcoder/abc259_c.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_c\n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T1, typename T2 >\n  inline bool\
    \ chmax(T1 &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\n  template\
    \ < typename T1, typename T2 >\n  inline bool chmin(T1 &a, T2 b) {\n    return\
    \ a > b and (a = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\n\
    namespace luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr\
    \ itr(const usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n \
    \       ++i;\n      }\n      constexpr usize operator*() const noexcept {\n  \
    \      return i;\n      }\n      constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return i != x.i;\n      }\n    };\n    const itr f, l;\n\
    \    constexpr rep(const usize f, const usize l) noexcept\n        : f(std::min(f,\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 2 \"src/sequence/run-length-encoding.hpp\"\
    \n\n#line 4 \"src/sequence/run-length-encoding.hpp\"\n\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace luz::impl {\n\n  template < typename\
    \ T >\n  std::vector< std::pair< T, usize > > rle(\n      const std::vector< T\
    \ > &vs) {\n    std::vector< std::pair< T, usize > > result;\n    for (const auto\
    \ &v: vs) {\n      if (result.empty() or result.back().first != v) {\n       \
    \ result.emplace_back(v, 0);\n      }\n      result.back().second++;\n    }\n\
    \    return result;\n  }\n\n} // namespace luz::impl\n\nnamespace luz {\n\n  template\
    \ < typename T >\n  std::vector< std::pair< T, usize > > run_length_encoding(\n\
    \      const std::vector< T > &vs) {\n    return impl::rle(vs);\n  }\n\n  std::vector<\
    \ std::pair< char, usize > > run_length_encoding(\n      const std::string &s)\
    \ {\n    std::vector< char > cs(s.begin(), s.end());\n    return impl::rle(cs);\n\
    \  }\n\n} // namespace luz\n#line 7 \"test/atcoder/abc259_c.test.cpp\"\n\n#line\
    \ 9 \"test/atcoder/abc259_c.test.cpp\"\n#include <iostream>\n#line 11 \"test/atcoder/abc259_c.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    std::string s, t;\n    std::cin >>\
    \ s >> t;\n\n    auto ss = run_length_encoding(s);\n    auto ts = run_length_encoding(t);\n\
    \n    usize n = std::min(ss.size(), ts.size());\n    for (usize i: rep(0, n))\
    \ {\n      auto &[sc, scnt] = ss[i];\n      auto &[tc, tcnt] = ts[i];\n\n    \
    \  if (scnt >= 2) {\n        chmin(tcnt, scnt);\n      }\n    }\n\n    if (ss\
    \ == ts) {\n      std::cout << \"Yes\" << std::endl;\n    } else {\n      std::cout\
    \ << \"No\" << std::endl;\n    }\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_c\n\
    \n#include \"src/cpp-template/header/change-minmax.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/sequence/run-length-encoding.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    std::string s, t;\n    std::cin >> s >> t;\n\n\
    \    auto ss = run_length_encoding(s);\n    auto ts = run_length_encoding(t);\n\
    \n    usize n = std::min(ss.size(), ts.size());\n    for (usize i: rep(0, n))\
    \ {\n      auto &[sc, scnt] = ss[i];\n      auto &[tc, tcnt] = ts[i];\n\n    \
    \  if (scnt >= 2) {\n        chmin(tcnt, scnt);\n      }\n    }\n\n    if (ss\
    \ == ts) {\n      std::cout << \"Yes\" << std::endl;\n    } else {\n      std::cout\
    \ << \"No\" << std::endl;\n    }\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/change-minmax.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/sequence/run-length-encoding.hpp
  isVerificationFile: true
  path: test/atcoder/abc259_c.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 19:09:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc259_c.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc259_c.test.cpp
- /verify/test/atcoder/abc259_c.test.cpp.html
title: test/atcoder/abc259_c.test.cpp
---
