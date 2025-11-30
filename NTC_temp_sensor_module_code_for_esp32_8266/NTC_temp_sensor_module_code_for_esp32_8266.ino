#include <Arduino.h>

const int sensorPin = A0;  // KY-013 connected to analog pin A0
const float B = 3950;      // Beta coefficient (varies by thermistor model)
const float R0 = 10000;    // Resistance at 25°C (varies by thermistor model)
const float T0 = 298.15;   // Reference temperature in Kelvin (25°C)

void setup() {
    Serial.begin(115200);
}

void loop() {
    int sensorValue = analogRead(sensorPin);
    float voltage = sensorValue * (3.3 / 1023.0);
    float resistance = (R0 * voltage) / (3.3 - voltage); // Calculate thermistor resistance

    // Apply Steinhart-Hart equation
    float tempKelvin = 1.0 / ((1.0 / T0) + (1.0 / B) * log(resistance / R0));
    float temperatureCelsius = tempKelvin - 273.15; // Convert to Celsius

    Serial.print("Temperature: ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");

    delay(1000); // Wait for a second
}