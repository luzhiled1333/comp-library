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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1_14_b/fast-rolling-hash.test.cpp
    title: test/aoj/alds1_14_b/fast-rolling-hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
    title: test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/sequence/fast-rolling-hash.hpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 6 \"src/sequence/fast-rolling-hash.hpp\"\n\n#line 8 \"src/sequence/fast-rolling-hash.hpp\"\
    \n#include <cassert>\n#include <chrono>\n#include <random>\n#include <vector>\n\
    \nnamespace luz {\n\n  class FastRollingHash {\n    static constexpr u64 mod =\
    \ (1ull << 61ull) - 1;\n\n    const u64 base;\n    std::vector< u64 > power;\n\
    \n    static u64 add(u64 a, u64 b) {\n      if ((a += b) >= mod) a -= mod;\n \
    \     return a;\n    }\n\n    static u64 mul(u64 a, u64 b) {\n      u128 c = u128(a)\
    \ * b;\n      return add(c >> 61, c & mod);\n    }\n\n    void expand(usize sz)\
    \ {\n      usize l = power.size(), r = sz + 1;\n      if (r <= l) return;\n\n\
    \      power.resize(r);\n      for (usize i: rep(l, r)) {\n        power[i] =\
    \ mul(power[i - 1], base);\n      }\n    }\n\n   public:\n    using Hs = std::vector<\
    \ u64 >;\n\n    FastRollingHash(): base(generate_base()), power{1} {}\n\n    explicit\
    \ FastRollingHash(u64 base): base(base), power{1} {}\n\n    template < class Iter\
    \ >\n    Hs build(Iter first, Iter last) const {\n      Hs hs(1);\n      hs.reserve(last\
    \ - first + 1);\n      while (first != last) {\n        u64 h = add(mul(hs.back(),\
    \ base), *first);\n        hs.emplace_back(h);\n        ++first;\n      }\n  \
    \    return hs;\n    }\n\n    u64 query(const Hs &s, usize l, usize r) {\n   \
    \   assert(l <= r and r < s.size());\n\n      expand(r - l);\n      return add(s[r],\
    \ mod - mul(s[l], power[r - l]));\n    }\n\n    u64 combine(u64 h1, u64 h2, usize\
    \ h2len) {\n      expand(h2len);\n      return add(mul(h1, power[h2len]), h2);\n\
    \    }\n\n    usize lcp(const Hs &a, usize l1, usize r1, const Hs &b, usize l2,\n\
    \              usize r2) {\n      assert(l1 <= r1 and r1 < a.size());\n      assert(l2\
    \ <= r2 and r2 < b.size());\n\n      usize len = std::min(r1 - l1, r2 - l2);\n\
    \      usize low = 0, high = len + 1;\n\n      while (high - low > 1) {\n    \
    \    usize mid = (low + high) / 2;\n        if (query(a, l1, l1 + mid) == query(b,\
    \ l2, l2 + mid)) {\n          low = mid;\n        } else {\n          high = mid;\n\
    \        }\n      }\n      return low;\n    }\n\n   private:\n    static u64 mod_pow(u64\
    \ b, u64 e) {\n      u64 res{1};\n\n      while (e) {\n        if (e & 1) {\n\
    \          res = mul(res, b);\n        }\n        b = mul(b, b);\n        e >>=\
    \ 1;\n      }\n\n      return res;\n    }\n\n    static bool is_primitive_root(u64\
    \ b) {\n      constexpr u64 ps[] = {2,  3,  5,  7,   11,  13,\n              \
    \              31, 41, 61, 151, 331, 1321};\n      for (const auto &p: ps) {\n\
    \        if (mod_pow(b, (mod - 1) / p) == 1) {\n          return false;\n    \
    \    }\n      }\n      return true;\n    }\n\n    static u64 generate_base() {\n\
    \      std::mt19937_64 mt(std::chrono::steady_clock::now()\n                 \
    \            .time_since_epoch()\n                             .count());\n  \
    \    std::uniform_int_distribution< u64 > rand(1e9, mod - 1);\n      while (true)\
    \ {\n        u64 b = rand(mt);\n        if (not is_primitive_root(b)) {\n    \
    \      continue;\n        }\n\n        return b;\n      }\n    }\n  };\n\n} //\
    \ namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <chrono>\n#include <random>\n\
    #include <vector>\n\nnamespace luz {\n\n  class FastRollingHash {\n    static\
    \ constexpr u64 mod = (1ull << 61ull) - 1;\n\n    const u64 base;\n    std::vector<\
    \ u64 > power;\n\n    static u64 add(u64 a, u64 b) {\n      if ((a += b) >= mod)\
    \ a -= mod;\n      return a;\n    }\n\n    static u64 mul(u64 a, u64 b) {\n  \
    \    u128 c = u128(a) * b;\n      return add(c >> 61, c & mod);\n    }\n\n   \
    \ void expand(usize sz) {\n      usize l = power.size(), r = sz + 1;\n      if\
    \ (r <= l) return;\n\n      power.resize(r);\n      for (usize i: rep(l, r)) {\n\
    \        power[i] = mul(power[i - 1], base);\n      }\n    }\n\n   public:\n \
    \   using Hs = std::vector< u64 >;\n\n    FastRollingHash(): base(generate_base()),\
    \ power{1} {}\n\n    explicit FastRollingHash(u64 base): base(base), power{1}\
    \ {}\n\n    template < class Iter >\n    Hs build(Iter first, Iter last) const\
    \ {\n      Hs hs(1);\n      hs.reserve(last - first + 1);\n      while (first\
    \ != last) {\n        u64 h = add(mul(hs.back(), base), *first);\n        hs.emplace_back(h);\n\
    \        ++first;\n      }\n      return hs;\n    }\n\n    u64 query(const Hs\
    \ &s, usize l, usize r) {\n      assert(l <= r and r < s.size());\n\n      expand(r\
    \ - l);\n      return add(s[r], mod - mul(s[l], power[r - l]));\n    }\n\n   \
    \ u64 combine(u64 h1, u64 h2, usize h2len) {\n      expand(h2len);\n      return\
    \ add(mul(h1, power[h2len]), h2);\n    }\n\n    usize lcp(const Hs &a, usize l1,\
    \ usize r1, const Hs &b, usize l2,\n              usize r2) {\n      assert(l1\
    \ <= r1 and r1 < a.size());\n      assert(l2 <= r2 and r2 < b.size());\n\n   \
    \   usize len = std::min(r1 - l1, r2 - l2);\n      usize low = 0, high = len +\
    \ 1;\n\n      while (high - low > 1) {\n        usize mid = (low + high) / 2;\n\
    \        if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) {\n          low\
    \ = mid;\n        } else {\n          high = mid;\n        }\n      }\n      return\
    \ low;\n    }\n\n   private:\n    static u64 mod_pow(u64 b, u64 e) {\n      u64\
    \ res{1};\n\n      while (e) {\n        if (e & 1) {\n          res = mul(res,\
    \ b);\n        }\n        b = mul(b, b);\n        e >>= 1;\n      }\n\n      return\
    \ res;\n    }\n\n    static bool is_primitive_root(u64 b) {\n      constexpr u64\
    \ ps[] = {2,  3,  5,  7,   11,  13,\n                            31, 41, 61, 151,\
    \ 331, 1321};\n      for (const auto &p: ps) {\n        if (mod_pow(b, (mod -\
    \ 1) / p) == 1) {\n          return false;\n        }\n      }\n      return true;\n\
    \    }\n\n    static u64 generate_base() {\n      std::mt19937_64 mt(std::chrono::steady_clock::now()\n\
    \                             .time_since_epoch()\n                          \
    \   .count());\n      std::uniform_int_distribution< u64 > rand(1e9, mod - 1);\n\
    \      while (true) {\n        u64 b = rand(mt);\n        if (not is_primitive_root(b))\
    \ {\n          continue;\n        }\n\n        return b;\n      }\n    }\n  };\n\
    \n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/sequence/fast-rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-08-12 04:06:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
  - test/aoj/alds1_14_b/fast-rolling-hash.test.cpp
