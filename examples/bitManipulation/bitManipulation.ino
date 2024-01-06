/**
 * @file bitManipulation.ino
 * @author Alexander Tonn 
 * @brief In this example the function bitManipulation() is used to read and write a bit of a variable.
 * ! Used Board: Arduino MEGA2560
 * ! Used Pins: none 
 * @brief Please consider that you only can pass integer values to the function.
 * @version 1.0
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "atUtility.h"

uint16_t uiTestVar = 2354; 

atUtilities atUtil;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Hello World");

  // Try to read out of range;
  Serial.println(atUtil.bitManipulation(atUtilities::permission::READ, uiTestVar, 17, false));

  // reading a in Range bit: 
  Serial.println(atUtil.bitManipulation(atUtilities::permission::READ, uiTestVar, 2, false));

  // writing a bit:
  atUtil.bitManipulation(atUtilities::permission::WRITE, uiTestVar, 4, false);
  Serial.println(uiTestVar);

}

void loop() 
{

}