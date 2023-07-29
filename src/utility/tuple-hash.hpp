#pragma once

#include "src/cpp-template/header/size-alias.hpp"

#include <functional>
#include <tuple>
#include <utility>

namespace luz::impl_tuple_hash {

  template < usize Index >
  class ImplTupleHash {
   public:
    template < typename T >
    usize hash_combine(const T &x, usize hr) const {
      usize h = std::hash< T >()(x);
      return hr ^ (h + (hr << 11) + (hr >> 13));
    }

    template < class Tuple >
    usize operator()(const Tuple &t) const noexcept {
      usize hr = ImplTupleHash< Index - 1 >()(t);
      return hash_combine(std::get< Index - 1 >(t), hr);
    }
  };

  template <>
  class ImplTupleHash< 0 > {
   public:
    template < class Tuple >
    usize operator()([[maybe_unused]] const Tuple &_) const noexcept {
      return 0;
    }
  };

} // namespace luz::impl_tuple_hash

namespace luz {

  class TupleHash {
    template < usize Index >
    using ImplTupleHash = impl_tuple_hash::ImplTupleHash< Index >;

   public:
    template < class... Args >
    usize operator()(const std::tuple< Args... > &t) const {
      using Tuple = std::tuple< Args... >;
      return ImplTupleHash< std::tuple_size< Tuple >::value >()(t);
    }
  };

} // namespace luz
