// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/math/modular-arithmetic/static-modint.hpp"

#include <iostream>
#include <cassert>

namespace luz {

  void main_() {
    using mint = StaticPrimeModInt<11>;

    mint a = 10;
    mint b(3);

    // equal
    assert(a == 10);
    assert(10 == a);
    assert(a == 21);
    assert(a == -1);

    // positive and negative
    assert(+b == 3);
    assert(-b == 8);

    // add
    assert(a + b == 2);
    assert(1 + a == 0);
    assert(a + 1 == 0);

    // sub
    assert(a - b == 7);
    assert(b - a == 4);
    assert(a - 1 == 9);
    assert(1 - a == 2);

    // mul
    assert(a * b == 8);
    assert(a * 2 == 9);
    assert(2 * a == 9);

    // div
    assert(a / b == 7);
    assert(a / 2 == 5);
    assert(2 / a == 9);

    // @=
    a += b;
    assert(a ==  2 and b == 3);
    a -= b;
    assert(a == 10 and b == 3);
    a *= b;
    assert(a ==  8 and b == 3);
    a /= b;
    assert(a == 10 and b == 3);

    // pow
    assert(b.pow(3) == 5); // 27 mod 11

    // inverse
    assert(b.inverse() == 4);

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
