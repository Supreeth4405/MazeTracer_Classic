# MazeTracer V0

MazeTracer V0 is an Arduino-based maze-solving robot developed during a competition. The robot uses three ultrasonic sensors and a left-hand rule algorithm to navigate unknown mazes while displaying its current actions on an OLED display.

## 📸 Model

![MazeTracer V0](Images/Front.jpg)

## 🚀 Features

* Left-hand rule maze-solving algorithm
* Three ultrasonic sensors for obstacle detection
* OLED status display
* Capacitive touch button start mechanism
* Autonomous decision making
* Automatic maze completion detection

## 🛠 Hardware Used

* Arduino Uno
* 3 × HC-SR04 Ultrasonic Sensors
* SSD1306 OLED Display
* L298N Motor Driver
* 2 × DC Motors
* Capacitive Touch Button
* Tank-style chassis

## 📚 Software & Libraries Used

### Arduino

* PlatformIO
* NewPing: https://docs.arduino.cc/libraries/newping/
* Adafruit GFX: https://github.com/adafruit/Adafruit-GFX-Library
* Adafruit SSD1306: https://github.com/adafruit/Adafruit_SSD1306

## 🏗️ Build Instructions

* Clone the repository and open the project in PlatformIO.
* Install the required libraries.
* Connect the hardware as shown in the images.
* Upload the code to the Arduino.

## 📂 Code

All source code is available inside the `src` folder.

The robot uses a simple left-hand rule algorithm for navigation and continuously monitors its surroundings using ultrasonic sensors.

## 📖 Code Modules

* **forward()** – Moves the robot forward
* **turnleft()** – Performs a left turn
* **turnright()** – Performs a right turn
* **backward()** – Handles dead ends
* **leftdistance()** – Reads the left ultrasonic sensor
* **centerdistance()** – Reads the center ultrasonic sensor
* **rightdistance()** – Reads the right ultrasonic sensor
* **solve()** – Main maze-solving logic

## 🖥️ OLED Display

The OLED display provides real-time status updates, including:

* Maze Solver startup screen
* Entering Maze
* Moving Forward
* Turning Left
* Turning Right
* Turning Back
* Maze Solved

## 📸 Demo

Photos of the original prototype are available in the `Images` folder.

The original hardware has since been dismantled, so videos of the system are not available.

## 🔮 Future Improvements

* Implement coordinate tracking
* Add path memory and replay functionality
* Upgrade to Flood Fill or Boundary Fill algorithms
* Improve turning accuracy using encoders
* Design a custom chassis

## 👤 Author

Developed by Supreeth (Competition Project, 2025).