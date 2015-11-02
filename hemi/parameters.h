#ifndef SPH_SRC_PARAMETERS_H_
#define SPH_SRC_PARAMETERS_H_

template <typename T>
class Parameters {
  public:
    Parameters() : gravity{static_cast<T>(9.8)},
                   dt{static_cast<T>(0.01)} {};

  private:
    T gravity;
    T dt;

  #include "parameters.hxx"
};

#endif
