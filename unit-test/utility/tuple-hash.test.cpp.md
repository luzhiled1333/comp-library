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
  - icon: ':x:'
    path: src/utility/tuple-hash.hpp
    title: "std::tuple \u306E Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/utility/tuple-hash.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/utility/tuple-hash.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 4 \"src/utility/tuple-hash.hpp\"\n\n#include <functional>\n\
    #include <tuple>\n#include <utility>\n\nnamespace luz::impl_tuple_hash {\n\n \
    \ template < usize Index >\n  class ImplTupleHash {\n   public:\n    template\
    \ < typename T >\n    usize hash_combine(const T &x, usize hr) const {\n     \
    \ usize h = std::hash< T >()(x);\n      return hr ^ (h + (hr << 11) + (hr >> 13));\n\
    \    }\n\n    template < class Tuple >\n    usize operator()(const Tuple &t) const\
    \ noexcept {\n      usize hr = ImplTupleHash< Index - 1 >()(t);\n      return\
    \ hash_combine(std::get< Index - 1 >(t), hr);\n    }\n  };\n\n  template <>\n\
    \  class ImplTupleHash< 0 > {\n   public:\n    template < class Tuple >\n    usize\
    \ operator()([[maybe_unused]] const Tuple &_) const noexcept {\n      return 0;\n\
    \    }\n  };\n\n} // namespace luz::impl_tuple_hash\n\nnamespace luz {\n\n  class\
    \ TupleHash {\n    template < usize Index >\n    using ImplTupleHash = impl_tuple_hash::ImplTupleHash<\
    \ Index >;\n\n   public:\n    template < class... Args >\n    usize operator()(const\
    \ std::tuple< Args... > &t) const {\n      using Tuple = std::tuple< Args... >;\n\
    \      return ImplTupleHash< std::tuple_size< Tuple >::value >()(t);\n    }\n\
    \  };\n\n} // namespace luz\n#line 4 \"unit-test/utility/tuple-hash.test.cpp\"\
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
    \ // namespace luz\n#line 8 \"unit-test/utility/tuple-hash.test.cpp\"\n\n#line\
    \ 10 \"unit-test/utility/tuple-hash.test.cpp\"\n#include <cassert>\n#include <iostream>\n\
    #line 13 \"unit-test/utility/tuple-hash.test.cpp\"\n#include <unordered_map>\n\
    #include <unordered_set>\n#line 16 \"unit-test/utility/tuple-hash.test.cpp\"\n\
    #include <vector>\n\nnamespace luz {\n\n  void main_() {\n    {\n      i64 large_number\
    \ = 998244353ll * 512;\n\n      std::tuple< i32, char, i64 > a(5, 'b', large_number),\n\
    \          b(6, 'b', large_number), c(5, 'c', large_number),\n          d(5, 'b',\
    \ large_number + 1);\n      std::vector< usize > hs({TupleHash()(a), TupleHash()(b),\n\
    \                               TupleHash()(c), TupleHash()(d)});\n      std::sort(hs.begin(),\
    \ hs.end());\n      hs.erase(std::unique(hs.begin(), hs.end()), hs.end());\n \
    \     assert(hs.size() == (usize)4);\n    }\n\n    {\n      using Tuple = std::tuple<\
    \ i32, i32, i32 >;\n      std::vector< Tuple > ts({{1, 2, 3},\n              \
    \                 {1, 3, 2},\n                               {2, 1, 3},\n    \
    \                           {2, 3, 1},\n                               {3, 1,\
    \ 2},\n                               {3, 2, 1}});\n      std::vector< usize >\
    \ hs(6);\n      for (usize i: rep(0, 6)) {\n        hs[i] = TupleHash()(ts[i]);\n\
    \      }\n      std::sort(hs.begin(), hs.end());\n      hs.erase(std::unique(hs.begin(),\
    \ hs.end()), hs.end());\n      assert(hs.size() == (usize)6);\n    }\n\n    using\
    \ PrimitiveTuple =\n        std::tuple< bool, char, short, int, long, long long\
    \ >;\n    std::unordered_map< PrimitiveTuple, usize, TupleHash > ump;\n    std::unordered_multimap<\
    \ PrimitiveTuple, usize, TupleHash > ummp;\n    std::unordered_set< PrimitiveTuple,\
    \ TupleHash > ust;\n    std::unordered_multiset< PrimitiveTuple, TupleHash > umst;\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/utility/tuple-hash.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <tuple>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  void main_() {\n    {\n      i64 large_number\
    \ = 998244353ll * 512;\n\n      std::tuple< i32, char, i64 > a(5, 'b', large_number),\n\
    \          b(6, 'b', large_number), c(5, 'c', large_number),\n          d(5, 'b',\
    \ large_number + 1);\n      std::vector< usize > hs({TupleHash()(a), TupleHash()(b),\n\
    \                               TupleHash()(c), TupleHash()(d)});\n      std::sort(hs.begin(),\
    \ hs.end());\n      hs.erase(std::unique(hs.begin(), hs.end()), hs.end());\n \
    \     assert(hs.size() == (usize)4);\n    }\n\n    {\n      using Tuple = std::tuple<\
    \ i32, i32, i32 >;\n      std::vector< Tuple > ts({{1, 2, 3},\n              \
    \                 {1, 3, 2},\n                               {2, 1, 3},\n    \
    \                           {2, 3, 1},\n                               {3, 1,\
    \ 2},\n                               {3, 2, 1}});\n      std::vector< usize >\
    \ hs(6);\n      for (usize i: rep(0, 6)) {\n        hs[i] = TupleHash()(ts[i]);\n\
    \      }\n      std::sort(hs.begin(), hs.end());\n      hs.erase(std::unique(hs.begin(),\
    \ hs.end()), hs.end());\n      assert(hs.size() == (usize)6);\n    }\n\n    using\
    \ PrimitiveTuple =\n        std::tuple< bool, char, short, int, long, long long\
    \ >;\n    std::unordered_map< PrimitiveTuple, usize, TupleHash > ump;\n    std::unordered_multimap<\
    \ PrimitiveTuple, usize, TupleHash > ummp;\n    std::unordered_set< PrimitiveTuple,\
    \ TupleHash > ust;\n    std::unordered_multiset< PrimitiveTuple, TupleHash > umst;\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/utility/tuple-hash.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: true
  path: unit-test/utility/tuple-hash.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: unit-test/utility/tuple-hash.test.cpp
layout: document
redirect_from:
- /verify/unit-test/utility/tuple-hash.test.cpp
- /verify/unit-test/utility/tuple-hash.test.cpp.html
title: unit-test/utility/tuple-hash.test.cpp
---
