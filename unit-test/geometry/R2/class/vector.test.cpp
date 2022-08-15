// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/geometry/R2/class/vector.hpp"

#include <iostream>

namespace luz {

  void main_() {
    using R = double;
    using Vector = R2::Vector< R >;
    Vector a(3.0, 2.5);
    a += (Vector(2.0, 2.5) + Vector(-3.0, 2.0)) * 2;
    a -= (Vector(4.0, 1.5) - Vector(-8.0, 1.0)) / 3;

    a *= 3;
    a /= 2;

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
