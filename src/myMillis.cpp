#include "atUtility.h"

/**
 * @brief enhanced millis() function for counting up to 584942417 years
 * ! could be necessary if you log events with millis and you dont want a reset after 49 days
 * ! This function is RAM intense! This function is for special use cases and is not replacing the original millis() function
 * @param uiMyMillis uint64_t for saving the millis, must be a static or global variable
 */
auto atUtilities::myMillis(uint64_t& uiMyMillis) -> void {
  uint32_t uiMillis = 0;
  constexpr static uint64_t MILLIS_MAX = 4294967295; // Max Value of millis
  uint64_t uiNewStartpoint = 0;     // This value will work as new start point for myMillis()
  uint16_t uiMultiplier = 0;


  uiMultiplier    = uiMyMillis / MILLIS_MAX;
  uiNewStartpoint = MILLIS_MAX * uiMultiplier; //calculating the multiplier which will calculate automatically

  uiMillis = millis();

  // if millis() < MyMillis, then add the millis onto my millis
  // max millis which could be saved with uint64t: 18446744073709551616 == 213503982334 days == 584942417 years
  if (uiMillis < 4320000000 && uiMyMillis >= uiNewStartpoint) {
     uiMyMillis = uiNewStartpoint + uiMillis;
  }
  else {
    uiMyMillis = uiMillis;
  }
}



