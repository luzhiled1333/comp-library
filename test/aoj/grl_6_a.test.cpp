// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A

#include "src/cpp-template/header/input.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/dinic.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, m;
    std::cin >> n >> m;

    Dinic< u32 > g(n);
    for ([[maybe_unused]] usize _: rep(0, m)) {
      usize u, v;
      u32 c;
      std::cin >> u >> v >> c;
      g.add_directed_edge(u, v, c);
    }
    std::cout << g.max_flow(0, n - 1) << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
