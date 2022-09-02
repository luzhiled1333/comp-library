// verification-helper: PROBLEM https://judge.yosupo.jp/problem/jump_on_tree

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/offline-query-level-ancestor.hpp"
#include "src/graph/offline-query-lowest-common-ancestor.hpp"

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    Graph< i32 > g(n);
    for ([[maybe_unused]] usize _: rep(0, n - 1)) {
      usize a, b;
      std::cin >> a >> b;
      g.add_undirected_edge(a, b);
    }

    std::queue< usize > que;
    std::vector< i32 > depth(n, -1);
    que.emplace(0);
    depth[0] = 0;
    while (not que.empty()) {
      usize v = que.front();
      que.pop();
      for (const auto& e: g[v]) {
        if (depth[e.to] == -1) {
          depth[e.to] = depth[v] + 1;
          que.emplace(e.to);
        }
      }
    }

    OfflineLCAQuery offline_lcas(g);
    std::vector< std::tuple< usize, usize, usize > > qs(q);
    for (auto& [s, t, i]: qs) {
      std::cin >> s >> t >> i;
      offline_lcas.add_query(s, t);
    }
    offline_lcas.build(0);

    std::vector< i32 > ans(q);
    std::vector< std::tuple< usize, usize, usize > > las;
    for (usize i: rep(0, q)) {
      const auto& [s, t, k] = qs[i];
      usize r               = offline_lcas.lca(s, t);
      usize sr_dist         = depth[s] - depth[r];
      usize rt_dist         = depth[t] - depth[r];
      if (k <= sr_dist) {
        las.emplace_back(i, s, depth[r] - k + sr_dist);
      } else if (k <= sr_dist + rt_dist) {
        las.emplace_back(i, t, depth[r] + k - sr_dist);
      } else {
        ans[i] = -1;
      }
    }

    OfflineLAQuery offline_las(g);
    for (const auto& [i, v, k]: las) {
      offline_las.add_query(v, k);
    }
    offline_las.build(0);

    for (const auto& [i, v, k]: las) {
      ans[i] = (i32)offline_las.la(v, k).value();
    }
    for (const auto& v: ans) {
      std::cout << v << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