documentation_of: src/sequence/fast-rolling-hash.hpp
layout: document
title: "\u9AD8\u901F\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5 (Fast\
  \ Rolling Hash with $\\mod 2^{61} - 1$)"
---

## FastRollingHash
ハッシュの列を扱ういくつかの関数を提供するクラス。

あらかじめ実体化しておき、列の生成や操作はその実体を通して行う必要がある。

```
(1) FastRollingHash froll;
(2) FastRollingHash froll(u64 b);
```

- (1) `froll` として実体化する。base は実行時にランダムな原始根がとられる。
- (2) base を `b` と指定し、 `froll` として実体化する。

以下、実体の変数名を `froll` であるとする。

## Hs
```
using Hs = std::vector< u64 >;
```

ハッシュの列の型。 `std::vector< u64 >` のエイリアスとなっている。

## build
```
template< class Iter >
Hs froll.build(Iter first, Iter last)
```

Iterator `first` と `last` を渡すことで、 $[first, last)$ のハッシュ列を生成する。

### 計算量
- 要素数を $n$ として $O(n)$

## query
```
u64 froll.query(const Hs &s, usize l, usize r)
```

ハッシュ列とその区間 $[l, r)$ を指定し、与えられた区間の hash を計算して返す。

### 計算量
- $O(1)$

## combine
```
u64 froll.combine(u64 h1, u64 h2, usize h2len)
```

2 つのハッシュ $h1, h2$ と $h2$ の長さ `h2len` を渡すことで、もとの 2 つの列を連結した列のハッシュを返す。

### 計算量
- $O(1)$

## lcp
```
usize froll.lcp(const Hs &a, usize l1, usize r1,
                const Hs &b, usize l2, usize r2)
```

列 $A$ のハッシュ列 `a` とその区間 $[l1, r1)$、列 $B$ のハッシュ列 `b` とその区間 $[l2, r2)$ を渡すことで、列 $A$ の区間 $[l1, r1)$ と列 $B$ の区間 $[l2, r2)$ の最長共通接頭辞 (Longest Common Prefix) の長さを返す。

### 計算量
- 2 つの区間の長さの最小値を $n$ として $O(\log n)$
