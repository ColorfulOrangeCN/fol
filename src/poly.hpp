#ifndef _FOL_POLY_
#define _FOL_POLY_
#include <vector>

template <typename Container, typename CovSysT>
class Poly : public Container {
 protected:
std::vector<int> rev;
  typedef typename CovSysT::Integer Integer;
  const static Integer mods = CovSysT::mods;

 public:
  void initbrp() {
    rev.resize(this->size());
    rev[0] = 0;
    for (int i = 1; i < this->size(); ++i) {
      rev[i] = rev[i >> 1] >> 1;
      if (i & 1)
        rev[i] |= this->size() >> 1;
    }
  }

 public:
  void ntt(const Integer _g = CovSysT::g) {
    Poly<Container, CovSysT>& f = *this;
    if (rev.size() != f.size())
      f.initbrp();
    for (int i = 0; i < f.size(); ++i)
      if (i < rev[i])
        swap(f[i], f[rev[i]]);
    for (int n = 2; n <= f.size(); n <<= 1) {
      const Integer stp = CovSysT::modpow(_g, (mods - 1) / n);
      const int dn = n / 2;
      for (int i = 0; i < f.size(); i += n) {
        Integer w = 1;
        for (int j = 0; j < dn; ++j, (w *= stp) %= mods) {
          const Integer x = f[i + j], y = f[i + j + dn] * w % CovSysT::mods;
          f[i + j] = (x + y) % CovSysT::mods;
          f[i + j + dn] = (x - y) % CovSysT::mods;
        }
      }
    }
  }
  void intt() {
    const Integer v = CovSysT::inv(this->size());
    ntt(CovSysT::inv(CovSysT::g));
    for (int i = 0; i < this->size(); ++i)
      (this->operator[](i) *= v) %= mods;
  }
  Poly<Container, CovSysT>& operator*=(Poly<Container, CovSysT> g) {
    Poly<Container, CovSysT>& f = *this;
    f.resize(f.size() * 2);
    g.resize(g.size() * 2);
    f.ntt();
    g.ntt();
    for (int i = 0; i < f.size(); ++i)
      (f[i] *= g[i]) %= mods;
    f.intt();
    return f;
  }
  Poly<Container, CovSysT> inv() {
    const Poly& f = *this;
    Poly g, tf;
    g.push_back(CovSysT::inv(f[0]));
    for (int n = 1; n <= f.size(); n <<= 1) {
      g.resize(n * 2, 0);
      tf.resize(n * 2, 0);
      copy(f.begin(), f.begin() + n, tf.begin());
      g.ntt();
      tf.ntt();
      for (int i = 0; i < g.size(); ++i)
        (g[i] *= 2 - tf[i] * g[i] % mods) %= mods;
      g.intt();
      fill(g.begin() + n, g.end(), 0);
    }
    g.resize(f.size());
    return g;
  }
};

#endif
