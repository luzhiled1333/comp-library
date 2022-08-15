#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {

  template <typename T>
  std::vector<T> make_vector(usize a, T b) {
    return std::vector<T>(a, b);
  }

  template <typename... Ts>
  auto make_vector(usize a, Ts... ts) {
    return std::vector<decltype(make_vector(ts...))>(a, make_vector(ts...));
  }

} // namespace luz
