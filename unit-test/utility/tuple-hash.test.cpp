// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/utility/tuple-hash.hpp"

#include "src/cpp-template/header/rep.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace luz {

  void main_() {
    {
      i64 large_number = 998244353ll * 512;

      std::tuple< i32, char, i64 > a(5, 'b', large_number),
          b(6, 'b', large_number), c(5, 'c', large_number),
          d(5, 'b', large_number + 1);
      std::vector< usize > hs({TupleHash()(a), TupleHash()(b),
                               TupleHash()(c), TupleHash()(d)});
      std::sort(hs.begin(), hs.end());
      hs.erase(std::unique(hs.begin(), hs.end()), hs.end());
      assert(hs.size() == (usize)4);
    }

    {
      using Tuple = std::tuple< i32, i32, i32 >;
      std::vector< Tuple > ts({{1, 2, 3},
                               {1, 3, 2},
                               {2, 1, 3},
                               {2, 3, 1},
                               {3, 1, 2},
                               {3, 2, 1}});
      std::vector< usize > hs(6);
      for (usize i: rep(0, 6)) {
        hs[i] = TupleHash()(ts[i]);
      }
      std::sort(hs.begin(), hs.end());
      hs.erase(std::unique(hs.begin(), hs.end()), hs.end());
      assert(hs.size() == (usize)6);
    }

    using PrimitiveTuple =
        std::tuple< bool, char, short, int, long, long long >;
    std::unordered_map< PrimitiveTuple, usize, TupleHash > ump;
    std::unordered_multimap< PrimitiveTuple, usize, TupleHash > ummp;
    std::unordered_set< PrimitiveTuple, TupleHash > ust;
    std::unordered_multiset< PrimitiveTuple, TupleHash > umst;

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
