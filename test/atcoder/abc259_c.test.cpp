// verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_c

#include "src/cpp-template/header/change-minmax.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/sequence/run-length-encoding.hpp"

#include <algorithm>
#include <iostream>
#include <string>

namespace luz {

  void main_() {
    std::string s, t;
    std::cin >> s >> t;

    auto ss = run_length_encoding(s);
    auto ts = run_length_encoding(t);

    usize n = std::min(ss.size(), ts.size());
    for (usize i: rep(0, n)) {
      auto &[sc, scnt] = ss[i];
      auto &[tc, tcnt] = ts[i];

      if (scnt >= 2) {
        chmin(tcnt, scnt);
      }
    }

    if (ss == ts) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
