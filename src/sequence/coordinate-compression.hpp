#include <algorithm>
#include <vector>

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

namespace luz {

template <typename T>
std::vector<usize> coordinate_compression(std::vector<T> vs) {
  std::vector<usize> res(vs.size());

  std::vector<T> zip = vs;
  std::sort(zip.begin(), zip.end());
  zip.erase(std::unique(zip.begin(), zip.end()), zip.end());

  for (usize i: rep(0, vs.size())) {
    res[i] = std::lower_bound(zip.begin(), zip.end(), vs[i]) - zip.begin();
  }

  return res;
}

}// namespace luz
