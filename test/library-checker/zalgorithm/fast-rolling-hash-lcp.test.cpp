// verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/vector-ios.hpp"
#include "src/sequence/fast-rolling-hash.hpp"

#include <iostream>
#include <string>
#include<vector>

namespace luz {

  void main_() {
    std::string s;
    std::cin >> s;

    const usize n = s.size();

    FastRollingHash froll;
    const auto hs = froll.build(s.begin(), s.end());

    std::vector< usize > ans;
    for (usize i: rep(0, n)) {
      ans.emplace_back(froll.lcp(hs, 0, n, hs, i, n));
    }

    std::cout << ans << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
