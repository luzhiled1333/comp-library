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
    path: src/sequence/compression.hpp
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
  bundledCode: "#line 1 \"unit-test/sequence/compression.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/sequence/compression.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 5 \"src/sequence/compression.hpp\"\
    \n\n#line 7 \"src/sequence/compression.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < class T, class Compare =\
    \ std::less< T > >\n  class Compressor {\n    std::vector< T > vs_;\n    std::vector<\
    \ T > zip_;\n    std::vector< usize > ziped_vs_;\n\n   public:\n    explicit Compressor(std::vector<\
    \ T > vs)\n        : vs_(vs),\n          zip_(vs),\n          ziped_vs_(vs.size())\
    \ {\n      std::sort(zip_.begin(), zip_.end(), Compare());\n      zip_.erase(std::unique(zip_.begin(),\
    \ zip_.end()), zip_.end());\n      for (usize i: rep(0, vs.size())) {\n      \
    \  ziped_vs_[i] = compress(vs[i]);\n      }\n    }\n\n    std::vector< usize >\
    \ compressed_vector() const {\n      return ziped_vs_;\n    }\n\n    usize compress(T\
    \ v) const {\n      auto iter = std::lower_bound(zip_.begin(), zip_.end(), v);\n\
    \      assert(*iter == v);\n      return iter - zip_.begin();\n    }\n\n    T\
    \ expand(usize i) const {\n      assert(i < zip_.size());\n      return zip_[i];\n\
    \    }\n  };\n\n} // namespace luz\n#line 4 \"unit-test/sequence/compression.test.cpp\"\
    \n\n#line 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#include <iostream>\n#line 7 \"src/cpp-template/header/vector-ios.hpp\"\n\n\
    namespace luz {\n\n  template < typename T >\n  std::ostream &operator<<(std::ostream\
    \ &os,\n                           const std::vector< T > vs) {\n    for (usize\
    \ i: rep(0, vs.size())) {\n      os << vs[i] << (i + 1 != vs.size() ? \" \" :\
    \ \"\");\n    }\n    return os;\n  }\n\n  template < typename T >\n  std::istream\
    \ &operator>>(std::istream &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n\
    \      is >> v;\n    }\n    return is;\n  }\n\n} // namespace luz\n#line 7 \"\
    unit-test/sequence/compression.test.cpp\"\n\n#line 9 \"unit-test/sequence/compression.test.cpp\"\
    \n#include <ostream>\n#line 11 \"unit-test/sequence/compression.test.cpp\"\n\n\
    namespace luz {\n\n  void main_() {\n    std::vector< int > vs({8, -5, 3, 4, 3,\
    \ 7, 1});\n    std::vector< usize > expected({5, 0, 2, 3, 2, 4, 1});\n\n    Compressor<\
    \ int > cp(vs);\n    std::vector< usize > result = cp.compressed_vector();\n \
    \   assert(result == expected);\n\n    std::cerr << \"result  : \" << result <<\
    \ std::endl;\n    std::cerr << \"expected: \" << expected << std::endl;\n\n  \
    \  std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint\
    \ main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/sequence/compression.hpp\"\n\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/cpp-template/header/vector-ios.hpp\"\n\n#include <cassert>\n\
    #include <ostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_() {\n\
    \    std::vector< int > vs({8, -5, 3, 4, 3, 7, 1});\n    std::vector< usize >\
    \ expected({5, 0, 2, 3, 2, 4, 1});\n\n    Compressor< int > cp(vs);\n    std::vector<\
    \ usize > result = cp.compressed_vector();\n    assert(result == expected);\n\n\
    \    std::cerr << \"result  : \" << result << std::endl;\n    std::cerr << \"\
    expected: \" << expected << std::endl;\n\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/sequence/compression.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  isVerificationFile: true
  path: unit-test/sequence/compression.test.cpp
  requiredBy: []
  timestamp: '2022-08-24 11:33:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/sequence/compression.test.cpp
layout: document
redirect_from:
- /verify/unit-test/sequence/compression.test.cpp
- /verify/unit-test/sequence/compression.test.cpp.html
title: unit-test/sequence/compression.test.cpp
---
