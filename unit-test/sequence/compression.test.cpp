// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <vector>
#include <ostream>
#include <cassert>

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/vector-ios.hpp"

#include "src/sequence/compression.hpp"

namespace luz {

  void main_() {
    std::vector< int > vs({8, -5, 3, 4, 3, 7, 1});
    std::vector< usize > expected({5, 0, 2, 3, 2, 4, 1});

    Compressor< int > cp(vs);
    std::vector< usize > result = cp.result_of_compressing_vs();
    assert(result == expected);

    std::cerr << "result  : " << result << std::endl;
    std::cerr << "expected: " << expected << std::endl;

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
