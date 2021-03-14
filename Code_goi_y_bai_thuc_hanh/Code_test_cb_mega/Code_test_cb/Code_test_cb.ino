int sensor1 = 40;
int sensor3 = 42;
int sensor4 = 44;
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(sensor1, INPUT_PULLUP);
  pinMode(sensor3, INPUT_PULLUP);
  pinMode(sensor4, INPUT_PULLUP);
  //pinMode(sensor2, INPUT_PULLUP);
}
void loop() {
  //read the pushbutton value into a variable
  int sensorVal1 = digitalRead(sensor1);
  int sensorVal3 = digitalRead(sensor3);
  int sensorVal4 = digitalRead(sensor4);
  //int sensorVal2 = digitalRead(sensor2);
  Serial.print("sensor1:");
  Serial.println(sensorVal1);
  
  Serial.print("sensor3:");
  Serial.println(sensorVal3);

  Serial.print("sensor4:");
  Serial.println(sensorVal4);
  //Serial.println(sensorVal2);
  Serial.println("----------------------");
  delay(600);
}
