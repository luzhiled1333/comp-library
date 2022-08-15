#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <cassert>

namespace luz {

template <typename cost_type>
class FunctionalGraph: Graph<cost_type> {
  using Graph<cost_type>::Graph;
  using Graph<cost_type>::g;
  using Graph<cost_type>::size;
  using Graph<cost_type>::add_directed_edge;

  usize LOG;
  std::vector<std::vector<usize>> doubling_table;

public:
  void add_edge(usize from, usize to, cost_type cost = 1) {
    assert(from < size());
    assert(to < size());
    add_directed_edge(from, to, cost);
    assert(g[from].size() == 1);
  }

  void initialize_jump(const u64 MAX_K) {
    LOG = 0;
    while (usize(1) << (LOG + 1) <= MAX_K) {
      LOG++;
    }

    doubling_table.assign(LOG, std::vector<usize>(size()));
    for (usize v: rep(0, size())) {
      doubling_table[0][v] = (g[v].size() == 1 ? g[v][0].to : -1);
    }
    for (usize k: rep(1, LOG)) {
      for (usize v: rep(0, size())) {
        usize pv = doubling_table[k - 1][v];
        if (pv == (usize)-1) {
          doubling_table[k][v] = pv;
        } else {
          doubling_table[k][v] = doubling_table[k - 1][pv];
        }
      }
    }
  }

  usize jump(usize v, u64 k) {
    if (k == 0) return v;
    for (usize i: rep(0, LOG)) {
      if ((k & 1) == 1) {
        v = doubling_table[i][v];
      }
      k >>= 1;
    }

    return v;
  }
};

}// namespace luz
