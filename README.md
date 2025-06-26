# Fire-Alarm-and-Extinguisher-System-project
# 🔥 Fire Alarm & Extinguisher System using Arduino UNO

A compact and efficient safety system built with Arduino UNO that detects fire using a flame sensor and instantly triggers both an alarm and a water pump to extinguish the fire automatically.

> 🚨 Built for safety. Designed for automation.

---

## 🌟 Project Overview

This project is an **automated fire detection and response system** that:
- Detects fire using a **Flame Sensor**
- Triggers a **Buzzer Alarm**
- Starts a **Water Pump** through a Relay
- Can be powered ON/OFF using a **Slide Switch**

Ideal for small rooms, kitchens, or labs to demonstrate early-stage fire control.

---

## 🎯 Features

- 🔥 Real-time Flame Detection
- 🚨 Instant Buzzer Alert
- 💧 Automatic Water Pump Activation
- 🎚️ Manual Slide Switch for Safety Control
- 🧠 Fully Programmable with Arduino UNO

---

## 🧰 Components Required

| 🔩 Component        | 🔢 Quantity |
|---------------------|-------------|
| Arduino UNO         | 1           |
| Flame Sensor        | 1           |
| Relay Module        | 1           |
| Water Pump (5V/9V)  | 1           |
| Buzzer              | 1           |
| Slide Switch        | 1           |
| 9V Battery          | 2           |
| Jumper Wires        | As needed   |
| Breadboard          | 1 (Optional)|

---

## 🛠️ Working Logic

1. System is powered ON using the slide switch.
2. Flame Sensor continuously checks for fire.
3. When fire is detected:
   - 🚨 Buzzer rings
   - ⚡ Relay triggers the pump
   - 💦 Water is sprayed automatically
4. Once fire is gone, system resets to monitoring mode.

---

## 🔌 Circuit Connections

| Device         | Arduino Pin |
|----------------|-------------|
| Flame Sensor   | A0          |
| Buzzer         | D8          |
| Relay Module   | D9          |
| Slide Switch   | VCC/GND     |

- Connect the water pump's power supply via the Relay.
- Make sure to use a diode (like 1N4007) across the relay coil for protection.

---

## 📷 Images / Diagrams

> _Add images or circuit diagram below:_

![circuit_diagram](./circuit_diagram.png)

---

## 💻 Code File

Upload the code using Arduino IDE:

```cpp
// fire_alarm_extinguisher.ino

const int flamePin = A0;
const int buzzerPin = 8;
const int relayPin = 9;

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int flameValue = analogRead(flamePin);
  
  if (flameValue < 100) { // Fire detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW);
  }
}
