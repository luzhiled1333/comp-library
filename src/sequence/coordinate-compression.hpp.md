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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
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
    \ return l;\n    }\n  };\n\n} // namespace luz\n#line 3 \"src/sequence/coordinate-compression.hpp\"\
    \n\n#line 5 \"src/sequence/coordinate-compression.hpp\"\n#include <vector>\n\n\
    namespace luz {\n\n  template < typename T >\n  std::vector< usize > coordinate_compression(std::vector<\
    \ T > vs) {\n    std::vector< usize > res(vs.size());\n\n    std::vector< T >\
    \ zip = vs;\n    std::sort(zip.begin(), zip.end());\n    zip.erase(std::unique(zip.begin(),\
    \ zip.end()), zip.end());\n\n    for (usize i: rep(0, vs.size())) {\n      res[i]\
    \ = std::lower_bound(zip.begin(), zip.end(), vs[i]) -\n          zip.begin();\n\
    \    }\n\n    return res;\n  }\n\n} // namespace luz\n"
  code: "#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <algorithm>\n#include <vector>\n\nnamespace luz {\n\n  template <\
    \ typename T >\n  std::vector< usize > coordinate_compression(std::vector< T >\
    \ vs) {\n    std::vector< usize > res(vs.size());\n\n    std::vector< T > zip\
    \ = vs;\n    std::sort(zip.begin(), zip.end());\n    zip.erase(std::unique(zip.begin(),\
    \ zip.end()), zip.end());\n\n    for (usize i: rep(0, vs.size())) {\n      res[i]\
    \ = std::lower_bound(zip.begin(), zip.end(), vs[i]) -\n          zip.begin();\n\
    \    }\n\n    return res;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/sequence/coordinate-compression.hpp
  requiredBy: []
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/sequence/coordinate-compression.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

## coordinate_compression
```
std::vector< usize > coordinate_compression(std::vector<T> vs)
```

`std::vector<T>` を 0-indexed で座標圧縮して返す。

### 計算量
- `T` の比較を $O(1)$、`vs` のサイズを $n$ として $O(n \log n)$