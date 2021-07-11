#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define ldr D0
int ADC=1;

// Set these to run example.
#define FIREBASE_HOST "test-c0b59.firebaseio.com"
#define FIREBASE_AUTH "CHMBaL1BVgK5lTZb9Ltbv6SzO8xEtDHkfBGhVncl"
#define WIFI_SSID "Motorola One Power"
#define WIFI_PASSWORD "password"

void CONNECT()
{
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
Serial.print("CONNECTED");
while(WiFi.status()!=WL_CONNECTED)
{
delay(50);
Serial.print("'...'");
}
Serial.println("");
Serial.println("WiFi Connected");
Serial.println(WiFi.localIP());
}
void setup()
{
Serial.begin(115200);
CONNECT();

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Serial.println("Firebase Connected");

Firebase.setString("WELCOME","LUX READING VIA LDR");
pinMode(ldr,INPUT);
}

int n = 0;

void loop() {
// set value
ADC=digitalRead(D0);
Serial.println(ADC);
Firebase.setFloat("LUX",ADC);

Firebase.setFloat("number", 42.0);
// handle error
if (Firebase.failed()) {
Serial.print("LUX failed:");
Serial.println(Firebase.error());
return;
}
delay(1000);

// update value
Firebase.setFloat("number", 43.0);
// handle error
if (Firebase.failed()) {
Serial.print("setting /number failed:");
Serial.println(Firebase.error());
return;
}
delay(1000);

// get value
Serial.print("number: ");
Serial.println(Firebase.getFloat("number"));
delay(1000);

// remove value
Firebase.remove("number");
delay(1000);

// set string value
Firebase.setString("message", "hello world");
// handle error
if (Firebase.failed()) {
Serial.print("setting /message failed:");
Serial.println(Firebase.error());
return;
}
delay(1000);

// set bool value
Firebase.setBool("truth", false);
// handle error
if (Firebase.failed()) {
Serial.print("setting /truth failed:");
Serial.println(Firebase.error());
return;
}
delay(1000);

// append a new value to /logs
String name = Firebase.pushInt("logs", n++);
// handle error
if (Firebase.failed()) {
Serial.print("pushing /logs failed:");
Serial.println(Firebase.error());
return;
}
Serial.print("pushed: /logs/");
Serial.println(name);
delay(1000);
}
