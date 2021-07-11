#include<ESP8266WiFi.h>
#define ssid "RK DUTTA"
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
  Serial.print("Current WiFi Strength:   ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=WiFi.scanNetworks();
  Serial.println("...........................\n");
  for(int b=0;b<a;b++){
    Serial.print(b+1);
    Serial.println(") Network");
    Serial.print("\t SSID:  ");
    Serial.println(WiFi.SSID(b));
    Serial.print("\t RSSI:  ");
    Serial.println(WiFi.RSSI(b));
  }
  delay(50000);
}
