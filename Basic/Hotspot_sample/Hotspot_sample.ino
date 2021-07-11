#include<ESP8266WiFi.h>
IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting soft-AP configuration....");
  Serial.println(WiFi.softAPConfig(local_IP,gateway,subnet)?"Ready":"Failed!");
  Serial.print("Setting soft-AP...");
  Serial.println(WiFi.softAP("33","password")?"Ready":"Failed!");
  Serial.println("Soft-AP IP Addresss = ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
