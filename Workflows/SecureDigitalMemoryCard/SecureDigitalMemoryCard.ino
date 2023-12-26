/* #### DOCUMENTATION
                            HOW TO WIRE:
|       Arduino      | CS / SS | SCK / CLK | MOSI / COPI | MISO / CIPO | 
| Uno                | 10      | 13        | 11          | 12          |
| Mega               | 53      | 52        | 51          | 50          |
| MKR WiFi 1010      | 7       | 9         | 8           | 10          |

Check my wiki for more informations: https://github.com/AlexanderTonn/MyArduinoSnippets/wiki/SD-Card 
*/


// LIBS
#include <SD.h>   // https://www.arduino.cc/reference/en/libraries/sd/
#include <SPI.h>  // https://www.arduino.cc/reference/en/language/functions/communication/spi/

//Instances of SD Lib
Sd2Card card;
SdVolume volume;
SdFile root;

// Variables vor initializing
bool xInitiated = false;              // global Status whether SD Card present
const byte byChipSelect = 53;         // SCK Pin. of Arduino MEGA
uint32_t uiBaudrate = 230400;
uint32_t uiVolumesize = 0;

// Variables for read/write files
// Consider the 8.3 Format rules for naming files!
String sFile = "EXAMPLE.TXT";             // File without Dir
String sFileDir = "/DAT/EXAMPLE.TXT";      // File with Dir

void setup() {

  // Opening Serial Port and wait until open
  Serial.begin(uiBaudrate);
  pinMode(byChipSelect, OUTPUT);

  xInitiated = sdInit();
  sdInitFiles(xInitiated);
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Initializing SD Card, return true if successfull
bool sdInit(){
  SD.begin(byChipSelect);
  Serial.println("Start to initialize SD Card");
  card.init();
  delay(100);
  volume.init(card);
  delay(100);
  
  
  // Initialization of utility lib
  if (!card.init()) {
    Serial.println("Init failed...");
    Serial.println("Check Wiring!");
    Serial.println("SD Card present?");
    Serial.println("Is SDCard FAT32?");
    Serial.println("SPI-SS correct?");
    return false;
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
  Serial.println("Existing files after finishing SD Init");
  root.openRoot(volume);
  root.ls(LS_R | LS_DATE | LS_SIZE);

  return true;
}

// Function for initializing the needed directorys and files.
// if the SD init is successfull (see passed "xInitiated") the root path will check whether dirs & and files are existing
void sdInitFiles(bool xInitiated){

  if (xInitiated == true){

    // Create File in root path
    if(!SD.exists(sFile)){
      File file = SD.open(sFile, FILE_WRITE);
      if(file){
        Serial.println("Create file EXAMPLE.TXT");
        file.close();
      }
      else
        Serial.println("Creating file failed");
    }

    //Create File in Directory
    if(!SD.exists("DAT")){
      SD.mkdir("DAT");
      File file = SD.open(sFileDir, FILE_WRITE);
      if(file){
        Serial.println("Create File EXAMPLE.TXT in Directory DAT");
        file.close();
      }else
      Serial.println("Creating file failed");
    }

  // Check in Serial Output whether all files & dirs created
  Serial.println("Existing files after finishing FILE init");
  root.ls(LS_R | LS_DATE | LS_SIZE);
  }
}