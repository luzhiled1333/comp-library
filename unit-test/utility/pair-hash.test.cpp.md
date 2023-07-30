---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/utility/pair-hash.hpp
    title: "std::pair \u306E Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/utility/pair-hash.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/utility/pair-hash.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 4 \"src/utility/pair-hash.hpp\"\n\n#include <functional>\n\
    #include <utility>\n\nnamespace luz {\n\n  class PairHash {\n    template < typename\
    \ T >\n    usize hash_combine(usize hr, const T &x) const {\n      usize h = std::hash<\
    \ T >()(x);\n      return hr ^ (h + (hr << 11) + (hr >> 13));\n    }\n\n   public:\n\
    \    template < typename F, typename S >\n    usize operator()(const std::pair<\
    \ F, S > &p) const {\n      return hash_combine(hash_combine(0, p.first), p.second);\n\
    \    }\n  };\n\n} // namespace luz\n#line 4 \"unit-test/utility/pair-hash.test.cpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
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
    \ // namespace luz\n#line 8 \"unit-test/utility/pair-hash.test.cpp\"\n\n#line\
    \ 10 \"unit-test/utility/pair-hash.test.cpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <set>\n#include <unordered_map>\n#include <unordered_set>\n#line 16 \"\
    unit-test/utility/pair-hash.test.cpp\"\n#include <vector>\n\nnamespace luz {\n\
    \n  void main_() {\n    {\n      using Pair       = std::pair< i32, i64 >;\n \
    \     i64 large_number = 998244353ll * 512;\n\n      std::vector< Pair > ps({{998244353,\
    \ large_number},\n                              {998244352, large_number},\n \
    \                             {998244353, large_number + 1}});\n      std::set<\
    \ usize > hs;\n      for (Pair &p: ps) {\n        hs.emplace(PairHash()(p));\n\
    \      }\n\n      assert(hs.size() == ps.size());\n    }\n\n    {\n      using\
    \ Pair = std::pair< i32, i32 >;\n      assert(PairHash()(Pair(1, 2)) != PairHash()(Pair(2,\
    \ 1)));\n    }\n\n    using PrimitivePair = std::pair< bool, long long >;\n  \
    \  std::unordered_map< PrimitivePair, usize, PairHash > ump;\n    std::unordered_multimap<\
    \ PrimitivePair, usize, PairHash > ummp;\n    std::unordered_set< PrimitivePair,\
    \ PairHash > ust;\n    std::unordered_multiset< PrimitivePair, PairHash > umst;\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/utility/pair-hash.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <set>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  void main_() {\n    {\n      using Pair   \
    \    = std::pair< i32, i64 >;\n      i64 large_number = 998244353ll * 512;\n\n\
    \      std::vector< Pair > ps({{998244353, large_number},\n                  \
    \            {998244352, large_number},\n                              {998244353,\
    \ large_number + 1}});\n      std::set< usize > hs;\n      for (Pair &p: ps) {\n\
    \        hs.emplace(PairHash()(p));\n      }\n\n      assert(hs.size() == ps.size());\n\
    \    }\n\n    {\n      using Pair = std::pair< i32, i32 >;\n      assert(PairHash()(Pair(1,\
    \ 2)) != PairHash()(Pair(2, 1)));\n    }\n\n    using PrimitivePair = std::pair<\
    \ bool, long long >;\n    std::unordered_map< PrimitivePair, usize, PairHash >\
    \ ump;\n    std::unordered_multimap< PrimitivePair, usize, PairHash > ummp;\n\
    \    std::unordered_set< PrimitivePair, PairHash > ust;\n    std::unordered_multiset<\
    \ PrimitivePair, PairHash > umst;\n\n    std::cout << \"Hello World\" << std::endl;\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/utility/pair-hash.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: true
  path: unit-test/utility/pair-hash.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/utility/pair-hash.test.cpp
layout: document
redirect_from:
- /verify/unit-test/utility/pair-hash.test.cpp
- /verify/unit-test/utility/pair-hash.test.cpp.html
title: unit-test/utility/pair-hash.test.cpp
---
