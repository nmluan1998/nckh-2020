  #define EN 13
     //Step Motor 2
     #define Z_STP 11
     #define Z_DIR 12
void setup() {
  // put your setup code here, to run once:
      pinMode(EN, OUTPUT);
      // Động cơ bước 2
      pinMode(Z_DIR, OUTPUT);
      pinMode(Z_STP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  step(true, Z_DIR, Z_STP, 500);
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
