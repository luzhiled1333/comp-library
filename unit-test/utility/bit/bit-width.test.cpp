// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/utility/bit/bit-width.hpp"

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  usize naive_bit_width(u64 x) {
    for (usize k: rrep(0, 64)) {
      if (x & (u64(1) << k)) {
        return k + 1;
      }
    }

    return 0;
  }

  void main_() {
    for (u64 x: rep(0, 1 << 20)) {
      assert(bit_width(x) == naive_bit_width(x));
    }

    u64 large = u64(1) << 63;
    assert(bit_width(large) == naive_bit_width(large));

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
