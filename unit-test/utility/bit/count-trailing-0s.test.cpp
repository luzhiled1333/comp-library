// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/utility/bit/count-trailing-0s.hpp"

#include "src/cpp-template/header/rep.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  usize naive_countr_zero(u64 x) {
    for (usize k: rep(0, 64)) {
      if (x & (u64(1) << k)) {
        return k;
      }
    }

    return 64;
  }

  void main_() {
    for (u64 x: rep(0, 1 << 20)) {
      assert(countr_zero(x) == naive_countr_zero(x));
    }

    u64 large = u64(1) << 63;
    assert(countr_zero(large) == naive_countr_zero(large));

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
