---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':question:'
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':question:'
    path: src/sequence/compression.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/sequence/compression.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/sequence/compression.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\
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
    \ 5 \"src/sequence/compression.hpp\"\n\n#line 7 \"src/sequence/compression.hpp\"\
    \n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  template < class T, class Compare = std::less< T > >\n  class Compressor\
    \ {\n    std::vector< T > vs;\n    std::vector< T > zip;\n    std::vector< usize\
    \ > ziped_vs;\n\n   public:\n    explicit Compressor(std::vector< T > vs)\n  \
    \      : vs(vs),\n          zip(vs),\n          ziped_vs(vs.size()) {\n      std::sort(zip.begin(),\
    \ zip.end(), Compare());\n      zip.erase(std::unique(zip.begin(), zip.end()),\
    \ zip.end());\n      for (usize i: rep(0, vs.size())) {\n        ziped_vs[i] =\
    \ compress(vs[i]);\n      }\n    }\n\n    std::vector< usize > compressed_vector()\
    \ const {\n      return ziped_vs;\n    }\n\n    usize compress(T v) const {\n\
    \      auto iter = std::lower_bound(zip.begin(), zip.end(), v);\n      assert(*iter\
    \ == v);\n      return iter - zip.begin();\n    }\n\n    T expand(usize i) const\
    \ {\n      assert(i < zip.size());\n      return zip[i];\n    }\n  };\n\n} //\
    \ namespace luz\n#line 4 \"unit-test/sequence/compression.test.cpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\nnamespace\
    \ luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n  using\
    \ i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\n\n#include <iostream>\n\
    #line 7 \"src/cpp-template/header/vector-ios.hpp\"\n\nnamespace luz {\n\n  template\
    \ < typename T >\n  std::ostream &operator<<(std::ostream &os,\n             \
    \              const std::vector< T > vs) {\n    for (usize i: rep(0, vs.size()))\
    \ {\n      os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n    }\n    return\
    \ os;\n  }\n\n  template < typename T >\n  std::istream &operator>>(std::istream\
    \ &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n\
    \    return is;\n  }\n\n} // namespace luz\n#line 8 \"unit-test/sequence/compression.test.cpp\"\
    \n\n#line 10 \"unit-test/sequence/compression.test.cpp\"\n#include <ostream>\n\
    #line 12 \"unit-test/sequence/compression.test.cpp\"\n\nnamespace luz {\n\n  void\
    \ main_() {\n    std::vector< i32 > vs({8, -5, 3, 4, 3, 7, 1});\n    std::vector<\
    \ usize > expected({5, 0, 2, 3, 2, 4, 1});\n\n    Compressor< i32 > cp(vs);\n\
    \    std::vector< usize > result = cp.compressed_vector();\n    assert(result\
    \ == expected);\n\n    std::cerr << \"result  : \" << result << std::endl;\n \
    \   std::cerr << \"expected: \" << expected << std::endl;\n\n    std::cout <<\
    \ \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n \
    \ luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/sequence/compression.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#include <cassert>\n#include <ostream>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  void main_() {\n    std::vector< i32 > vs({8, -5, 3, 4, 3, 7, 1});\n\
    \    std::vector< usize > expected({5, 0, 2, 3, 2, 4, 1});\n\n    Compressor<\
    \ i32 > cp(vs);\n    std::vector< usize > result = cp.compressed_vector();\n \
    \   assert(result == expected);\n\n    std::cerr << \"result  : \" << result <<\
    \ std::endl;\n    std::cerr << \"expected: \" << expected << std::endl;\n\n  \
    \  std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint\
    \ main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/sequence/compression.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  isVerificationFile: true
  path: unit-test/sequence/compression.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: unit-test/sequence/compression.test.cpp
layout: document
redirect_from:
- /verify/unit-test/sequence/compression.test.cpp
- /verify/unit-test/sequence/compression.test.cpp.html
title: unit-test/sequence/compression.test.cpp
---
