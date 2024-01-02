#ifndef AT_UTILITIES_H
#define AT_UTILITIES_H

#include <Arduino.h>
#include <Array.h>

class atUtilities
{
    private:

    public:

    enum class edgeType{
    RISING_EDGE,
    FALLING_EDGE
    };

    auto myMillis(uint64_t& uiMyMillis) -> void;

    auto functionTrigger(uint32_t &uiMillisOld, uint32_t uiTargetTime) -> bool;
    auto secondToMs(uint16_t uiS) -> uint16_t;
    auto fmap(float f, float fInputMin, float fInputMax, float fOutputMin, uint16_t fOutputMax) -> float;

    #include "edgeDetection.h"
    #include "interpolation.h"


};

#endif
