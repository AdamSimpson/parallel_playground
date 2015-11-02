#ifndef SPH_SRC_PARTICLES_HXX_
#define SPH_SRC_PARTICLES_HXX_

/**
template<typename T, int dim>
**/

public:
Particles(const Parameters<T>& parameters_,
          const int max_local_) : parameters{parameters_},
                                  max_count_local{max_local_},
                                  pos{hemi::Array< Vector<T, dim> >(max_count_local)},
                                  v{hemi::Array< Vector<T, dim> >(max_count_local)},
                                  density{hemi::Array<T>(max_count_local)} {

  // Initialize particle values
  for (int i=0; i<max_count_local; ++i) {
    v.writeOnlyPtr(hemi::host)[i] = Vector<T,dim>(0.0);
    pos.writeOnlyPtr(hemi::host)[i] = Vector<T,dim>(0.0);
    density.writeOnlyPtr(hemi::host)[i] = 0.0;
  }

}

void ApplyGravity() {
  const T g = parameters.GetGravity();
  const T dt = parameters.GetDT();

  hemi::parallel_for(0, local_count, [=] HEMI_LAMBDA (int i) {
      v.ptr(hemi::host)[i].y += g*dt;
  });

}

#endif
