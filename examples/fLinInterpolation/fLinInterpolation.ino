/**
 * @file fLinInterpolation.ino
 * @author Alexander Tonn
 * @brief In this example the function fLinInterpolation() is used to interpolate a value from a given array.
 * @brief The example is used to calculate the SoC of a 24V LiFePo4 battery.
 * @brief This function needs two arrays with the same size. The first array contains the x-values and the second array contains the y-values.
 * @brief Array is a part of Arduino.h --> https://github.com/janelia-arduino/Array 
 * ! Used Board: Arduino MEGA2560
 * ! Used Pins: 5V -> potentiometer -> analog Pin A0
 * @brief 
 * @version 1.0
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "atUtility.h"

atUtilities atUtil;

constexpr static  byte BAT_SOC_ARRAY_SIZE = 15;
Array <float, BAT_SOC_ARRAY_SIZE> aSocVoltage24 = {{20.0, 22.4, 24.0, 25.2, 25.6, 25.8, 26.0, 26.1, 26.2, 26.4, 26.6, 26.8, 27.0, 27.6, 29.2}};
Array <float, BAT_SOC_ARRAY_SIZE> aSoCPercentage = {{0.0, 5.0, 9.5, 14.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 99.0, 99.5, 100.0}};


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
}

void loop() {
  float fTemp = analogRead(A0);
  float fBatteryVoltage = atUtil.fmap(fTemp, 0.0, 1023.0, 20.0, 29.0);
  Serial.println("fBatteryVoltage: " + String(fBatteryVoltage));
  float fInterpolated = atUtil.fLinInterpolation(fBatteryVoltage, aSocVoltage24, aSoCPercentage);
  Serial.println("Interpolated Percentage: " + String(fInterpolated));
  delay(1000);
}