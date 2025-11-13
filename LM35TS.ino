// LM35 Temperature Sensor Test 

const int sensorPin = A0;  // Analog input pin for LM35
float temperatureC;        // Variable to store °C

void setup() {
  Serial.begin(9600);
  Serial.println("LM35 Temperature Sensor Ready");
  Serial.println("---------------------------------");
}

void loop() {
  int sensorValue = analogRead(sensorPin);          // Read analog value (0–1023)
  float voltage = sensorValue * (5.0 / 1023.0);     // Convert to voltage (assume 5 V reference)
  temperatureC = voltage * 100.0;                   // 10 mV per °C  → multiply by 100
  Serial.println("voltage: ");
  Serial.println(voltage);
  Serial.print("Temperature: ");
  Serial.print(temperatureC, 1);  // one decimal place
  Serial.println(" °C");

  // --- Optional: enable plotting line ---
  Serial.println(temperatureC);

  delay(500);  // Update every 1 s
}
