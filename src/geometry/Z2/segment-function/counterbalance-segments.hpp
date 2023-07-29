#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/geometry/Z2/class/segment.hpp"
#include "src/geometry/Z2/compare/compare-xy.hpp"
#include "src/geometry/Z2/normalize/line-normalize.hpp"
#include "src/geometry/Z2/operation/ccw.hpp"
#include "src/geometry/Z2/utility/next-idx.hpp"
#include "src/sequence/compression.hpp"

#include <cmath>
#include <tuple>
#include <utility>
#include <vector>

namespace luz::Z2 {

  template < typename Z >
  Segments< Z > counterbalance_segments(
      const Segments< Z > &segments) {
    usize n = segments.size();

    std::vector< std::tuple< Z, Z, Z > > normalized_lines(n);
    for (usize i: rep(0, n)) {
      normalized_lines[i] =
          normalize_l(Line(segments[i].p0(), segments[i].p1()));
    }

    Compressor compressor(normalized_lines);
    std::vector< usize > line_idxs = compressor.compressed_vector();
    usize line_count =
        (*std::max_element(line_idxs.begin(), line_idxs.end())) + 1;

    using event_type = std::pair< Point< Z >, i32 >;
    std::vector< std::vector< event_type > > events_each_line(
        line_count);
    for (usize i: rep(0, n)) {
      usize l_idx = line_idxs[i];
      events_each_line[l_idx].emplace_back(segments[i].p0(), +1);
      events_each_line[l_idx].emplace_back(segments[i].p1(), -1);
    }

    auto cmp = [](const event_type &e0, const event_type &e1) {
      CompareXY< Z > comp;
      if (e0.first != e1.first) return comp(e0.first, e1.first);
      return e0.second < e1.second;
    };

    Segments< Z > result;
    for (auto &events: events_each_line) {
      std::sort(events.begin(), events.end(), cmp);

      for (usize i: rep(1, events.size())) {
        i32 prev = events[i - 1].second;
        events[i].second += prev;
        if (events[i - 1].first == events[i].first) continue;
        if (std::abs(prev) != 1) continue;

        Point< Z > from = events[i - 1].first;
        Point< Z > to   = events[i].first;
        if (prev == -1) std::swap(from, to);
        Segment< Z > seg(from, to);

        if (not result.empty()) {
          Segment< Z > prev_seg = result.back();
          Vector< Z > a = prev_seg.p0(), b = prev_seg.p1();
          Vector< Z > c = seg.p0(), d = seg.p1();
          if (b == c and std::abs(ccw(a, c, d)) != 1) {
            seg = Segment(a, d);
            result.pop_back();
          }
          if (a == d and std::abs(ccw(c, a, b)) != 1) {
            seg = Segment(c, b);
            result.pop_back();
          }
        }

        result.emplace_back(seg);
      }
    }

    return result;
  }
} // namespace luz::Z2
