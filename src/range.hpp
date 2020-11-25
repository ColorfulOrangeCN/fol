#ifndef _FOL_RANGE_
#define _FOL_RANGE_

#include <utility>

namespace fol {

  template <typename C>
  std::pair<typename C::iterator, typename C::iterator> range(C& c) {
    return std::make_pair(c.begin(), c.end());
  }

  template <typename C>
  std::pair<typename C::const_iterator, typename C::const_iterator> range(C const& c) {
    return std::make_pair(c.begin(), c.end());
  }

  template <typename T, std::size_t N>
  std::pair<T*, T*> range(T (&a)[N]) {
    return std::make_pair(a, a + N);
  }

}  // namespace fol

#endif