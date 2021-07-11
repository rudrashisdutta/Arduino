#include<ESP8266WiFi.h>
#define ssid "Motorola One Power"
#define PASSWORD "password"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Connecting");
  WiFi.begin(ssid, PASSWORD);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP address:   ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI:   ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  // put your main code here, to run repeatedly:

}
