# MazeTracer

MazeTracer is a tank-style Arduino-based maze-solving robot using three ultrasonic sensors, an OLED display, and a **left-hand rule** algorithm. 
It records visited coordinates and **displays the solved path**.

## 🚀 Features
- Left-hand rule maze solving
- OLED path visualization
- Coordinate logging
- Touch button start
- Display final solved path on an OLED display

## 🛠 Hardware Used
- Arduino Uno/Nano
- 3x Ultrasonic Sensors (HC-SR04)
- OLED Display (SSD1306)
- Motor Driver (L298N) + 2 DC Motors
- Capacitive Touch Button
- Power source (2 * 18650 cells , 1 * 9V Battery)
- Tank Style Chassis

## 📚 Libraries Used
- NewPing : https://docs.arduino.cc/libraries/newping/
- Adafruit GFX : https://github.com/adafruit/Adafruit-GFX-Library
- Adafruit BusIO : https://github.com/adafruit/Adafruit_BusIO
- Adafruit SSD306 : https://github.com/adafruit/Adafruit_SSD1306
- Custom Motor Library **(Files Included)**

## 🏗️ Build Instructions
- Clone the repo and open in PlatformIO IDE.
- Ensure `platformio.ini` is configured for your board (ESP32/Arduino Uno, etc.).
- Build and upload with one click!

## 📂 Code
All Arduino code is available in the `src/` folder.  
To run:  
1. Install the libraries.  
2. Upload the code to Arduino.  
3. Connect the sensors, display, and motors as per the circuit diagram **(Present inside Images Folder)**.

## 📖 Code Modules
- **Sensor.h / Sensor.cpp** – handles ultrasonic input
- **Motor.h / Motor.cpp** – motor control
- **Display.h / Display.cpp** – OLED display logic
- **Solver.h / Solver.cpp** – pathfinding and tracking

## 📸 Demo
Photos are present inside the images folder 

## 🔮 Future Improvements 
- Smarter pathfinding (Boundary Fill/Flood Fill).  
- Implement Bluetooth/Wifi logging to a mobile app.  
- 3D print a custom chassis for better stability.

## 👤 Author
Developed by Supreeth (12th grade project, 2025).  
