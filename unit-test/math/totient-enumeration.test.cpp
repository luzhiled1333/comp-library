// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/math/totient-enumeration.hpp"

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

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
    std::vector< u32 > totients = totient_enumeration((u32)1000);

    for (u32 i: rep(0, 1001)) {
      assert(totients[i] == naive_totient(i));
    }

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
