#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "atUtility.h"

/**
 * @brief Interpolating a value based of the dataset of two float arrays
 * ! Consider that you have to pass two arrays with the same size 
 * 
 * @tparam T 
 * @param fx value to interpolate
 * @param aX array with x values
 * @param aY array with y values
 * @return float 
 */
template <size_t T>
auto fLinInterpolation (float fx, const Array<float, T>& aX, const Array<float, T>& aY) -> float
{
  static auto n = sizeof(aX) / 4;
  auto x1 = 0.0F, x2 = 0.0F; 
  auto y1 = 0.0F, y2 = 0.0F; 
  bool xLowRec = false, xUpperRec = false; // true, if lower/upper value was received

  // getting x1 && y1
  for (auto i = n; i > 0 && !xLowRec; i--)
  {
    if(fx >= aX[i])
    {
      x1 = aX[i];
      y1 = aY[i];
      xLowRec = true;
    }
  }
  // getting x2 && y2
  for (auto i = 0; i < n && !xUpperRec; i++)
  {
    if(fx <= aX[i])
    {
      x2 = aX[i];
      y2 = aY[i];
      xUpperRec = true;
    }
  }

  // All necesssary values collected, now calculate
  auto fResult = 0.0F;
  if(xLowRec && xUpperRec)
  {
    auto term1 = (fx - x1)/(x2 - x1);
    auto term2 = (y2 - y1);
    fResult = y1+term1*term2;
  }
  return fResult;
}
#endif // INTERPOLATION_H