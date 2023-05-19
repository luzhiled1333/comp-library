// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc

#include "src/cpp-template/header/fast-ios.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/vector-ios.hpp"
#include "src/graph/decomposition/strongly-connected-components.hpp"
#include "src/graph/graph-template.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    usize n, m;
    std::cin >> n >> m;
    Graph< i32 > g(n);
    for ([[maybe_unused]] usize _: rep(0, m)) {
      usize u, v;
      std::cin >> u >> v;
      g.add_directed_edge(u, v);
    }
    decomposition::StronglyConnectedComponents< i32 > scc(g);
    auto groups = scc.groups();
    std::cout << groups.size() << std::endl;
    for (auto& group: groups) {
      std::cout << group.size() << " " << group << " " << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::set_fast_ios();

  luz::main_();
}
