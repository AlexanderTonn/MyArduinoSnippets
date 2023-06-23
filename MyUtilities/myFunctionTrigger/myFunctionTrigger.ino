// ##############;
// my time based triggering;
// ##############;
// executing a function if specific time is elapsed;
// working with reference parameter (updating uiMillisOLd trough the function);
// you have to pass your old millis time and the target time;
// needs the myMillis function

void setup() {
  Serial.begin(115200);

  

}

void loop() {
  delay(1000);
  // TODO FOR ME: Add usage example with serial output!

}


bool functionTrigger(uint64_t &uiMillisOld, uint64_t uiTargetTime){
  uint64_t uiMillisActual = 0;
  myMillis(uiMillisActual);

  if(uiMillisActual - uiMillisOld >= uiTargetTime){
    myMillis(uiMillisOld);
    return true;
  }else {
    return false; 
  }
    
}

// i recommend using my own build "myMillis" function, because standard millis will overflow after 40 days and stuck 
void myMillis(uint64_t& uiMyMillis){
  uint32_t uiMillis=0;
  uint64_t uiMillisMax=4294967295;  // Max Value of millis
  uint64_t uiNewStartpoint=0;       // This value will work as new start point for myMillis()
  uint16_t uiMultiplier=0;


  uiMultiplier    = uiMyMillis/uiMillisMax;
  uiNewStartpoint = uiMillisMax*uiMultiplier;   //calculating the multiplier which will calculate automatically

  uiMillis = millis();

  // if millis() < MyMillis, then add the millis onto my millis
  // max millis which could be saved with uint64t: 18446744073709551616 == 213503982334 days
 
  if(uiMillis < 4320000000 && uiMyMillis >= uiNewStartpoint){
    uiMyMillis = uiNewStartpoint + uiMillis;
  }
    // my Millis counted up to 100 days
  else{
    uiMyMillis = uiMillis;
  }
}
