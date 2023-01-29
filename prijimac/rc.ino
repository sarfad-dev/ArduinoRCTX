//vysilac
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <RCSwitch.h>
#include <ArduinoJson.h>

RCSwitch vysilac = RCSwitch();

#define BME280_ADRESA (0x76)
Adafruit_BME280 bme;

void setup() {
bme.begin(BME280_ADRESA);
vysilac.enableTransmit(10);
vysilac.setProtocol(2);
Serial.begin(9600);
}

void loop() {


  float temperature = bme.readTemperature() * 10 ;
  float hummidity = bme.readHumidity() * 10;
  float pressure = bme.readPressure() / 10;
  vysilac.send(temperature, 24);
  vysilac.send(hummidity, 32);
  vysilac.send(pressure, 16);
  Serial.println(temperature);
  Serial.println(hummidity);
  Serial.println(pressure);
  

  delay(1000);



}
