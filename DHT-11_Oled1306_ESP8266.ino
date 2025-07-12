/*
 * ESP8266 with DHT11, SSD1306 OLED, and Blynk
 */
#define BLYNK_TEMPLATE_ID "TMPL3fibk1R2I"
#define BLYNK_TEMPLATE_NAME "temperature and humidity"
#define BLYNK_AUTH_TOKEN 
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial


// DHT Sensor Settings
#define DHTPIN 13     // GPIO2 (D4 on NodeMCU)
#define DHTTYPE DHT11

// OLED Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Blynk Authentication
char auth[] = "gr3z8ed8z1tig7s0XJrFHNk2Vudg7tw_"; // Replace with your Blynk auth token

// WiFi Credentials
char ssid[] = "BHATTI-2.4Ghz";
char pass[] = "msb2451920";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  
  // Initialize DHT sensor
  dht.begin();  

  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    while(1); // Halt if display fails
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Connecting to WiFi...");
  display.display();

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Connected!");
  display.display();
  delay(1000);
}

void loop() {
  Blynk.run(); // Run Blynk
  
  delay(2000); // Wait between measurements

  float humi = dht.readHumidity();     // Read humidity
  float tempC = dht.readTemperature(); // Read temperature in Celsius

  // Update OLED
  display.clearDisplay();
  
  if (isnan(humi) || isnan(tempC)) {
    display.setCursor(0, 0);
    display.println("Sensor Error!");
  } else {
    // Display temperature
    display.setCursor(0, 0);
    display.print("Temp: ");
    display.print(tempC);
    display.print(" ");
    display.write(167); // Degree symbol
    display.println("C");

    // Display humidity
    display.setCursor(0, 20);
    display.print("Humi: ");
    display.print(humi);
    display.println("%");

    // Send data to Blynk
    Blynk.virtualWrite(V0, tempC); // Virtual pin V0 for temperature
    Blynk.virtualWrite(V1, humi);  // Virtual pin V1 for humidity
  }
  
  display.display(); // Update OLED
}