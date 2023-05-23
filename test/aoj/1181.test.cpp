// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1181

#include "src/cpp-template/header/change-minmax.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/vector-ios.hpp"
#include "src/utility/class/dice.hpp"

#include <iostream>
#include <map>
#include <utility>
#include <vector>

namespace luz {

  using coordinate = std::pair< isize, isize >;
  using dice       = Dice< i32 >;
  using hs_map     = std::map< coordinate, usize >;
  using tops_map   = std::map< coordinate, i32 >;

  void put(dice &d, isize y, isize x, hs_map &hs, tops_map &tops) {
    coordinate now(y, x);

    std::vector< isize > dy({0, 0, 1, -1});
    std::vector< isize > dx({1, -1, 0, 0});
    std::vector< usize > rot_id({2, 3, 1, 0});
    usize rid = -1;
    isize ny = y, nx = x;
    i32 max_face = 3;
    for (usize id: rep(0, 4)) {
      if (hs[coordinate(y + dy[id], x + dx[id])] >= hs[now]) continue;

      if (chmax(max_face, d.face_id(id))) {
        rid = rot_id[id];
        ny  = y + dy[id];
        nx  = x + dx[id];
      }
    }

    if (max_face < 4) {
      hs[now]++;
      tops[now] = d.top() - 1;
      return;
    }

    d.rotate_by_id(rid);
    put(d, ny, nx, hs, tops);
  }

  void solve(usize n) {
    dice d(5, 2, 4, 3, 1, 6);

    std::map< coordinate, usize > hs;
    std::map< coordinate, i32 > tops;

    for ([[maybe_unused]] usize _: rep(0, n)) {
      i32 t, f;
      std::cin >> t >> f;

      d.normalize_as_top_front(t, f);
      put(d, 0, 0, hs, tops);
    }

    std::vector< usize > ans(6);
    for (auto &[_, top]: tops) {
      ans[top]++;
    }

    std::cout << ans << std::endl;
  }

  void main_() {
    usize n;
    while (std::cin >> n, n) {
      solve(n);
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
