// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/geometry/R2/class/point.hpp"
#include "src/geometry/R2/class/vector.hpp"

#include <iostream>

namespace luz {

  void main_() {
    using R      = double;

    using Vector = R2::Vector< R >;
    Vector a(3.0, 2.5);
    a += 3 * (Vector(2.0, 2.5) + Vector(-3.0, 2.0)) * 2;
    a -= (Vector(4.0, 1.5) - Vector(-8.0, 1.0)) / 3;

    a *= 3;
    a /= 2;

    using Point = R2::Point< R >;
    Point b(3.0, 2.5);
    b += 3 * (Point(2.0, 2.5) + Point(-3.0, 2.0)) * 2;
    b -= (Point(4.0, 1.5) - Point(-8.0, 1.0)) / 3;

    b *= 3;
    b /= 2;

    a += Point(Point(1.0, 0.0) + Vector(0.0, 1.0));
    b += Vector(Vector(1.0, 0.0) + Point(0.0, 1.0));

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
