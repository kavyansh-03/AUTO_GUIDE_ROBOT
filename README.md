# 🤖 AUTO_GUIDE_ROBOT

AUTO_GUIDE_ROBOT is an Arduino-based obstacle avoidance robot that uses an ultrasonic sensor, a servo motor, and an L298N motor driver to move autonomously without colliding with obstacles. The robot constantly measures the distance in front using the HC-SR04 ultrasonic sensor. When an obstacle is detected, it stops, scans its surroundings by rotating the sensor left and right using the servo motor, and then decides to turn in the direction with more free space. This simple yet effective logic allows the robot to navigate its environment smoothly.

## 📌 Project Description

The robot is built on a two-wheel drive chassis powered by BO motors, with motor speed controlled through the L298N motor driver. An Arduino Uno serves as the brain of the robot, processing sensor data and controlling motor movements. The servo motor holds the ultrasonic sensor and allows it to rotate, enabling the robot to compare left and right distances before making a navigation decision. If the path ahead is clear, the robot moves forward. If an obstacle is within 30 cm, the robot stops, moves slightly backward, scans left and right, and then turns toward the safer direction before resuming forward motion. This approach ensures that the robot reacts dynamically to its environment in real time.

## 🔧 Hardware Requirements

- Arduino Uno  
- L298N Motor Driver  
- 2 × BO/DC Motors + Wheels  
- HC-SR04 Ultrasonic Sensor  
- SG90 Servo Motor  
- Robot Chassis with Caster Wheel  
- Battery Pack (7.4V–12V depending on motors)  
- Jumper wires and connectors  

## ⚡ Circuit Connections

**Motor Driver (L298N → Arduino):**  
- ENA → Pin 6  
- IN1 → Pin 7  
- IN2 → Pin 2  
- ENB → Pin 3  
- IN3 → Pin 5  
- IN4 → Pin 4  

**Ultrasonic Sensor (HC-SR04 → Arduino):**  
- VCC → 5V  
- GND → GND  
- Trig → Pin 8  
- Echo → Pin 9  

**Servo Motor (SG90 → Arduino):**  
- VCC → 5V (or IOREF)  
- GND → GND  
- Signal → Pin 11  

⚠️ Note: Make sure all grounds (Arduino, motor driver, servo, battery) are connected together.

## 💻 Software

The code is written in Arduino IDE using the Servo library. It consists of functions to control motor movement, measure distances with the ultrasonic sensor, and scan the surroundings with the servo. The main loop checks for obstacles and decides whether to move forward or change direction based on sensor readings.  

## ▶️ Usage

Clone the repository, open the Arduino sketch in Arduino IDE, select your board and COM port, and upload the code. Power the robot with a suitable battery pack and place it on the ground. The robot will automatically move forward and avoid obstacles using its sensors and motor control system.  

## 🚀 Future Improvements

In future versions, additional sensors like IR modules can be added for line following, Bluetooth or WiFi modules can enable remote control, and advanced algorithms can be implemented for path planning. Its various applications are self-driving cars, Rescue Operations, Service Robots, etc.

## 📜 License

This project is licensed under the MIT License.  

## 👨‍💻 Author

Developed by **[Kavyansh Pandya]**
