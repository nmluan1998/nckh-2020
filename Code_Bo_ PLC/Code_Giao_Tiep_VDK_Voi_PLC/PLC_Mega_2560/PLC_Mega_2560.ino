// Khai báo Chân Step Motor step mam xoay chai
     #define EN 13
     #define Y_STP 15
     #define Y_DIR 14
// Khai báo chân Motor DC
  // Motor 1 - bang tai 2
     #define IN1 9
     #define IN2 8
  // Motor 2 - Băng tải 1
     #define IN3 7
     #define IN4 6
  // Motor 3 - Mâm xoay cấp nắp
     #define IN5 5
     #define IN6 4
  // Motor 4 - Bom nuoc
     #define IN7 3
     #define IN8 2
// giao tiep plc
     // step
     #define STP 51
     #define DC1 46
     #define DC2 48
     #define DC3 50
     #define DC4 52

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
// Khai báo Step motor 1 - 2
      pinMode(EN, OUTPUT);
      // Động cơ bước 
      pinMode(Y_DIR, OUTPUT);
      pinMode(Y_STP, OUTPUT);
// khai bao giao tiếp plc
      pinMode(STP, INPUT_PULLUP);
      pinMode(DC1, INPUT_PULLUP);
      pinMode(DC2, INPUT_PULLUP);
      pinMode(DC3, INPUT_PULLUP);
      pinMode(DC4, INPUT_PULLUP);
// Khai báo motor 1-5
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(IN5, OUTPUT);
      pinMode(IN6, OUTPUT);
      pinMode(IN7, OUTPUT);
      pinMode(IN8, OUTPUT);
      // trang thái ban dau cua dong co.
                motor_1_Dung(); 
                motor_2_Dung(); 
                motor_3_Dung(); 
                motor_4_Dung(); 
}// end setup

void loop() {
  // put your main code here, to run repeatedly:
    
    if (digitalRead(STP)==LOW)
    {
      step(true, Y_DIR, Y_STP, 1000); 
    }
    else
    {
      step_Dung();  
    }
    if(digitalRead(DC1)==LOW)
    {
       motor_1_Tien(190);    // Băng tải 2 
    }
    else
    {
       motor_1_Dung(); 
    }
    if(digitalRead(DC2)==LOW)
    {
       motor_2_Tien(200);    // Băng tải 1
    }else
    {
       motor_2_Dung(); 
    }
    if(digitalRead(DC3)==LOW)
    {
        motor_3_Tien(190);    // Motor cấp nắp
    }
    else
    {
        motor_3_Dung(); 
    }
    if (digitalRead(DC4)==LOW)
    {
      motor_4_Tien(160);// motor bom nuoc
    }
    else
    {
       motor_4_Dung(); 
    }
}// end loop
//--------------Hàm điều khiển hướng và số bước của động cơ ---------------
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
     {analogWrite(IN1, speed1);                  
      digitalWrite(IN2, LOW);      
     }
void motor_1_Dung()           
     {digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
     }
//--------------------------Hàm điều khiển động cơ 2------------------------
void motor_2_Tien(int speed2)
     {analogWrite (IN4,255-speed2);                  
      digitalWrite(IN3, HIGH);      
     }
void motor_2_Dung()           
     {digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
     }
//--------------------------Hàm điều khiển động cơ 3------------------------
void motor_3_Tien(int speed3)
     {analogWrite (IN5,255-speed3);                  
      digitalWrite(IN6, LOW);      
     }
void motor_3_Dung()           
     {digitalWrite(IN5, LOW);
      digitalWrite(IN6, LOW);
     }
//--------------------------Hàm điều khiển động cơ 4------------------------
void motor_4_Tien(int speed4)
     {analogWrite (IN7,255-speed4);                  
      digitalWrite(IN8, HIGH);      
     }
void motor_4_Dung()           
     {digitalWrite(IN7, LOW);
      digitalWrite(IN8, LOW);
     }
