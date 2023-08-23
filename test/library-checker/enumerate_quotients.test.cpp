// verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients

#include "src/cpp-template/header/fast-ios.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/math/floor/enumerate-quotients.hpp"

#include <iostream>

namespace luz {

  void main_() {
    u64 n;
    std::cin >> n;
    auto quotients = enumerate_quotients(n);
    std::cout << quotients.size() << std::endl;
    for (auto&& [q, l, r]: quotients) {
      std::cout << q << " ";
    }
    std::cout << std::endl;
  }

} // namespace luz

int main() {
  luz::set_fast_ios();

  luz::main_();
}
