#include <ESP8266WiFi.h>
 
const char* ap = "redmi niraj";   // Your WiFi's access point name
const char* pass = "niraj123456"; // Your WiFi's password
int wifiStatus;
int connectStatus = 0;
bool ledState = false; // To track the blinking state of the LED
 
void setup() {
    pinMode(LED_BUILTIN, OUTPUT); // Configure the built-in LED as an output pin
    WiFi.begin(ap, pass); // Start connecting to the WiFi network
}
 
void loop() {
    wifiStatus = WiFi.status(); // Check the WiFi status

    if (wifiStatus == WL_CONNECTED) { 
        // When connected to WiFi
        digitalWrite(LED_BUILTIN, LOW); // Turn on the built-in LED (logic inverted)
        connectStatus = 1; // Update the connection status
    } else { 
        // When disconnected or detecting WiFi
        if (connectStatus != 0) { 
            // Reset connection status
            connectStatus = 0;
        }
        // Blink the built-in LED
        ledState = !ledState; // Toggle the LED state
        digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW); // Apply the toggle
        delay(500); // Adjust blinking speed (500 ms)
        return; // Skip the 1-second delay below to keep the blinking interval consistent
    }

    delay(1000); // Delay for 1 second
}
