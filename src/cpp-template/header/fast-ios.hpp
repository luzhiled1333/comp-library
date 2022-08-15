#pragma once

#include <iostream>

namespace luz {

void set_fast_ios() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

} // namespace luz
