#define stop1 18

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(stop1,INPUT_PULLUP);
attachInterrupt(5,ngung,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("----------");
delay(1000);
}
void ngung()
{
  Serial.println("ngat khan cap");
}
