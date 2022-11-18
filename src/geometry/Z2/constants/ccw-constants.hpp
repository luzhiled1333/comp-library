#include "src/cpp-template/header/type-alias.hpp"

namespace luz::Z2::constants::ccw {

  constexpr i32 COUNTER_CLOCKWISE = +1;
  constexpr i32 CLOCKWISE         = -1;
  constexpr i32 ONLINE_BACK       = +2; // c-a-b
  constexpr i32 ONLINE_FRONT      = -2; // a-b-c
  constexpr i32 ON_SEGMENT        =  0; // a-c-b

}
