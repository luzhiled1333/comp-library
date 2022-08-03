#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>
#include <string>
#include <utility>

namespace luz {

namespace impl {

  template< typename T >
  std::vector< std::pair< T, usize > > rle(const std::vector< T > &vs) {
    std::vector< std::pair< T, usize > > result;
    for (const auto &v: vs) {
      if (result.empty() or result.back().first != v) {
        result.emplace_back(v, 0);
      }
      result.back().second++;
    }

    return result;
  }

} // namespace impl

  template< typename T >
  std::vector< std::pair< T, usize > > run_length_encoding(const std::vector< T > &vs) {
    return impl::rle(vs);
  }
  
  std::vector< std::pair< char, usize > > run_length_encoding(const std::string &s) {
    std::vector< char > cs(s.begin(), s.end());
    return impl::rle(cs);
  }

} // namespace luz
