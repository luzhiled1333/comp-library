---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':heavy_check_mark:'
    path: src/sequence/coordinate-compression.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/sequence/coordinate-complession.test.cpp\"\n//\
    \ verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize\
    \ = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n        ++i;\n\
    \      }\n      constexpr usize operator*() const noexcept {\n        return i;\n\
    \      }\n      constexpr bool operator!=(const itr x) const noexcept {\n    \
    \    return i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rep(const\
    \ usize f, const usize l) noexcept\n        : f(std::min(f, l)),\n          l(l)\
    \ {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n  \
    \  constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n  struct\
    \ rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const usize i)\
    \ noexcept: i(i) {}\n      void operator++() noexcept {\n        --i;\n      }\n\
    \      constexpr usize operator*() const noexcept {\n        return i;\n     \
    \ }\n      constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rrep(const usize\
    \ f, const usize l) noexcept\n        : f(l - 1),\n          l(std::min(f, l)\
    \ - 1) {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n\
    \    constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n}\
    \ // namespace luz\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace luz {\n\n  template < typename T\
    \ >\n  std::ostream &operator<<(std::ostream &os,\n                          \
    \ const std::vector< T > vs) {\n    for (usize i: rep(0, vs.size())) {\n     \
    \ os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n    }\n    return os;\n\
    \  }\n\n  template < typename T >\n  std::istream &operator>>(std::istream &is,\
    \ std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n    return\
    \ is;\n  }\n\n} // namespace luz\n#line 3 \"src/sequence/coordinate-compression.hpp\"\
    \n\n#line 6 \"src/sequence/coordinate-compression.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename T >\n  std::vector< usize > coordinate_compression(std::vector<\
    \ T > vs) {\n    std::vector< usize > res(vs.size());\n\n    std::vector< T >\
    \ zip = vs;\n    std::sort(zip.begin(), zip.end());\n    zip.erase(std::unique(zip.begin(),\
    \ zip.end()), zip.end());\n\n    for (usize i: rep(0, vs.size())) {\n      res[i]\
    \ = std::lower_bound(zip.begin(), zip.end(), vs[i]) -\n          zip.begin();\n\
    \    }\n\n    return res;\n  }\n\n} // namespace luz\n#line 6 \"unit-test/sequence/coordinate-complession.test.cpp\"\
    \n\n#include <cassert>\n#include <ostream>\n#line 10 \"unit-test/sequence/coordinate-complession.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    std::vector< int > vs({8, -5, 3,\
    \ 4, 3, 7, 1});\n    std::vector< usize > expected({5, 0, 2, 3, 2, 4, 1});\n\n\
    \    assert(coordinate_compression(vs) == expected);\n\n    std::vector< usize\
    \ > result = coordinate_compression(vs);\n\n    std::cerr << \"result  : \" <<\
    \ result << std::endl;\n    std::cerr << \"expected: \" << expected << std::endl;\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/vector-ios.hpp\"\
    \n#include \"src/sequence/coordinate-compression.hpp\"\n\n#include <cassert>\n\
    #include <ostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_() {\n\
    \    std::vector< int > vs({8, -5, 3, 4, 3, 7, 1});\n    std::vector< usize >\
    \ expected({5, 0, 2, 3, 2, 4, 1});\n\n    assert(coordinate_compression(vs) ==\
    \ expected);\n\n    std::vector< usize > result = coordinate_compression(vs);\n\
    \n    std::cerr << \"result  : \" << result << std::endl;\n    std::cerr << \"\
    expected: \" << expected << std::endl;\n\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/cpp-template/header/rep.hpp
  - src/sequence/coordinate-compression.hpp
  isVerificationFile: true
  path: unit-test/sequence/coordinate-complession.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/sequence/coordinate-complession.test.cpp
layout: document
redirect_from:
- /verify/unit-test/sequence/coordinate-complession.test.cpp
- /verify/unit-test/sequence/coordinate-complession.test.cpp.html
title: unit-test/sequence/coordinate-complession.test.cpp
---
