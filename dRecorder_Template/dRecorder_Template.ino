#include <SD.h> //Load SD card library
#include<SPI.h> //Load SPI Library
 
 
#include "Wire.h"    // imports the wire library for talking over I2C 
#include "Adafruit_BMP085.h"  // import the Pressure Sensor Library We are using Version one of Adafruit API for this sensor
 
 
float data1;  // Variable 
float data2;  // Variable 
float data3; //Variable 
 
int chipSelect = 53; //chipSelect pin for the SD card Reader
File mySensorData; //Data object you will write your sesnor data


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(53, OUTPUT); //Must declare 10 an output and reserve it
SD.begin(10);

}

void loop() {
  // put your main code here, to run repeatedly:
// variables or calculations
mySensorData = SD.open("PTData.txt", FILE_WRITE);

if (mySensorData) {
Serial.print("The Temp is: "); //Print Your results
//Serial.print(tempF);
//Serial.println(" degrees F");
//Serial.print("The Pressure is: ");
//Serial.print(pressure);
//Serial.println(" Pa.");
//Serial.println("");
delay(250); //Pause between readings.
 
 
mySensorData.print(data1);                             //write temperature data to card
mySensorData.print(",");                               //write a commma
mySensorData.println(data2);                        //write pressure and end the line (println)
mySensorData.close();                                  //close the file


}
