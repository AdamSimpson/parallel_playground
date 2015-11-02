#ifndef SPH_SRC_UTILITY_MATH_H_
#define SPH_SRC_UTILITY_MATH_H_

template<typename Util_T>
Util_T Clamp(Util_T n, Util_T lower, Util_T upper) {
  return n <= lower ? lower : n >= upper ? upper : n;
}

#endif
