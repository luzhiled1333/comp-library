#pragma once

#include <iostream>
#include <utility>

namespace luz {

  template< typename T1, typename T2 >
  std::ostream &operator<<(std::ostream &os, std::pair < T1, T2 > p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
  }

  template< typename T1, typename T2 >
  std::istream &operator>>(std::istream &is, std::pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
  }

} // namespace luz
