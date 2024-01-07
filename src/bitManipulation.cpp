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

/**
 * @brief Selecting the Low or High Byte of a uint16_t variable
 * 
 * @param pos enum class bytePos, can be bytePos::LOW_BYTE or bytePos::HIGH_BYTE
 * @param uiInput Insert here the uint16_t variable
 * @return uint8_t 
 */
auto atUtilities::byteSelect16(bytePos pos, uint16_t uiInput) -> uint8_t
{
    switch (pos)
    {
    case bytePos::LOW_BYTE:
        return uiInput & 0xFF;
        break;
    case bytePos::HIGH_BYTE:
        return (uiInput >> 8) & 0xFF;
        break;
    default:
        return 0xFF;
        break;
    }
}
/**
 * @brief Selecting a bit range of a uint16_t variable
 * 
 * @param uiInput Insert here the uint16_t variable
 * @param uiStartBit Start bit position of the bit range
 * @param uiEndBit End Bit position of the bit range
 * @return uint16_t 
 */
auto atUtilities::selectMultipleBits16(uint16_t uiInput, uint8_t uiStartBit, uint8_t uiEndBit) -> uint16_t
{
    if(!bitRangeCheck(sizeof(uiInput), uiStartBit) || !bitRangeCheck(sizeof(uiInput), uiEndBit))
    {
        Serial.println("Error: Bitposition is out of range!");
        return 0; 
    }
    else 
    {
        // Create a bitmask with the length of the bit range 
        uint16_t mask = ((1U << (uiEndBit - uiStartBit + 1)) - 1) << uiStartBit;
        // shift the mask to the right position and return the value
        uint16_t uiOutput = (uiInput & mask) >> uiStartBit;
        return uiOutput;
    }
}