# 🌡️ ESP8266 DHT11 Temperature & Humidity Monitoring

An IoT project using the **ESP8266** microcontroller and **DHT11 sensor** to measure **temperature and humidity**, with optional display support and cloud integration.

---

## 📌 Project Overview

This project reads **temperature and humidity data** from a **DHT11 sensor** connected to an **ESP8266** (NodeMCU), processes the readings, and makes them available for:

- Serial monitoring
- OLED display (SSD1306)
- Cloud logging (e.g., Google Sheets / IoT dashboards like Blynk)

The project is modular and easy to extend for real-world IoT use cases.

---

## 🧠 Features

- 📡 ESP8266 WiFi-enabled microcontroller
- 🌡️ Real-time temperature monitoring
- 💧 Real-time humidity monitoring
- 🖥️ Serial output for debugging
- 📊 Optional Google Sheets data logging
- 📺 Optional OLED (SSD1306) display support
- 🔌 Simple wiring and low power consumption

---

## 🧰 Hardware Requirements

- ESP8266 (NodeMCU / ESP-12)
- DHT11 Temperature & Humidity Sensor
- OLED Display (SSD1306) *(optional)*
- Breadboard & jumper wires
- USB cable

---

## 🧪 Software Requirements

- Arduino IDE
- ESP8266 Board Package
- Required libraries:
  - `DHT.h`
  - `ESP8266WiFi.h`
  - `Adafruit_GFX.h` *(for OLED)*
  - `Adafruit_SSD1306.h` *(for OLED)*

---

## 🔌 Wiring Connections

### DHT11 → ESP8266

| DHT11 Pin | ESP8266 Pin |
|----------|-------------|
| VCC | 3.3V |
| DATA | D4 (GPIO2) |
| GND | GND |

*(Pin can be changed in code if required)*

---
