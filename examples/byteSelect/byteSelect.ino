#include "atUtility.h"

atUtilities atUtil;

uint16_t uiTest = 0xE402;

void setup()
{
    Serial.begin(9600);

    byte by = atUtil.byteSelect16(atUtilities::bytePos::LOW_BYTE, uiTest);

    Serial.println("Low Byte: " + String(by));

    by = atUtil.byteSelect16(atUtilities::bytePos::HIGH_BYTE, uiTest);
    Serial.println("High Byte: " + String(by));
}

void loop()
{
}