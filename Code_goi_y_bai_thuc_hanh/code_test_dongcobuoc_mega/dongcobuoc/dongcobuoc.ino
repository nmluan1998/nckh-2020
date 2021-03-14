  #define EN 16
     //Step Motor 2
     #define Y_STP 15// uno 11
     #define Y_DIR 14// uno 12
void setup() {
  // put your setup code here, to run once:
      pinMode(EN, OUTPUT);
      // Động cơ bước 2
      pinMode(Y_DIR, OUTPUT);
      pinMode(Y_STP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  step(true, Y_DIR, Y_STP, 800);
  delay(1000);
  
}

void step(boolean dir, byte dirPin, byte stepperPin, int steps)
     { digitalWrite(EN, LOW);               // Cho phép Step motor chạy
       digitalWrite(dirPin, dir);
       delay(50);
       for (int i = 0; i < steps; i++) 
           {
            digitalWrite(stepperPin, LOW);
            delayMicroseconds(800);  
            digitalWrite(stepperPin, HIGH);
            delayMicroseconds(800);  
            }
     }
