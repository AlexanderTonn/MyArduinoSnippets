/**
 * @file myFunctionTrigger.ino
 * @author Aleander Tonn
 * @brief In this example the function functionTrigger() is used to trigger a function every 1000ms.
 * ! Used Board: Arduino MEGA2560
 * ! Used Pins: none
 * @version 1.0
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "atUtility.h"

atUtilities atUtil;

uint32_t uiMillisOld1 = 4294967230; // example for showing a overflow of millis()
uint32_t uiMillisOld2 = 0;

bool xFunctionTrigger1 = false;
bool xFunctionTrigger2 = false;


void setup() {
  Serial.begin(9600);
}

void loop() {

  // Function Trigger Example

  xFunctionTrigger1 = atUtil.functionTrigger(uiMillisOld1, 1000);
  xFunctionTrigger2 = atUtil.functionTrigger(uiMillisOld2, 1000);
  Serial.println("millis = " + String(millis()) + "xFunctionTrigger1: " + String(xFunctionTrigger1));
  Serial.println("millis = " + String(millis()) + "xFunctionTrigger2: " + String(xFunctionTrigger2));
}
