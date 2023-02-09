// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/utility/bit/popcount.hpp"

#include "src/cpp-template/header/rep.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  usize naive_popcount(u64 x) {
    usize result = 0;
    while (x) {
      x &= (x - 1);
      result++;
    }
    return result;
  }

  void main_() {
    for (u64 x: rep(0, 1 << 20)) {
      assert(popcount(x) == naive_popcount(x));
    }

    assert(popcount(-1) == naive_popcount(-1));

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
