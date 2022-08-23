// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/data-structure/fenwick-tree.hpp"

#include "src/cpp-template/header/type-alias.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  void main_() {
    { // T as i32
      FenwickTree< i32 > ft(3);

      ft.add(0, 3);
      ft.add(1, 6);
      ft.add(2, -4);

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 3);
      assert(ft.sum(0, 1 + 1) == 9);
      assert(ft.sum(0, 2 + 1) == 5);
    }

    { // T as u32
      FenwickTree< u32 > ft(3);

      ft.add(0, 5);
      ft.add(1, 2);
      ft.add(2, 1);

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 5);
      assert(ft.sum(0, 1 + 1) == 7);
      assert(ft.sum(0, 2 + 1) == 8);
    }

    { // T as i64
      FenwickTree< i64 > ft(3);

      ft.add(0, 1000000000000ll);
      ft.add(1, 1000000000000ll);
      ft.add(2, -2000000000000ll);

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 1000000000000ll);
      assert(ft.sum(0, 1 + 1) == 2000000000000ll);
      assert(ft.sum(0, 2 + 1) == 0);
    }

    { // T as u64
      FenwickTree< u64 > ft(3);

      ft.add(0, 10000000000ull);
      ft.add(1, 10000000000ull);
      ft.add(2, 10000000000ull);

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 10000000000ull);
      assert(ft.sum(0, 1 + 1) == 20000000000ull);
      assert(ft.sum(0, 2 + 1) == 30000000000ull);
    }

    { // T as ModInt
      using mint = modint998244353;
      FenwickTree< mint > ft(3);

      ft.add(1, 5);
      ft.add(2, 998244352);

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 0);
      assert(ft.sum(0, 1 + 1) == 5);
      assert(ft.sum(0, 2 + 1) == 4);
    }

    { // T as i32
      FenwickTree< i32 > ft({1, -10, 100, -1000});

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 1);
      assert(ft.sum(0, 1 + 1) == -9);
      assert(ft.sum(0, 2 + 1) == 91);
      assert(ft.sum(0, 3 + 1) == -909);
    }

    { // T as u32
      FenwickTree< u32 > ft({1, 10, 100, 1000});

      assert(ft.sum(0, 0) == 0);
      assert(ft.sum(0, 0 + 1) == 1);
      assert(ft.sum(0, 1 + 1) == 11);
      assert(ft.sum(0, 2 + 1) == 111);
      assert(ft.sum(0, 3 + 1) == 1111);
    }

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
