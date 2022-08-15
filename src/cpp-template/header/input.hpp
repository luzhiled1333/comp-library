#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <iostream>

namespace luz {

template <typename T = i64>
T input() {
  T tmp;
  std::cin >> tmp;
  return tmp;
}

}// namespace luz
