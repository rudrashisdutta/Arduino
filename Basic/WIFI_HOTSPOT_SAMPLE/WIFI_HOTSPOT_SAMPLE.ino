#include<ESP8266WiFi.h>
#define ssid "RK DUTTA"
#define PASSWORD "password"
IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);
void setup() {
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
  
  Serial.println();
  Serial.print("Setting soft-AP configuration....");
  Serial.println(WiFi.softAPConfig(local_IP,gateway,subnet)?"Ready":"Failed!");
  Serial.print("Setting soft-AP...");
  Serial.println(WiFi.softAP("TWINS33","gudrat33")?"Ready":"Failed!");
  Serial.println("Soft-AP IP Addresss = ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
