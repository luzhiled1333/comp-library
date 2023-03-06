// verification-helper: IGNORE
// verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e

#include "src/cpp-template/header/rep.hpp"
#include "src/graph/graph-template.hpp"
#include "src/graph/topological-ordering/lexical-order-topological-sort.hpp"

#include <functional>

namespace luz {

  void main_() {
    using graph = Graph< usize >;

    usize n = input(), m = input();

    graph g(n);
    for ([[maybe_unused]] usize _: rep(0, m)) {
      usize t = input() - 1, f = input() - 1;
      g.add_directed_edge(t, f);
    }

    auto ord = topological_sort< usize, std::greater< usize > >(g);
    auto rev = topological_sort< usize, std::less< usize > >(g);

    if (ord == rev) {
      std::cout << "Yes" << std::endl;

      std::vector< usize > ans(n);
      for (usize i: rep(0, n)) {
        ans[ord[i]] = i + 1;
      }

      std::cout << ans << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
