# Smart Blind Stick 🚶‍♂️

A microcontroller-based Smart Blind Stick using Arduino Uno and an ultrasonic sensor for real-time obstacle detection and audio-visual alerts.
## 📌 Features
- Obstacle detection using HC-SR04 ultrasonic sensor.
- Real-time distance measurement.
- Three-level warning system.
- Audio alerts using a passive buzzer.
- Visual alerts using an LED.
- Low-cost and portable design.

## 🛠️ Components
- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- Passive Buzzer
- LED
- 9V Battery
- Breadboard and Jumper Wires
- Walking Stick

## 🔌 Pin Connections

| Component | Arduino Pin |
|---|---|
| Ultrasonic TRIG | 9 |
| Ultrasonic ECHO | 8 |
| Buzzer | 7 |
| LED | 6 |
| VCC | 5V |
| GND | GND |

## ⚙️ Working Principle

The ultrasonic sensor measures the distance of nearby obstacles. Arduino processes the sensor data and activates the buzzer and LED according to the detected distance.

| Distance | Alert |
|---|---|
| Below 10 cm | Danger |
| Below 20 cm | Warning |
| Below 40 cm | Alert |
| 40 cm or more | No Alert |

## 🚀 Getting Started

### Prerequisites
- Arduino IDE
- Arduino Uno R3
- USB cable

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/faysalfahim10/Smart-Blind-Stick_Poject.git
   ```
2. Open the Arduino source code (`.cpp` file).
3. Connect Arduino Uno to your PC.
4. Connect the components according to the pin configuration.
5. Select Arduino Uno and the correct COM port.
6. Upload the code and test the device.

## 💻 Technologies
- Microcontroller-Based Embedded System
- Arduino
- Embedded C/C++
- Ultrasonic Sensing

## 🔮 Future Improvements
- Add multiple sensors for wider detection.
- Integrate GPS and GSM modules.
- Add a vibration motor for tactile feedback.
- Add an emergency button.
