#include <Wire.h>
#include <avr/wdt.h>

#define SLAVE_ADDRESS 0x69

char statusCode = 'N'; // Default status: 'N' for None/Neutral
int sensorReading = 420; // Example data the slave might hold
int ledPin = PIN_PB2; // use the bitmasked enum names instead of numbers
int maxBrightness = 100; // 0 - 255
volatile bool ledShouldBlink = false;
unsigned long ledOnTime = 0;
unsigned long ledOnLength = 1000;
volatile bool shouldReboot = false;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(SDA, INPUT_PULLUP);
  pinMode(SCL, INPUT_PULLUP);
  // Initialize as I2C slave
  Wire.begin(SLAVE_ADDRESS);
  
  // Define callbacks
  Wire.onReceive(receiveEvent);  // Called when master writes to the slave
  Wire.onRequest(requestEvent);  // Called when master requests data from the slave
  analogWrite(ledPin, maxBrightness);
  delay(1000);
  analogWrite(ledPin, LOW);
}

void loop() {
 if (ledShouldBlink) {
    // Check if enough time has passed
    if (millis() - ledOnTime >= ledOnLength) {
      digitalWrite(ledPin, LOW);
      ledShouldBlink = false;
    }
  }
}


// Called when master sends data to this slave
void receiveEvent(int numBytes) {
  while (Wire.available()) {
    char command = Wire.read();
    
    // Interpret the command
    switch (command) {
      case 'R':
        // Set status to Ready
        statusCode = 'R';
        break;
      case 'D':
        // Done or data request: maybe update status or log that we should send a sensor value next time
        statusCode = 'D';
        // (Optionally do something like measuring a sensor here)
        sensorReading = 69; // Example: update sensor reading based on master request
        analogWrite(ledPin, maxBrightness);
        ledOnLength = 500;
        ledShouldBlink = true;
        ledOnTime = millis();
        break;
      case 'i':
        statusCode = 'i';
        analogWrite(ledPin, maxBrightness);
        ledOnLength = 500;
        ledShouldBlink = true;
        ledOnTime = millis();
        break;
      case 'E':
        // Error or special condition
        statusCode = 'E';
        analogWrite(ledPin, maxBrightness);
        ledOnLength = 500;
        ledShouldBlink = true;
        ledOnTime = millis();
        break;
      default:
        // Unknown command
        statusCode = '?';
        analogWrite(ledPin, maxBrightness);
        ledOnLength = 100;
        ledShouldBlink = true;
        ledOnTime = millis();
        break;
    }
  }
}

// Called when master requests data from this slave
void requestEvent() {
  // Here we decide what to send based on the current statusCode.
  // For a simple example, we just send the statusCode and possibly some data.
  
  // Send the status code first
  Wire.write(statusCode);
  
  // If the status was 'D' (Done), we might also send additional data, like a sensor reading.
  if (statusCode == 'D') {
    // Convert sensorReading (int) to two bytes and send it
    analogWrite(ledPin, maxBrightness);
    ledOnLength = 1200;
    ledShouldBlink = true;
    ledOnTime = millis();
    Wire.write((byte)(sensorReading >> 8));  // High byte
    Wire.write((byte)(sensorReading & 0xFF)); // Low byte
  }

  else if (statusCode == 'i') {
    analogWrite(ledPin, maxBrightness);
    ledOnLength = 1200;
    ledShouldBlink = true;
    ledOnTime = millis();
    Wire.write(0x69);
  }

  
}
