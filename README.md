# Automated Smart Sericulture Using Embedded System

## Overview

This project presents an **automated sericulture system** that enhances silkworm rearing by monitoring and regulating environmental conditions using IoT and embedded systems. It aims to improve silk quality and yield while reducing the need for manual intervention.

## Table of Contents

- [Project Objectives](#project-objectives)
- [System Architecture](#system-architecture)
- [Key Features](#key-features)
- [Components Used](#components-used)
- [Setup and Installation](#setup-and-installation)
- [Calibration and Configuration](#calibration-and-configuration)
- [Results and Analysis](#results-and-analysis)
- [Future Scope](#future-scope)
- [References](#references)

## Project Objectives

- Monitor and control **temperature**, **humidity**, and **light intensity** for silkworm growth.
- Use an **ESP32** microcontroller for real-time processing and wireless communication.
- Enable remote access to data through **Wi-Fi** and **Firebase** cloud integration.
- Minimize labor and manual monitoring through automation.
- Improve silk productivity by maintaining optimal environmental conditions.

## System Architecture

The system consists of:

- **Sensors**: DHT22 (temperature & humidity), LDR (light).
- **Actuators**: Peltier module, cooling fan, sprayer, LED, water pump.
- **Controller**: ESP32 microcontroller.
- **Communication**: Wi-Fi (via ESP32) to Firebase.
- **Display**: 16x2 LCD for local environmental data.
- **Cloud**: Firebase for real-time remote monitoring and control.

## Key Features

- 📶 Wi-Fi-enabled real-time data sync with Firebase.
- 🌡️ Automated control of environmental parameters.
- 📊 LCD shows current readings on-site.
- 🌍 Remote monitoring via mobile/web dashboard.
- ♻️ Energy-efficient and scalable design.

## Components Used

| Component             | Description                                   |
|----------------------|-----------------------------------------------|
| ESP32                | Microcontroller with built-in Wi-Fi           |
| DHT22                | Temperature & Humidity Sensor                 |
| LDR                  | Light Intensity Sensor                        |
| 16x2 LCD             | Real-time display of sensor readings          |
| Peltier Module       | Temperature regulation                        |
| Cooling Fan          | Supports thermal control                      |
| Sprayer + Water Pump | Humidity control                              |
| Firebase             | Cloud database for monitoring                 |
| Power Supply         | 5V and 12V regulated supplies                 |

## Setup and Installation

1. Wire up all sensors and actuators to the ESP32 as per schematic.
2. Use the **Arduino IDE** to upload code (with required libraries).
3. Configure your **Firebase project** and Wi-Fi credentials in the code.
4. Monitor and control the setup via Firebase's web/mobile interface.

## Calibration and Configuration

- Define temperature, humidity, and light thresholds in the code.
- Calibrate sensors by comparing with standard instruments.
- Tune control logic for actuators to maintain optimal conditions.
- Validate real-time data flow to Firebase.

## Results and Analysis

- **Energy Efficient**: Operates only when environmental deviations occur.
- **Improved Yield**: Stable environment boosts cocoon and silk quality.
- **Low Maintenance**: Minimal manual intervention required after setup.

## Future Scope

- Build a full-fledged rearing enclosure with integrated automation.
- Add silkworm tracking, disease detection, and AI-driven alerts.
- Develop a user-friendly mobile dashboard for remote control.
- Integrate solar energy for off-grid sustainability.
- Expand system to other precision agriculture applications.

## References

Refer to the project documentation for detailed technical references and citations.

---

**Author**  
- Mayiel Raja Sundar B  

**Supervisor**  
- Mr. S. Palanivel, M.E.  

**Institution**  
Vel Tech Multi Tech Dr. Rangarajan Dr. Sakunthala Engineering College  
Affiliated to Anna University, Chennai
