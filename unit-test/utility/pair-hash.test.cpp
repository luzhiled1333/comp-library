// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/utility/pair-hash.hpp"

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace luz {

  void main_() {
    {
      using Pair       = std::pair< i32, i64 >;
      i64 large_number = 998244353ll * 512;

      std::vector< Pair > ps({{998244353, large_number},
                              {998244352, large_number},
                              {998244353, large_number + 1}});
      std::set< usize > hs;
      for (Pair &p: ps) {
        hs.emplace(PairHash()(p));
      }

      assert(hs.size() == ps.size());
    }

    {
      using Pair = std::pair< i32, i32 >;
      assert(PairHash()(Pair(1, 2)) != PairHash()(Pair(2, 1)));
    }

    using PrimitivePair = std::pair< bool, long long >;
    std::unordered_map< PrimitivePair, usize, PairHash > ump;
    std::unordered_multimap< PrimitivePair, usize, PairHash > ummp;
    std::unordered_set< PrimitivePair, PairHash > ust;
    std::unordered_multiset< PrimitivePair, PairHash > umst;

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
