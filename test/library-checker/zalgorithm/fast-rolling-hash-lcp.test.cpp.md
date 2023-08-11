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
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':heavy_check_mark:'
    path: src/sequence/fast-rolling-hash.hpp
    title: "\u9AD8\u901F\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\
      \ (Fast Rolling Hash with $\\mod 2^{61} - 1$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp\"\
    \n// verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm\n\
    \n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 2 \"src/cpp-template/header/vector-ios.hpp\"\n\n#line 4 \"src/cpp-template/header/vector-ios.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nnamespace luz {\n\n  template <\
    \ typename T >\n  std::ostream &operator<<(std::ostream &os,\n               \
    \            const std::vector< T > vs) {\n    for (usize i: rep(0, vs.size()))\
    \ {\n      os << vs[i] << (i + 1 != vs.size() ? \" \" : \"\");\n    }\n    return\
    \ os;\n  }\n\n  template < typename T >\n  std::istream &operator>>(std::istream\
    \ &is, std::vector< T > &vs) {\n    for (T &v: vs) {\n      is >> v;\n    }\n\
    \    return is;\n  }\n\n} // namespace luz\n#line 2 \"src/sequence/fast-rolling-hash.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 6 \"src/sequence/fast-rolling-hash.hpp\"\
    \n\n#line 8 \"src/sequence/fast-rolling-hash.hpp\"\n#include <cassert>\n#include\
    \ <chrono>\n#include <random>\n#line 12 \"src/sequence/fast-rolling-hash.hpp\"\
    \n\nnamespace luz {\n\n  class FastRollingHash {\n    static constexpr u64 mod\
    \ = (1ull << 61ull) - 1;\n\n    const u64 base;\n    std::vector< u64 > power;\n\
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
    \ namespace luz\n#line 7 \"test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp\"\
    \n\n#line 9 \"test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp\"\
    \n#include <string>\n#line 11 \"test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    std::string s;\n    std::cin >> s;\n\
    \n    const usize n = s.size();\n\n    FastRollingHash froll;\n    const auto\
    \ hs = froll.build(s.begin(), s.end());\n\n    std::vector< usize > ans;\n   \
    \ for (usize i: rep(0, n)) {\n      ans.emplace_back(froll.lcp(hs, 0, n, hs, i,\
    \ n));\n    }\n\n    std::cout << ans << std::endl;\n  }\n\n} // namespace luz\n\
    \nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm\n\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/cpp-template/header/vector-ios.hpp\"\n#include \"src/sequence/fast-rolling-hash.hpp\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  void main_() {\n    std::string s;\n    std::cin >> s;\n\n    const usize\
    \ n = s.size();\n\n    FastRollingHash froll;\n    const auto hs = froll.build(s.begin(),\
    \ s.end());\n\n    std::vector< usize > ans;\n    for (usize i: rep(0, n)) {\n\
    \      ans.emplace_back(froll.lcp(hs, 0, n, hs, i, n));\n    }\n\n    std::cout\
    \ << ans << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/sequence/fast-rolling-hash.hpp
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: true
  path: test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
  requiredBy: []
  timestamp: '2023-08-12 04:06:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
- /verify/test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp.html
title: test/library-checker/zalgorithm/fast-rolling-hash-lcp.test.cpp
---
