# ESP32 EV Telemetry and Fault Monitoring System

An ESP32-based embedded system for monitoring simulated electric vehicle parameters, detecting unsafe operating conditions, and reporting telemetry and faults.

> **Status:** In Progress  
> The initial version is being developed and tested using Wokwi simulation before physical hardware validation.

## Problem Statement

Electric vehicles must continuously monitor parameters such as battery voltage, battery temperature, and motor speed. Unsafe values may indicate abnormal operation or potential component failure.

This project develops modular ESP32 firmware that:

- Acquires simulated vehicle telemetry.
- Converts raw sensor readings into physical values.
- Detects predefined fault conditions.
- Reports telemetry and faults through UART.
- Activates a warning output when a fault occurs.

This is an educational prototype and is not intended to replace a production Battery Management System or motor controller.

## Planned Features

- ADC-based battery-voltage monitoring
- ADC-based temperature monitoring
- ADC-based motor-speed monitoring
- Conversion of raw ADC readings into volts, degrees Celsius, and RPM
- Low-battery detection
- Over-temperature detection
- Motor-overspeed detection
- UART telemetry and fault reporting
- PWM-controlled warning LED
- Non-blocking periodic sampling
- Modular Embedded C++ implementation

## System Architecture

```text
Simulated Sensors
        |
        v
    ESP32 ADC
        |
        v
Signal Conversion
        |
        v
Fault Monitoring Logic
        |
        +------------------+
        |                  |
        v                  v
UART Telemetry       PWM Warning LED
```

The firmware is organized into three logical layers:

1. **Input layer:** Reads raw values through the ESP32 ADC channels.
2. **Monitoring layer:** Converts measurements and evaluates faults.
3. **Application layer:** Reports telemetry and controls the warning output.

## Monitored Parameters

| Parameter | Simulated Range | Initial Fault Condition |
|---|---:|---|
| Battery voltage | 35-55 V | Below 42 V |
| Battery temperature | 20-100 °C | Above 60 °C |
| Motor speed | 0-7000 RPM | Above 5000 RPM |

These values are initially selected for simulation and will be configurable within the firmware.

## System States

The initial state model supports:

- `NORMAL`
- `LOW_BATTERY`
- `OVER_TEMPERATURE`
- `OVER_SPEED`

The state is evaluated during every sampling cycle. The system returns to `NORMAL` when all parameters return to their safe ranges.

## Technology Stack

- ESP32
- Embedded C++
- Arduino framework
- PlatformIO
- ADC
- UART
- PWM
- Wokwi
- Git and GitHub

## Design Choices

### Embedded C++

Embedded C++ provides low-level access to ESP32 peripherals while supporting modular functions, constants, and strongly typed system states.

### ADC-Based Simulation

Potentiometers initially simulate analog vehicle sensors. This allows the telemetry-processing and fault-detection logic to be tested without requiring real EV hardware.

### UART Telemetry

The ESP32's built-in UART peripheral sends readings and fault information to a serial monitor. UART is simple, widely supported, and useful for embedded-system debugging.

### PWM Warning Output

A PWM-controlled LED provides local fault indication. Future versions can use different brightness levels or blinking patterns to represent fault severity.

### Non-Blocking Sampling

Timestamp-based scheduling will be used instead of blocking `delay()` calls. This keeps the main loop available for communication and future functionality.

## Planned Directory Structure

```text
esp32-ev-telemetry-monitor/
├── README.md
├── LICENSE
├── .gitignore
├── platformio.ini
├── src/
│   └── main.cpp
├── include/
│   ├── telemetry.h
│   └── fault_monitor.h
├── docs/
│   ├── architecture.md
│   ├── circuit-diagram.png
│   └── test-cases.md
└── simulation/
    ├── diagram.json
    └── wokwi.toml
```

## Development Roadmap

- [ ] Configure the ESP32 development environment
- [ ] Implement ADC input acquisition
- [ ] Convert ADC readings into physical values
- [ ] Implement fault thresholds and system states
- [ ] Add UART telemetry output
- [ ] Add PWM warning indication
- [ ] Create the Wokwi circuit simulation
- [ ] Document test cases and results
- [ ] Refactor peripheral access into modular components
- [ ] Validate the design using physical hardware

## Planned Test Cases

- All parameters within safe ranges
- Battery voltage below the minimum threshold
- Temperature above the maximum threshold
- Motor speed above the maximum threshold
- Multiple unsafe readings occurring simultaneously
- Values exactly at the configured thresholds
- Recovery after parameters return to safe values

## Future Improvements

- Sensor calibration
- Moving-average noise filtering
- Fault hysteresis
- Multiple simultaneous fault flags
- Persistent fault logging
- CAN bus communication
- FreeRTOS task separation
- Watchdog and fail-safe behaviour
- Physical ESP32 and sensor validation

## Disclaimer

This project is under active development. Current thresholds and sensor ranges are intended for simulation and educational purposes only.

## Author

**Vishwas Khattar**  
B.E. Computer Engineering  
Thapar Institute of Engineering and Technology  
Expected Graduation: 2027
