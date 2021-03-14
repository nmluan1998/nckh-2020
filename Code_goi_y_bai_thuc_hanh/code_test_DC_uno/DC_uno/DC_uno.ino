// Motor 5 - Băng tải 3
     #define IN9  5
     #define IN10 6

void setup() {
  // put your setup code here, to run once:
      pinMode(IN9, OUTPUT);
      pinMode(IN10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
motor_5_Tien(190);    // Băng tải 3
delay(2000);
motor_5_Dung(); 
delay(1000);
}

void motor_5_Tien(int speed5)
     {analogWrite (IN9,255-speed5);                  
      digitalWrite(IN10, HIGH);      
     }
void motor_5_Dung()           
     {digitalWrite(IN9, LOW);
      digitalWrite(IN10,LOW);
     }
     
