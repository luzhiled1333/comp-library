#pragma once

#include <iomanip>
#include <iostream>

#include "src/cpp-template/header/type-alias.hpp"

namespace luz {

  void io_set(usize precision) {
    std::cout << std::fixed << std::setprecision(precision);
    std::cerr << std::fixed << std::setprecision(precision);
  }

} // namespace luz
