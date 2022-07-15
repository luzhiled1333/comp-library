#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <iostream>
#include <iomanip>

namespace luz {

  void io_set(usize precision) {
    std::cout << std::fixed << std::setprecision(precision);
    std::cerr << std::fixed << std::setprecision(precision);
  }

} // namespace luz
