// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D

#include "src/cpp-template/header/int-alias.hpp"
#include "src/math/totient.hpp"

#include <iostream>

namespace luz {

  void main_() {
    u32 n;
    std::cin >> n;
    std::cout << totient(n) << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
