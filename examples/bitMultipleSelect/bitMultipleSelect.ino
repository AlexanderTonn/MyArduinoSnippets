#include "atUtility.h"

atUtilities atUtil;

uint16_t uiTest = 0xE4;

void setup()
{
    Serial.begin(9600);

    uint16_t uiResult = atUtil.selectMultipleBits16(uiTest, 0, 6);
    Serial.println("Result: " + String(uiResult));
}

void loop()
{
}