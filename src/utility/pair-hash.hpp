#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <functional>
#include <utility>

namespace luz {

  class PairHash {
    template < typename T >
    usize hash_combine(usize hr, const T &x) const {
      usize h = std::hash< T >()(x);
      return hr ^ (h + (hr << 11) + (hr >> 13));
    }

   public:
    template < typename F, typename S >
    usize operator()(const std::pair< F, S > &p) const {
      return hash_combine(hash_combine(0, p.first), p.second);
    }
  };

} // namespace luz
