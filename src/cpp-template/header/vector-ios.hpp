#pragma once

#include "src/cpp-template/header/rep.hpp"

namespace luz {

  template< typename T >
  std::ostream &operator<<(std::ostream &os, std::vector< T > &vs) {
    for (usize i: rep(0, vs.size())) {
      os << vs[i] << (i + 1 != vs.size() ? " " : "");
    }
    return os;
  }

  template< typename T >
  std::istream &operator>>(std::istream &is, std::vector< T > &vs) {
    for (T &v: vs) {
      is >> v;
    }
    return is;
  }

} // namespace luz
