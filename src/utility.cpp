#ifndef _FOL_UTILITY_
#define _FOL_UTILITY_

namespace fol {
    template<typename T>
    T exchange(T& l, const T& r) {
        T tmp = l;
        l = r;
        return tmp;
    }
    template<typename T>
    T& letmax(T& l, const T& r) {
        return l < r ? l = r : l;
    }
    template<typename T>
    T& letmin(T& l, const T& r) {
        return r < l ? l = r : l;
    }
}

#endif
