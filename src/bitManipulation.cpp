#include "atUtility.h"

// checking whether the passed bitPosition is out of range of the variable
auto atUtilities::bitRangeCheck(uint8_t uiSize, byte byBitPos) -> bool
{
    switch (uiSize)
    {
    case 1:
        if (byBitPos > 7)
            return false;
        else
            return true;
        break;
    // uint16 or int16
    case 2:
        if (byBitPos > 15)
            return false;
        else
            return true;
        break;
    // uint32 or int32
    case 4:
        if (byBitPos > 31)
            return false;
        else
            return true;
        break;
    // uint64 or int64
    case 8:
        if (byBitPos > 63)
            return false;
        else
            return true;
        break;
        // uint8 or int8

    default:
        Serial.println("This Size is not programmed to check: " + String(uiSize));
        break;
    }
}