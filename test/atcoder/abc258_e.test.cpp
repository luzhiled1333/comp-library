// verification-helper: PROBLEM https://atcoder.jp/contests/abc258/tasks/abc259_e

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/functional-graph-utility.hpp"
#include "src/cpp-template/header/vector-ios.hpp"

#include <iostream>
#include <numeric>
#include <vector>

namespace luz {
 
  void main_() {
    usize n, q, x;
    std::cin >> n >> q >> x;

    std::vector< i64 > ws(n);
    std::cin >> ws;
 
    i64 sum_w = std::accumulate(ws.begin(), ws.end(), i64());
    i64 xp = x % sum_w;
    std::vector< i64 > ans(n, x / sum_w * n);
 
    ws.resize(2 * n + 1);
    for (usize i: rep(0, n)) {
      ws[n + i] = ws[i];
    }
    for (usize i: rrep(0, 2 * n)) {
      ws[i] += ws[i + 1];
    }
 
    FunctionalGraph< i32 > fg(n);
    usize r = 0;
    for (usize l: rep(0, n)) {
      while (ws[l] - ws[r] < xp) {
        r++;
      }
 
      fg.add_edge(l, r % n);
      ans[l] += r - l;
    }
 
    fg.initialize_jump(1e13);
    
    for (usize _: rep(0, q)) {
      u64 k;
      std::cin >> k;
      usize v = fg.jump(0, k - 1);
      std::cout << ans[v] << std::endl;
    }
  }
 
} // namespace luz

int main() {
  luz::main_();
}
