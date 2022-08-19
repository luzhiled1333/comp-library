#include <algorithm>
#include <vector>
#include <functional>

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

namespace luz {

  template< class T, class Compare = std::less< T > >
  class Compressor {
    std::vector< T > vs_;
    std::vector< T > zip_;
    std::vector< usize > ziped_vs_;

   public:
    explicit Compressor(std::vector< T > vs): vs_(vs), zip_(vs), ziped_vs_(vs.size()) {
      std::sort(zip_.begin(), zip_.end(), Compare());
      zip_.erase(std::unique(zip_.begin(), zip_.end()), zip_.end());
      for (usize i: rep(0, vs.size())) {
        ziped_vs_[i] = compress(vs[i]);
      }
    }

    std::vector< usize > result_of_compressing_vs() const {
      return ziped_vs_;
    }

    usize compress(T v) const {
      auto iter = std::lower_bound(zip_.begin(), zip_.end(), v);
      assert(*iter == v);
      return iter - zip_.begin();
    }

    T expand(usize i) const {
      assert(i < zip_.size());
      return zip_[i];
    }
  };

}
