#define ldr D0
void setup() {
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
float Sv=digitalRead(ldr);
Serial.print(Sv);
if(Sv==1.0){
Serial.println("High");
delay(2000);}
else
{
if (Sv==0.0)
Serial.println("Low");
delay(2000);
}
}
