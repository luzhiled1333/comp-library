---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unit-test/sequence/coordinate-complession.test.cpp
    title: unit-test/sequence/coordinate-complession.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/sequence/coordinate-compression.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 6 \"src/cpp-template/header/rep.hpp\"\n\nnamespace luz {\n\n  struct\
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
    \ const noexcept { return l; }\n  };\n\n} // namespace luz\n#line 6 \"src/sequence/coordinate-compression.hpp\"\
    \n\nnamespace luz {\n\n  template< typename T >\n  std::vector< usize > coordinate_compression(std::vector<\
    \ T > vs) {\n    std::vector< usize > res(vs.size());\n\n    std::vector< T >\
    \ zip = vs;\n    std::sort(zip.begin(), zip.end());\n    zip.erase(std::unique(zip.begin(),\
    \ zip.end()), zip.end());\n\n    for (usize i: rep(0, vs.size())) {\n      res[i]\
    \ = std::lower_bound(zip.begin(), zip.end(), vs[i]) - zip.begin();\n    }\n\n\
    \    return res;\n  }\n\n}\n"
  code: "#include <algorithm>\n#include <vector>\n\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n\nnamespace luz {\n\n  template<\
    \ typename T >\n  std::vector< usize > coordinate_compression(std::vector< T >\
    \ vs) {\n    std::vector< usize > res(vs.size());\n\n    std::vector< T > zip\
    \ = vs;\n    std::sort(zip.begin(), zip.end());\n    zip.erase(std::unique(zip.begin(),\
    \ zip.end()), zip.end());\n\n    for (usize i: rep(0, vs.size())) {\n      res[i]\
    \ = std::lower_bound(zip.begin(), zip.end(), vs[i]) - zip.begin();\n    }\n\n\
    \    return res;\n  }\n\n}\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: false
  path: src/sequence/coordinate-compression.hpp
  requiredBy: []
  timestamp: '2022-07-16 05:13:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/sequence/coordinate-complession.test.cpp
documentation_of: src/sequence/coordinate-compression.hpp
layout: document
redirect_from:
- /library/src/sequence/coordinate-compression.hpp
- /library/src/sequence/coordinate-compression.hpp.html
title: src/sequence/coordinate-compression.hpp
---
