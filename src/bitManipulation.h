#include "atUtility.h"

// 
/**
 * @brief Read or Set a bit of a integer variable
 * ! The counting of the bitpositions is starting with index 0 
 * ! (0-7 for uint8_t, 0-15 for uint16_t, 0-31 for uint32_t, 0-63 for uint64_t)
 * @tparam tVar 
 * @param p enum class permission, can be READ or WRITE
 * @param input can be any integer variable
 * @param byBitPos Position of the bit that should be read or set
 * @param x true or false if permission::WRITE is selected
 * @return true 
 * @return false 
 */
template <typename tVar>
auto bitManipulation (permission p, tVar &input, byte byBitPos, bool x ) -> bool
{
  auto size = sizeof(input);
  if(!bitRangeCheck(size, byBitPos))
  {
    Serial.println("Error: Bitposition is out of range!");
    return false; 
  }
  else 
    {
        switch (p)
        {
        case atUtilities::permission::READ : 
        return (input >> byBitPos) & 1UL;
        break;
        
        case atUtilities::permission::WRITE : 
        if (x)
            input |= 1UL << byBitPos; // set bit to 1
        else 
            input &= ~(1UL << byBitPos); // Set Bit to 0
        break;
    
        default: 
        Serial.println("No valid permission option!");
        break;
        }
    }
}