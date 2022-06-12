#pragma once 

namespace luz {

  template <typename T1, typename T2>
  inline bool chmax(T1 &a, T2 b) {
    return a < b and (a = b, true);
  }

  template <typename T1, typename T2>
  inline bool chmin(T1 &a, T2 b) {
    return a > b and (a = b, true);
  }

} // namespace luz
