// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2286

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/math/totient-enumeration.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    constexpr u32 MAX_N = 1000000;

    std::vector< u64 > rs = totient_enumeration< u64 >(MAX_N);
    for (usize i: rep(2, rs.size())) {
      rs[i] += rs[i - 1];
    }

    usize t;
    std::cin >> t;
    for ([[maybe_unused]] usize _: rep(0, t)) {
      usize n;
      std::cin >> n;

      std::cout << rs[n] + 1 << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
