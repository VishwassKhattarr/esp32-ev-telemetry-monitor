#include <Arduino.h>

namespace {

constexpr uint8_t kBatteryVoltageAdcPin = 34;
constexpr uint32_t kSerialBaudRate = 115200;
constexpr uint32_t kSampleDelayMs = 500;

}  // namespace

void setup() {
    Serial.begin(kSerialBaudRate);

    pinMode(kBatteryVoltageAdcPin, INPUT);
    analogReadResolution(12);

    Serial.println();
    Serial.println("ESP32 EV Telemetry Monitor");
    Serial.println("Phase 1: Raw ADC acquisition");
}

void loop() {
    const int rawAdcValue = analogRead(kBatteryVoltageAdcPin);

    Serial.print("Battery ADC raw: ");
    Serial.println(rawAdcValue);

    delay(kSampleDelayMs);
}