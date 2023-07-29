// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/utility/bit/count-leading-0s.hpp"

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  usize naive_countl_zero(u64 x) {
    for (usize k: rrep(0, 64)) {
      if (x & (u64(1) << k)) {
        return 63 - k;
      }
    }

    return 64;
  }

  void main_() {
    for (u64 x: rep(0, 1 << 20)) {
      assert(countl_zero(x) == naive_countl_zero(x));
    }

    u64 large = u64(1) << 63;
    assert(countl_zero(large) == naive_countl_zero(large));

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
