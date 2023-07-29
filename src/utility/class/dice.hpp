#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <array>
#include <cassert>
#include <vector>

namespace luz {

  template < typename T >
  class Dice {
    // +x, -x, +y, -y, +z, -z
    std::vector< T > dice;

    static constexpr std::array< std::array< T, 4 >, 6 > rot{
        {{2, 5, 3, 4},
         {4, 3, 5, 2},
         {4, 1, 5, 0},
         {0, 5, 1, 4},
         {0, 3, 1, 2},
         {2, 1, 3, 0}}};

    void rotate(const std::array< T, 4 > &idxs) {
      for (usize i: rep(1, 4)) {
        std::swap(dice[idxs[i - 1]], dice[idxs[i]]);
      }
    }

    void internal_rotate(usize base, isize count) {
      if (count != 0) {
        bool neg = count < 0;
        rotate(rot[base + neg]);
        internal_rotate(base, count + (neg ? +1 : -1));
      }
    }

    isize count_minimize(isize count) {
      return (count % 4 + 5) % 4 - 1;
    }

   public:
    Dice(): dice(6) {}
    Dice(T px, T nx, T py, T ny, T pz, T nz)
        : dice({px, nx, py, ny, pz, nz}) {}

    void rotate_x(isize count) {
      internal_rotate(0, count_minimize(count));
    }
    void rotate_y(isize count) {
      internal_rotate(2, count_minimize(count));
    }
    void rotate_z(isize count) {
      internal_rotate(4, count_minimize(count));
    }

    void rotate_by_id(usize idx) {
      rotate(rot[idx]);
    }

    T &right() {
      return dice[0];
    }
    T &left() {
      return dice[1];
    }
    T &back() {
      return dice[2];
    }
    T &front() {
      return dice[3];
    }
    T &top() {
      return dice[4];
    }
    T &bottom() {
      return dice[5];
    }

    T &face_id(usize idx) {
      assert(idx < 6);
      return dice[idx];
    }

    void normalize_as_top_front(T t, T f) {
      for (usize i: rep(0, 6)) {
        if (top() == t) {
          for ([[maybe_unused]] usize _: rep(0, 4)) {
            if (front() == f) return;
            rotate_z(1);
          }
        }

        rotate_by_id(2 * (i & 1));
      }

      assert(false);
    }
  };

  template < typename T >
  std::vector< Dice< T > > dice_enumeration(Dice< T > dice) {
    std::vector< Dice< T > > result;

    for (usize i: rep(0, 6)) {
      for ([[maybe_unused]] usize _: rep(0, 4)) {
        result.emplace_back(dice);
        dice.rotate_z(1);
      }

      dice.rotate_by_id(2 * (i & 1));
    }

    return result;
  }

} // namespace luz
