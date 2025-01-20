// Time of Flight Sensor testing
// Calico Rose
// January 20, 2025

#include <Arduino.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X TOFS = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);

  while(!Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!TOFS.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  Serial.println("Time of Flight sensor booted.");
  // if(!TOFS.begin()) {
  //   Serial.println(F("Failed to boot Time of Flight sensor."));
  //   while(1);
  // }
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  TOFS.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println("Out of range");
  }
    
  delay(100);
}