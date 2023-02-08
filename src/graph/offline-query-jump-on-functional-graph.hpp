namespace luz {
  template < typename cost_type >
  class OfflineJumpOnFunctionalGraphQuery {
    usize g_size;
    Graph< cost_type > g;
    Graph< usize > tree;
    std::vector< usize > tree_depth, tree_root;
    OfflineLAQuery< usize > la;
    std::vector< usize > loop_id, loop_size, loop_pos;
    std::vector< std::vector< usize > > loops;
    using query_type = std::pair< usize, u64 >;
    std::vector< query_type > qs;
    std::unordered_map< query_type, usize, PairHash > result;

    void dfs_on_tree(usize v, usize p) {
      for (auto &e: tree[v]) {
        usize u = e.to;
        if (u == p) continue;
        tree_root[u]  = tree_root[v];
        tree_depth[u] = tree_depth[v] + 1;
        dfs_on_tree(u, v);
      }
    }

   public:
    explicit OfflineJumpOnFunctionalGraphQuery(
        const Graph< cost_type > &g_)
        : g_size(g_.size()),
          tree(g_.size() + 1),
          tree_depth(g_.size()),
          tree_root(g_.size()),
          loop_id(g_.size()),
          loop_size(g_.size()),
          loop_pos(g_.size()),
          g(g_) {
      for (usize v: rep(0, g_size)) {
        assert(g[v].size() == 1);
      }
    }

    void add_query(usize v, u64 k) {
      qs.emplace_back(v, k);
    }

    void build() {
      std::vector< usize > degs(g_size);
      for (usize v: rep(0, g_size)) {
        degs[g[v][0].to]++;
      }
      std::vector< usize > que;
      que.reserve(g_size);
      for (usize v: rep(0, g_size)) {
        if (degs[v] == 0) {
          que.emplace_back(v);
        }
      }
      while (not que.empty()) {
        usize v = que.back();
        que.pop_back();
        usize u = g[v][0].to;
        degs[u]--;
        tree.add_undirected_edge(u, v);
        if (degs[u] == 0) {
          que.emplace_back(u);
        }
      }
      for (usize v: rep(0, g_size)) {
        if (degs[v] != 0) {
          tree_root[v] = v;
          tree.add_undirected_edge(g_size, v);
          dfs_on_tree(v, g_size);
        }
      }
      for (usize v: rep(0, g_size)) {
        if (degs[v] != 0) {
          usize cur = v;
          std::vector< usize > loop;
          do {
            loop_id[cur]  = loops.size();
            loop_pos[cur] = loop.size();
            loop.emplace_back(cur);
            degs[cur] = 0;
            cur       = g[cur][0].to;
          } while (cur != v);
          do {
            loop_size[cur] = loop.size();
            cur            = g[cur][0].to;
          } while (cur != v);
          loops.emplace_back(std::move(loop));
        }
      }
      la = OfflineLAQuery(tree);
      result.reserve(qs.size());
      for (auto [v, k]: qs) {
        if (k < tree_depth[v]) {
          la.add_query(v, tree_depth[v] - k + 1);
        } else {
          query_type qi(v, k);
          k -= tree_depth[v];
          usize root = tree_root[v];
          auto &loop = loops[loop_id[root]];
          k += loop_pos[root];
          k %= loop_size[root];
          result[qi] = loop[k];
        }
      }
      la.build(g_size);
      for (auto [v, k]: qs) {
        if (k < tree_depth[v]) {
          query_type qi(v, k);
          result[qi] = la.la(v, tree_depth[v] - k + 1).value();
        }
      }
    }

    usize jump(usize v, u64 k) const {
      query_type qi(v, k);
      assert(result.count(qi));
      return result.find(qi)->second;
    }
  };
} // namespace luz
