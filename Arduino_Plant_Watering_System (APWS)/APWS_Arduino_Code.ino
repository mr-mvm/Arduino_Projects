// Pin Definitions
const int moistureSensorPin = A0; // Soil moisture sensor connected to A0
const int motorPin = 3;           // Motor connected to digital pin 3 (PWM)
const int lowerThreshold = 400;   // Lower threshold for moisture level to start pumping
const int upperThreshold = 500;   // Upper threshold to stop the motor

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the motor pin as output
  pinMode(motorPin, OUTPUT);
  
  // Start with the motor turned off
  digitalWrite(motorPin, LOW);
}

void loop() {
  // Read the value from the soil moisture sensor
  int moistureLevel = analogRead(moistureSensorPin);
  
  // Print the moisture level to the serial monitor
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);
  
  // If the moisture level is below the lower threshold, turn on the motor
  if (moistureLevel < lowerThreshold) {
    digitalWrite(motorPin, HIGH); // Turn on the motor
    Serial.println("Motor ON - Pumping Water");
  }
  // If the moisture level is above the upper threshold, turn off the motor
  else if (moistureLevel >= upperThreshold) {
    digitalWrite(motorPin, LOW);  // Turn off the motor
    Serial.println("Motor OFF - Soil Moisture Adequate");
  }
  
  // Delay for a short period to avoid too frequent readings
  delay(1000);
}
