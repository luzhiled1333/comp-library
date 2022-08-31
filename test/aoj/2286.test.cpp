// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2286

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/math/enumerate-totient.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    constexpr int MAX_N      = 1000000;
    std::vector< u32 > euler = enumerate_totient(MAX_N + 1);
    std::vector< u64 > S(MAX_N + 1);
    for (u32 i: rep(2, MAX_N + 1)) {
      S[i] = S[i - 1] + euler[i];
    }
    u32 T;
    std::cin >> T;
    for ([[maybe_unused]] u32 _: rep(0, T)) {
      u32 N;
      std::cin >> N;
      std::cout << S[N] + 2 << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
