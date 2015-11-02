#ifndef SPH_SRC_PARAMETERS_HXX_
#define SPH_SRC_PARAMETERS_HXX_

#include "utility_math.h"

/**
template <typename T>
**/
public:
T GetGravity() const { return gravity; }
void SetGravity(const T new_gravity) {
  const T min = static_cast<T>(-9.8);
  const T max = static_cast<T>(9.8);
  gravity = Clamp<T>(new_gravity, min, max);
}
T GetDT() const { return dt; }
void SetDT(const T new_dt) { dt = new_dt; }

#endif
