// verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_h
// verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_ex

#include "src/cpp-template/header/size-alias.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"
#include "src/sequence/wildcard-pattern-matching.hpp"

#include <iostream>

namespace luz {

  void main_() {
    using mint = modint998244353;

    usize l, w;
    std::string s;

    std::cin >> l >> w >> s;
    s += std::string(w - 1, '.');
    s += s.substr(0, w - 1);

    std::string p;
    std::cin >> p;

    auto wpm = wildcard_pattern_matching< mint >(
        s.begin(), s.end(), p.begin(), p.end(), '_');

    std::cout << std::count(wpm.begin(), wpm.end(), 1) << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
