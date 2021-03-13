// Khai báo Chân Step Motor dan nhan
     #define EN 8
     #define Z_STP 11
     #define Z_DIR 12
// Khai báo chân Motor DC
  // Motor ep nhan
     #define IN1 5
     #define IN2 6
// giao tiep PLC vs uno
     #define STP 7
     #define DC A3

void setup() {
  // put your setup code here, to run once:
 // Khai báo Step motor 1 - 2
      pinMode(EN, OUTPUT);
      pinMode(Z_DIR, OUTPUT);
      pinMode(Z_STP, OUTPUT);
//Khai báo motor 1
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
// khai bao giao tiep plc vs uno
      pinMode(DC,INPUT_PULLUP);
      pinMode(STP,INPUT_PULLUP);
      motor_1_Dung();    
}// end setup

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(STP)==LOW)
  {
    delay(250);
    step(false, Z_DIR, Z_STP, 500);
  }
  else
  {
     step_Dung();
  }
  if(analogRead(DC)< 500)
  {
     motor_1_Tien(220);
  }
  else
  {
    motor_1_Dung();      
  }
}// end loop
//------------Hàm điều khiển hướng và số bước của động cơ ---------------
void step(boolean dir, byte dirPin, byte stepperPin, int steps)
     { digitalWrite(EN, LOW);               // Cho phép Step motor chạy
       digitalWrite(dirPin, dir);
       delay(10);
       for (int i = 0; i < steps; i++) 
           {
            digitalWrite(stepperPin, HIGH);
            delayMicroseconds(800);  
            digitalWrite(stepperPin, LOW);
            delayMicroseconds(800);  
            }
     }
void step_Dung()
     {digitalWrite(EN, HIGH);     
     }
//--------------------------Hàm điều khiển động cơ 1------------------------
void motor_1_Tien(int speed1)
     {analogWrite (IN1,255-speed1);                  
      digitalWrite(IN2, HIGH);      
     }
void motor_1_Dung()           
     {digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
     }
