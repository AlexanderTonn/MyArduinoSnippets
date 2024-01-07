#ifndef AT_UTILITIES_H
#define AT_UTILITIES_H

#include <Arduino.h>
#include <Array.h>

class atUtilities
{
public:
    enum class edgeType
    {
        RISING_EDGE,
        FALLING_EDGE
    };
    enum class permission
    {
        READ,
        WRITE
    };
    enum class bytePos
    {
        LOW_BYTE,
        HIGH_BYTE
    };

    auto myMillis(uint64_t &uiMyMillis) -> void;

    auto functionTrigger(uint32_t &uiMillisOld, uint32_t uiTargetTime) -> bool;
    auto secondToMs(uint16_t uiS) -> uint16_t;
    auto fmap(float f, float fInputMin, float fInputMax, float fOutputMin, uint16_t fOutputMax) -> float;
    auto byteSelect16(bytePos pos, uint16_t uiInput) -> uint8_t;
    auto selectMultipleBits16(uint16_t uiInput, uint8_t uiStartBit, uint8_t uiEndBit) -> uint16_t;

private:
    auto bitRangeCheck(uint8_t uiSize, byte byBitPos) -> bool;

public:
#include "edgeDetection.h"
#include "interpolation.h"
#include "bitManipulation.h"
};

#endif
