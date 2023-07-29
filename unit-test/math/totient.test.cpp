// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/math/totient.hpp"

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

#include <cassert>
#include <iostream>
#include <numeric>

namespace luz {

  u32 naive_totient(u32 n) {
    u32 result = 0;
    for (u32 m: rep(1, n + 1)) {
      if (std::gcd(n, m) == 1) result++;
    }
    return result;
  }

  void main_() {

    // small
    for (u32 i: rep(0, 1000)) {
      assert(totient(i) == naive_totient(i));
    }

    // large
    assert(totient(735134400) == 132710400);
    assert(totient(1000000007) == 1000000006);
    assert(totient(1000000009) == 1000000008);
    assert(totient(31415926535) == 20847434400);

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
