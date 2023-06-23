uint64_t uiMillis = 0; 

void setup() {
  Serial.begin(115200);
}

void loop() {
  myMillis(uiMillis);
  Serial.println(int(uiMillis));
}

// ########;
// my "millis()" Function;
// ########;
// My Own millis function because the basic millis() will overflow after 50 days;
// if you know that your MCU is running longer than 50 days you have to detect the overflow;
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
  else{
    uiMyMillis = uiMillis;
  }
}


// Function for saving the current system time in secods 
// this function is using myMillis function (see above) and is converting the milli seconds into seconds
uint32_t seconds(uint64_t uiMillis){
  myMillis(uiMillis);

  uint32_t uiElapsedSeconds = (uiMillis/1000);
  return uiElapsedSeconds;
}


