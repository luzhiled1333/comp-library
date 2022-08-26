// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/math/totient.hpp"

#include "src/cpp-template/header/rep.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  void main_() {

    // small
    u64 totients[] = {0, 1, 1, 2, 2, 4, 2, 6, 4, 6};
    for (u64 i: rep(0, 10)) {
      assert(totient(i) == totients[i]);
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
