#pragma once

#include "src/cpp-template/header/size-alias.hpp"

#include <iomanip>
#include <iostream>

namespace luz {

  void io_set(usize precision) {
    std::cout << std::fixed << std::setprecision(precision);
    std::cerr << std::fixed << std::setprecision(precision);
  }

} // namespace luz
