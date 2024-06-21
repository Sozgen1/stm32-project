# STM32-Based Smart Home System

This project is a smart home system implemented using the STM32 microcontroller. The system allows controlling LEDs and fans using buttons and measuring temperature.

## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributors](#contributors)
- [License](#license)

## Features
- **LED Control:** Turn LEDs on and off using buttons.
- **Fan Control:** Turn fans on and off using buttons.
- **Temperature Measurement:** Measure real-time temperature using a temperature sensor.

## Requirements
- STM32 microcontroller (e.g., STM32F103)
- Buttons
- LEDs
- Fans
- Temperature sensor (e.g., DS18B20)
- Breadboard and jumper wires
- STM32 development environment (e.g., STM32CubeIDE)
- ST-LINK/V2 programmer

## Installation
1. **Set Up the Development Environment:**
   - Download and install STM32CubeIDE or your preferred STM32 development environment.

2. **Clone the Project:**
   ```bash
   git clone https://github.com/username/smart-home-system.git
   cd smart-home-system
   
Connect the Hardware:

Connect the buttons, LEDs, fans, and temperature sensor to the STM32 microcontroller.
For connection schematics and details, refer to the docs/hardware_setup.md file.
Open the Project:

Open STM32CubeIDE and import the cloned project.
Build and Flash the Code:

Build the project and flash it to the STM32 microcontroller using the ST-LINK/V2 programmer.
Usage
Start the System:

Power up the microcontroller to start the system.
LED Control:

Press the corresponding button to turn the LEDs on and off.
Fan Control:

Press the corresponding button to turn the fans on and off.
Temperature Measurement:

The temperature sensor will automatically measure and display the temperature values on the screen or via the serial port.

smart-home-system/
├── docs/
│   ├── hardware_setup.md
│   └── project_description.md
├── src/
│   ├── main.c
│   ├── stm32f1xx_hal_conf.h
│   ├── stm32f1xx_it.c
│   ├── ...
├── include/
│   ├── main.h
│   ├── stm32f1xx_hal.h
│   ├── ...
├── README.md


