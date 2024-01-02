/**
 * @file myMillis.ino
 * @author Alexander Tonn
 * @brief In this example the function myMillis() is used to get the current time in milliseconds.
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

// Edge Detection Test Variables
bool xEdgeDetectionResult1 = false;
bool xEdgeDetectionResult2 = false;

// MyMillis Variable
uint64_t uiMillis = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // My Millis Example
  atUtil.myMillis(uiMillis);
  Serial.println(int(uiMillis));
}
