/**
 * @file edgeDetection.ino
 * @author Alexander Tonn
 * @brief In this example the function edgeDetection() is used to detect the rising edge of an analog signal and falling edge of a boolean signal.
 * ! Used Board: Arduino MEGA2560 
 * ! Used Pins: 5V -> switch or button -> digital Pin 10
 * ! Used Pins: 5V -> potentiometer -> analog Pin A0
 * @version 1.0
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "atUtility.h"

bool xInput = false;
bool xEdgeDetectionResult1 = false; 
bool xEdgeDetectionResult2 = false;
bool xPreviousSignal;
uint16_t uiAnalogSignal = 0; 
uint16_t uiPreviousSignal = 0;

atUtilities atUtil;


void setup() {
  Serial.begin(9600);

  pinMode(10, INPUT);
  pinMode(A0, INPUT);


}


void loop() {

  // Function Trigger Example
  xInput = digitalRead(10);
  uiAnalogSignal = analogRead(A0);

  // For Edge detection of boolean signals you have to choose between LOW and HIGH (0 or 1)
  xEdgeDetectionResult1 = atUtil.edgeDetection(xInput, xPreviousSignal, atUtilities::edgeType::FALLING_EDGE, LOW );
  // 500 is the trigger value for the analog signal
  xEdgeDetectionResult2 = atUtil.edgeDetection(uiAnalogSignal, uiPreviousSignal, atUtilities::edgeType::RISING_EDGE, 500);

  Serial.print("Rising Edge BOOL: ");
  Serial.println(xEdgeDetectionResult1);

  Serial.print("Rising Edge ANALOG: ");
  Serial.println(xEdgeDetectionResult2);
  Serial.print("ANALOG Value: ");
  Serial.println(uiAnalogSignal);

  delay(500);
}