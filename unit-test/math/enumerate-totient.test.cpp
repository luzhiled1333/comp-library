// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/math/enumerate-totient.hpp"

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

namespace luz {

  u32 naive_totient(u32 n) {
    u32 result = 0;
    for (u32 m: rep(1, n + 1)) {
      if (std::gcd(n, m) == 1) result++;
    }
    return result;
  }

  void main_() {
    std::vector< u32 > totients = enumerate_totient((u32)1000);

    for (u32 i: rep(0, 1000)) {
      assert(totients[i] == naive_totient(i));
    }

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
