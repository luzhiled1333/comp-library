#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

namespace luz {

  template < class T, class Compare = std::less< T > >
  class Compressor {
    std::vector< T > vs;
    std::vector< T > zip;
    std::vector< usize > ziped_vs;

   public:
    explicit Compressor(std::vector< T > vs)
        : vs(vs),
          zip(vs),
          ziped_vs(vs.size()) {
      std::sort(zip.begin(), zip.end(), Compare());
      zip.erase(std::unique(zip.begin(), zip.end()), zip.end());
      for (usize i: rep(0, vs.size())) {
        ziped_vs[i] = compress(vs[i]);
      }
    }

    std::vector< usize > compressed_vector() const {
      return ziped_vs;
    }

    usize compress(T v) const {
      auto iter = std::lower_bound(zip.begin(), zip.end(), v);
      assert(*iter == v);
      return iter - zip.begin();
    }

    T expand(usize i) const {
      assert(i < zip.size());
      return zip[i];
    }
  };

} // namespace luz
