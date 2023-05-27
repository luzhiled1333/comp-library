#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/single-source-shortest-path/in-unweighted-graph.hpp"
#include "src/graph/tree/offline-query/offline-query-level-ancestor.hpp"
#include "src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp"
#include "src/utility/tuple-hash.hpp"

#include <cassert>
#include <optional>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace luz {

  template < class G >
  class OfflineJumpOnTreeQuery {
    using graph     = G;
    using cost_type = typename graph::cost_type;

    usize g_size;
    G g;
    OfflineLCAQuery< graph > lca;
    OfflineLAQuery< graph > la;

    using query_type = std::tuple< usize, usize, usize >;

    std::vector< query_type > qs;

    std::vector< query_type > converted_qs;
    std::unordered_map< query_type, std::optional< usize >,
                        TupleHash >
        results;

    void bound_check(usize v) const {
      assert(v < g_size);
    }

   public:
    explicit OfflineJumpOnTreeQuery(graph &g)
        : g_size(g.size()),
          g(g),
          lca(g),
          la(g) {}

    void add_query(usize start, usize end, usize distance) {
      bound_check(start);
      bound_check(end);
      qs.emplace_back(start, end, distance);
    }

    void build(usize root) {
      bound_check(root);
      for (const auto &[s, t, _]: qs) {
        lca.add_query(s, t);
      }

      lca.build(root);

      sssp::InUnweightedGraph sssp_solver(g, root);
      std::vector< usize > depths = sssp_solver.get_distances();

      converted_qs.reserve(qs.size());
      results.reserve(qs.size());

      for (usize i: rep(0, qs.size())) {
        const auto &[s, t, d] = qs[i];
        usize r               = lca.lca(s, t);
        usize distance_sr     = depths[s] - depths[r];
        usize distance_rt     = depths[t] - depths[r];

        if (d <= distance_sr) {
          converted_qs.emplace_back(i, s,
                                    depths[r] + distance_sr - d);
        } else if (d <= distance_sr + distance_rt) {
          converted_qs.emplace_back(i, t,
                                    depths[r] + d - distance_sr);
        } else {
          results[qs[i]] = std::nullopt;
        }
      }

      for (const auto &[_, v, k]: converted_qs) {
        la.add_query(v, k);
      }

      la.build(root);

      for (const auto &[i, v, k]: converted_qs) {
        results[qs[i]] = la.la(v, k);
      }
    }

    std::optional< usize > jump_on_tree(usize start, usize end,
                                        usize distance) const {
      bound_check(start);
      bound_check(end);
      query_type qi(start, end, distance);
      assert(results.count(qi));
      return (*results.find(qi)).second;
    }
  };

} // namespace luz
