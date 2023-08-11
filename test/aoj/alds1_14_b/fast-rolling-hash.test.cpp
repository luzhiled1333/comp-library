// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B

#include "src/sequence/fast-rolling-hash.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <iostream>
#include <string>

namespace luz {

  void main_() {
    std::string t, p;
    std::cin >> t >> p;

    const usize n = t.size(), m = p.size();
    if (n < m) return;

    FastRollingHash froll;
    const auto hs1 = froll.build(t.begin(), t.end());
    const auto hs2 = froll.build(p.begin(), p.end());

    for (usize i: rep(0, n - m + 1)) {
      if (froll.query(hs1, i, i + m) != froll.query(hs2, 0, m)) {
        continue;
      }

      std::cout << i << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
