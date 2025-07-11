
#include <cmath>
#include "MathFunctions.h"
#ifdef USE_MYMATH
#  include "Mysqrt.h"
#endif

namespace mathfunctions {

double sqrt(double x)
{
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
}

}
