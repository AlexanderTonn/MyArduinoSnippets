/* #### DOCUMENTATION
                            HOW TO WIRE:
|       Arduino      | CS / SS | SCK / CLK | MOSI / COPI | MISO / CIPO | 
| Uno                | 10      | 13        | 11          | 12          |
| Mega               | 53      | 52        | 51          | 50          |
| MKR WiFi 1010      | 7       | 9         | 8           | 10          |

##### TROUBLESHOOTING FINDINGS: SD init is failing
- play safe that power supply is constantly >=5V (in my case i increased my LM317 Circuit up to 5,1V)
- disconnect the power supply of Arduino if you debugging with USB Port
*/


// LIBS
#include <SD.h>   // https://www.arduino.cc/reference/en/libraries/sd/
#include <SPI.h>  // https://www.arduino.cc/reference/en/language/functions/communication/spi/

Sd2Card card;
SdVolume volume;
SdFile root;
SdFile file;

const byte byChipSelect = 53;  // SCK Pin. of Arduino MEGA
const uint32_t uiBaudrate = 230400;
uint32_t uiVolumesize = 0;

void setup() {

  // Opening Serial Port and wait until open
  Serial.begin(uiBaudrate);
  pinMode(byChipSelect, OUTPUT);

  sdInit();


}

void loop() {
  // put your main code here, to run repeatedly:

}


void sdInit(){
  Serial.println("Start to initialize SD Card");
  card.init();
  delay(100);
  volume.init(card);
  delay(100);
  root.openRoot(volume);
  delay(100);
  
  
  // Initialization of utility lib
  if (!card.init()) {
    Serial.println("Init failed...");
    Serial.println("Check Wiring!");
    Serial.println("SD Card present?");
    Serial.println("Is SDCard FAT32?");
    Serial.println("SPI-SS correct?");
    return;
  } else
    Serial.println("SD Card found and initialized");

  // Opening volume and Partition
  if(!volume.init(card)){
    Serial.println("FAT16/FAT32 Partition not found. Please format the SD Card!");
  }
  else{
    Serial.print("Volume Typ is: ");
    Serial.println(volume.fatType(),DEC);
  }

  // Calculate the Volumesize
  uiVolumesize = volume.blocksPerCluster();   // clusters are collections of blocks
  uiVolumesize *= volume.clusterCount();      // we'll have a lot of clusters
  uiVolumesize /= 2;                          // SD card blocks are always 512 bytes (2 blocks are 1KB)
  uiVolumesize /= 1024;
  Serial.print("Volume Size: ");
  Serial.print(uiVolumesize/1024);
  Serial.println("Gb");

  // List all Files on SD CArd 
  root.openRoot(volume);
  root.ls(LS_R | LS_DATE | LS_SIZE);  
}
