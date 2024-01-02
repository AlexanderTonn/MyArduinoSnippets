/**
 * @file fmap.ino
 * @author Alexander Tonn
 * @brief In this example the function fmap() is used to map a value from one range to another.
 * ! Used Board: Arduino MEGA2560
 * ! Used Pins: 5V -> potentiometer -> analog Pin A0
 * @version 1.0
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "atUtility.h"

atUtilities atUtil;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}


void loop() {
  float fTemp = analogRead(A0);
  float fScaled = atUtil.fmap(fTemp, 0.0, 1023.0, 0.0, 100.0); // Scaling the analog value from 0-1023 to 0-100
  Serial.println("Scaled Value: " + String(fScaled));
}
