#include "atUtility.h"

/**
 * @brief
 *
 * @tparam T1
 * @tparam T2
 * @tparam T3
 * @param TinputSignal
 * @param TpreviousSignal
 * @param Type
 * @param Ttrigger
 * @return true
 * @return false
 */
template<typename T1, typename T2, typename T3 >
auto atUtilities::edgeDetection (T1 TinputSignal, T2 &TpreviousSignal, edgeType Type, T3 Ttrigger ) -> bool {
  // RISING EDGE detection
  switch(Type)
  {
    case edgeType::RISING_EDGE :
    if (TinputSignal >= Ttrigger && TpreviousSignal < Ttrigger ) {
      TpreviousSignal = TinputSignal;
      return true;
    }
    // Resetting the signal if Ttrigger was reached
    else if ((TinputSignal >= Ttrigger && TpreviousSignal >= Ttrigger)
          || (TinputSignal < Ttrigger && TpreviousSignal >= Ttrigger)) {
      TpreviousSignal = TinputSignal;
      return false;
    }else
      return false;
    break;

    case edgeType::FALLING_EDGE :
    if (TinputSignal <= Ttrigger && TpreviousSignal > Ttrigger) {
      TpreviousSignal = TinputSignal;
      return true;
    }
    else if ((TinputSignal <= Ttrigger && TpreviousSignal <= Ttrigger) || (TinputSignal > Ttrigger && TpreviousSignal <= Ttrigger)) {
      TpreviousSignal = TinputSignal;
      return false;
    }
    else
      return false;
    break;

    default:
    Serial.println("Error: No edge type defined");
    break;

  }

}
