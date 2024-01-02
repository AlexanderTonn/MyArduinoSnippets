#include "atUtility.h"

/**
 * @brief Triggering functions with a certain time interval
 * ! Max Targettime: about 49 days
 * Can also handle a overflow of millis()
 * @param uiMillisOld separate uint32_t which is storing the old millis() value 
 * @param uiTargetTime trigger time interval in ms
 * @return true if target time is reached
 * @return false if target time is not reached
 */
auto atUtilities::functionTrigger(uint32_t &uiMillisOld, uint32_t uiTargetTime) -> bool {

  uint16_t uiMillisTemp = millis() - uiMillisOld;

  if (uiMillisTemp >= uiTargetTime) {
    uiMillisOld += uiTargetTime;
    return true;
  } else {
    return false;
  }
}

