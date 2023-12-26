// How to use Strtok for converting String to char array
// please consider that the Variable which used for strtok have to be pointer chars!

void setup() {
  Serial.begin(9600);

  using_Strtok();

}

void loop() {
  delay(1000);
  // put your main code here, to run repeatedly:

}


void using_Strtok(){
  char cExample [] = "uiExampleVar=1337";
  char *cName = strtok(cExample,"=");

  // Read until the equal sign
  if(cName){
    Serial.print("cName = ");
    Serial.println(cName);

    // If cName is valid, strtok the remaining chars
    char *cValue = strtok(NULL," ");
    if(cValue){
      Serial.print("cValue = ");
      Serial.println(cValue);
    }
  }

}
