#ifndef _FOL_COVSYS_
#define _FOL_COVSYS_

namespace fol {
  template <typename _Integer, _Integer _mods, _Integer _g = 0>
  class CovSys {
   public:
    typedef _Integer Integer;
    const static Integer mods = _mods;
    const static Integer g = _g;
    template <typename T>
    static Integer modpow(Integer a, T p) {
      Integer res = 1;
      while (p) {
        if (p & 1)
          (res *= a) %= mods;
        (a *= a) %= mods;
        p >>= 1;
      }
      return res;
    }
    static Integer inv(Integer a) { return modpow(a, mods - 2); }
  };
}  // namespace fol

#endif
