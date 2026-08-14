# Smart Fan Controller

## Goal
An energy-efficient fan controller that only activates when needed — when
a room is both occupied and too hot/humid — instead of running on a fixed
schedule or manual switch.

## How it works

- *DHT11/DHT22 sensor* (pin 2) reads ambient temperature and humidity
- *PIR motion sensor* (HC-SR501, pin 4) detects human presence in the
  room
- *Relay* (pin 7) switches the fan on/off
- The fan turns ON only when *both* conditions are met:
  - Temperature > 28.0 °C *or* humidity > 70.0 % (adjustable thresholds)
  - *and* presence is detected by the PIR sensor
- If either condition is false, the fan stays OFF — avoiding wasted
  energy when the room is empty
- Sensor read errors (DHT disconnected or misread) are detected and
  logged instead of crashing the loop

## Code

→ [View source code](smart_fan_controller.ino)

## Simulation

→ [Try it live on Wokwi](https://wokwi.com/projects/472288713683827713)

Tested and validated in simulation: the fan stays OFF when only one
condition is met (e.g. high humidity without presence), and switches ON
only when both temperature/humidity threshold AND presence are true —
confirming the intended dual-condition logic works correctly.

## Hardware
- Arduino Uno (ATmega328P)
- DHT11 or DHT22 temperature/humidity sensor
- HC-SR501 PIR motion sensor
- Relay module (to switch the fan)
- Fan (AC or DC, depending on relay rating)

## Wiring
| Component | Pin |
|---|---|
| DHT11/DHT22 signal | D2 |
| PIR sensor OUT | D4 |
| Relay IN | D7 |

## Status
- [x] Core logic written (temperature/humidity + presence detection)
- [x] Logic validated in simulation (Wokwi) — confirmed correct behavior:
      fan activates only when both heat/humidity AND presence are detected
- [ ] Physical prototype and wiring test
- [ ] Calibration of PIR sensitivity and DHT thresholds in real conditions

## Tools
Arduino IDE · Wokwi · C++ (Arduino framework) · DHT sensor library
