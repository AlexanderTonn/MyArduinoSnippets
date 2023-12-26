// HOW TO CONVERT STRING TO CHAR ARRAY
// https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/tochararray/ 

void setup() {
  Serial.begin(9600);

  StringToChar();

}

void loop() {
  delay(1000);

}

void StringToChar(){
  String sExample = "Example";
  uint8_t uiStringLength = sExample.length() + 1; // +1 is important otherwise you will loose an char

  char cConvertedString[uiStringLength];
  sExample.toCharArray(cConvertedString, uiStringLength);

  Serial.print("cConvertedString = ");
  Serial.println(cConvertedString);
}