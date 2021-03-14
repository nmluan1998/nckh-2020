// code test động cơ DC cho mega.
 // Motor 1 - Máy bơm nước
     #define IN1 9
     #define IN2 8
  // Motor 2 - Băng tải 1
     #define IN3 7
     #define IN4 6
  // Motor 3 - Mâm xoay cấp nắp
     #define IN5 5
     #define IN6 4
  // Motor 4 - Băng tải 2
     #define IN7 3
     #define IN8 2
  
void setup() {
  // put your setup code here, to run once:
//Khai báo motor 1-5
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(IN5, OUTPUT);
      pinMode(IN6, OUTPUT);
      pinMode(IN7, OUTPUT);
      pinMode(IN8, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
     motor_1_Tien(150);
     motor_2_Tien(195);    // Băng tải 1
     motor_4_Tien(195);    // BƠM NUOC
     motor_3_Tien(160);    // Motor cấp nắp
delay(2000);
                motor_1_Dung(); 
                motor_2_Dung(); 
                motor_3_Dung(); 
                motor_4_Dung(); 
               
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
      digitalWrite(IN8, LOW);      
     }
void motor_4_Dung()           
     {digitalWrite(IN7, LOW);
      digitalWrite(IN8, LOW);
     }
     
