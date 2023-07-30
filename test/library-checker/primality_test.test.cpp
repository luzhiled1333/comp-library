// verification-helper: PROBLEM https://judge.yosupo.jp/problem/primality_test

#include "src/cpp-template/header/fast-ios.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/math/primes/primality-test.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize q;
    std::cin >> q;

    while (q--) {
      u64 n;
      std::cin >> n;

      std::cout << (is_prime(n) ? "Yes" : "No") << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::set_fast_ios();

  luz::main_();
}
