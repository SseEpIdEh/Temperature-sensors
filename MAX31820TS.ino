#include <OneWire.h> //Install OneWire in the library
#include <DallasTemperature.h> // Install DallasTemperature in the library

// Data wire connected to digital pin 2
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();   // Start the sensor
  Serial.println("MAX31820 Temperature Sensor Ready");
}

void loop() {
  sensors.requestTemperatures();  // Request temperature from the sensor
  
  // Read temperature in Celsius and Fahrenheit
  float tempC = sensors.getTempCByIndex(0);
  float tempF = sensors.getTempFByIndex(0);

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" °C  |  ");
  Serial.print(tempF);
  Serial.println(" °F");
  

  delay(000);  // Update every second
}
