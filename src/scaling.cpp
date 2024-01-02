#include "atUtility.h"
/**
 * @brief scaling a float value from one range to another
 * ! If you have a int value, please use the map() function from official Arduino library (syntax is the same)
 * @param f value to scale
 * @param fInputMin minimum value of input range
 * @param fInputMax maximum value of input range
 * @param fOutputMin minimum value of output range
 * @param fOutputMax maximum value of output range
 * @return float
 */
auto atUtilities::fmap(float f, float fInputMin, float fInputMax, float fOutputMin, uint16_t fOutputMax) -> float
{
  return fOutputMin + (f - fOutputMin) * ((fOutputMax - fOutputMin) / (fInputMax - fInputMin));
}