#pragma once

#include <utility>
#include <vector>

namespace luz::internal {

  template < class Tree >
  usize find_centroid(usize v, usize p, const usize mid,
                      const Tree &g, const std::vector< usize > &sub,
                      const std::vector< usize > &vs) {
    for (const auto &e: g[v]) {
      if (e.to == p or vs[e.to]) continue;
      if (sub[e.to] <= mid) continue;
      return find_centroid(e.to, v, mid, g, sub, vs);
    }
    return v;
  }

  template < class Tree >
  usize dfs(usize v, usize p, const Tree &g,
            std::vector< usize > &sub,
            const std::vector< usize > &vs) {
    sub[v] = 1;
    for (const auto &e: g[v]) {
      if (e.to == p or vs[e.to]) continue;
      sub[v] += dfs(e.to, v, g, sub, vs);
    }
    return sub[v];
  }

  template < class Tree >
  usize centroid_decomposition(usize v, const Tree &g, Tree &tree,
                               std::vector< usize > &sub,
                               std::vector< usize > &vs) {
    usize centroid =
        find_centroid(v, -1, dfs(v, -1, g, sub, vs) / 2, g, sub, vs);
    vs[centroid] = true;
    for (const auto &e: g[centroid]) {
      if (not vs[e.to]) {
        tree.add_directed_edge(
            centroid, centroid_decomposition(e.to, g, tree, sub, vs));
      }
    }
    vs[centroid] = false;
    return centroid;
  }

} // namespace luz::internal

namespace luz {

  template < class Tree >
  std::pair< Tree, usize > centroid_decomposition(const Tree &g) {
    usize n = g.size();

    Tree tree(n);
    std::vector< usize > sub(n), vs(n);
    usize r = internal::centroid_decomposition(0, g, tree, sub, vs);
    return {tree, r};
  }

} // namespace luz
