---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unit-test/sequence/compression.test.cpp
    title: unit-test/sequence/compression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/sequence/compression.hpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/type-alias.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace luz {\n\n  template < class\
    \ T, class Compare = std::less< T > >\n  class Compressor {\n    std::vector<\
    \ T > vs_;\n    std::vector< T > zip_;\n    std::vector< usize > ziped_vs_;\n\n\
    \   public:\n    explicit Compressor(std::vector< T > vs)\n        : vs_(vs),\n\
    \          zip_(vs),\n          ziped_vs_(vs.size()) {\n      std::sort(zip_.begin(),\
    \ zip_.end(), Compare());\n      zip_.erase(std::unique(zip_.begin(), zip_.end()),\
    \ zip_.end());\n      for (usize i: rep(0, vs.size())) {\n        ziped_vs_[i]\
    \ = compress(vs[i]);\n      }\n    }\n\n    std::vector< usize > compressed_vector()\
    \ const {\n      return ziped_vs_;\n    }\n\n    usize compress(T v) const {\n\
    \      auto iter = std::lower_bound(zip_.begin(), zip_.end(), v);\n      assert(*iter\
    \ == v);\n      return iter - zip_.begin();\n    }\n\n    T expand(usize i) const\
    \ {\n      assert(i < zip_.size());\n      return zip_[i];\n    }\n  };\n\n} //\
    \ namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/sequence/compression.hpp
  requiredBy: []
  timestamp: '2022-08-24 11:33:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/sequence/compression.test.cpp
documentation_of: src/sequence/compression.hpp
layout: document
redirect_from:
- /library/src/sequence/compression.hpp
- /library/src/sequence/compression.hpp.html
title: src/sequence/compression.hpp
---
