#pragma once

#include "src/cpp-template/header/size-alias.hpp"

#include <string>
#include <utility>
#include <vector>

namespace luz::impl {

  template < typename T >
  std::vector< std::pair< T, usize > > rle(
      const std::vector< T > &vs) {
    std::vector< std::pair< T, usize > > result;
    for (const auto &v: vs) {
      if (result.empty() or result.back().first != v) {
        result.emplace_back(v, 0);
      }
      result.back().second++;
    }
    return result;
  }

} // namespace luz::impl

namespace luz {

  template< class T, class Iter >
  std::vector< std::pair< T, usize > > run_length_encoding(Iter first, Iter last) {
    std::vector< std::pair< T, usize > > result;

    while (first != last) {
      if (result.empty() or result.back().first != *first) {
        result.emplace_back(*first, 0);
      }

      result.back().second++;
      ++first;
    }

    return result;
  }

  template < typename T >
  std::vector< std::pair< T, usize > > run_length_encoding(
      const std::vector< T > &vs) {
    return run_length_encoding(vs.begin(), vs.end());
  }

  std::vector< std::pair< char, usize > > run_length_encoding(
      const std::string &s) {
    return run_length_encoding<char>(s.begin(), s.end());
  }

} // namespace luz
