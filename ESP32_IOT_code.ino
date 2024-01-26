#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "J0BpK_Y7m9_tfYmy4hqAfaPN03gcjr7Y";  // Enter your Blynk authentication token
char ssid[] = "Garv";  // Your WiFi network name
char pass[] = "12341234";  // Your WiFi network password

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
  digitalWrite(21, LOW);  // Turn the lights off initially
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int lightStatus = param.asInt();  // Get the value from the Blynk app (0,1,2,3)

  if (lightStatus == 0) {
    digitalWrite(5, HIGH);
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    digitalWrite(21, LOW);
  } else if (lightStatus == 1) {
    digitalWrite(18, HIGH);  
    digitalWrite(5, LOW);  
    digitalWrite(19, LOW);  
    digitalWrite(21, LOW);  
  } else if (lightStatus == 2) {
    digitalWrite(18, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(19, LOW);
    digitalWrite(21, LOW);
  } else if (lightStatus == 3) {
    digitalWrite(21, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
  } else {
    digitalWrite(21, LOW);
    digitalWrite(5, LOW);
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
  }
}
