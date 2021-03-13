// Khai báo Chân Motor DC 
     // Motor 1 - Băng tải 1
     #define IN1 7
     #define IN2 6
     // Motor 2 - Băng tải 2
     #define IN3 9
     #define IN4 8
     // Motor 3 - Cấp nắm
     #define IN5 5
     #define IN6 4
     // Motor 4 - Cấp bơm
     #define IN7 3
     #define IN8 2

// Khai báo động cơ bước - mam xoay chai
     #define Y_STP 15
     #define Y_DIR 14
     //#define EN  80
// Giao tiếp PLC
     #define DC1 46 // Băng tải 1
     #define DC2 48 // Băng tải 2
     #define DC3 50 // Động cơ Bơm
     #define DC4 52 // Động cơ Cấp nắm
     #define STP 51 // Động cơ bước
     
void setup() {
Serial.begin(9600);
// Khai báo motor 
      //Động cơ 1 - Băng tải 1
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      //Động cơ 2 - Băng tải 2
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      //Động cơ 3 - Cấp nắm
      pinMode(IN5, OUTPUT);
      pinMode(IN6, OUTPUT);
      //Động cơ 4 - Bơm
      pinMode(IN7, OUTPUT);
      pinMode(IN8, OUTPUT);
// Khai báo động cơ bước 
      pinMode(Y_DIR, OUTPUT);
      pinMode(Y_STP, OUTPUT);
      
// khai bao giao tiếp plc
      pinMode(DC1, INPUT_PULLUP);
      pinMode(DC2, INPUT_PULLUP);
      pinMode(DC3, INPUT_PULLUP);
      pinMode(DC4, INPUT_PULLUP);
      pinMode(STP, INPUT_PULLUP);
      
// Trang thai ban dau cua dong co.
      motor_1_Dung(); 
      motor_2_Dung();
      motor_3_Dung();
      motor_4_Dung();
}// end setup

void loop() {
   // Dieu khien dong co dc 1 - Băng tải 1
      int ValDC1=digitalRead(DC1);
      Serial.println(ValDC1);
      if(ValDC1==LOW){motor_1_Tien(220);}
      else motor_1_Dung();
   
    //Dieu khien dong co dc 2 - Băng tải 2
     int ValDC2=digitalRead(DC2);
     Serial.println(ValDC2);
     if(ValDC2==LOW){motor_2_Tien(220);}
     else motor_2_Dung();
    
    //Dieu khien dong co dc 3 - Cấp nắp
     int ValDC3=digitalRead(DC3);
     Serial.println(ValDC3);
     if(ValDC3==LOW){motor_3_Tien(220);}
     else motor_3_Dung();
    
    //Dieu khien dong co dc 4 - Bơm
     int ValDC4=digitalRead(DC4);
     Serial.println(ValDC4);
     if(ValDC4==LOW){motor_4_Tien(220);}
     else motor_4_Dung();

    // Động cơ bước 
       int ValSTP=digitalRead(STP);
       Serial.println(ValSTP);
       if (ValSTP==LOW){step(true, Y_DIR, Y_STP, 800); }
       else //step_Dung();  

   Serial.println("--------------");
   delay(100);
   
}// end loop
//---------------Hàm điều khiển hướng và số bước của động cơ ---------------
void step(boolean dir, byte dirPin, byte stepperPin, int steps){ 
     //digitalWrite(EN, LOW);               // Cho phép Step motor chạy
     digitalWrite(dirPin, dir);
     delay(30);
     for (int i = 0; i < steps; i++){
         digitalWrite(stepperPin, HIGH);
         delayMicroseconds(800);  
         digitalWrite(stepperPin, LOW);
         delayMicroseconds(800);  
         }
 }
//void step_Dung(){digitalWrite(EN, HIGH);}

//Động cơ 1 - Băng tải 1
void motor_1_Tien(int speed1){
     analogWrite(IN1, speed1);                  
     digitalWrite(IN2, LOW);      
 }
void motor_1_Dung(){
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, LOW);
 }
//Động cơ 1 - Băng tải 2
void motor_2_Tien(int speed1){
     analogWrite(IN3, speed1);                  
     digitalWrite(IN4, LOW);      
 }
void motor_2_Dung(){
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
}
//Động cơ 3 - Cấp nắm
void motor_3_Tien(int speed1){
     analogWrite(IN5, speed1);                  
     digitalWrite(IN6, LOW);      
 }
void motor_3_Dung(){
     digitalWrite(IN5, LOW);
     digitalWrite(IN6, LOW);
}
//Động cơ 4 - bơm
void motor_4_Tien(int speed1){
     analogWrite(IN7, speed1);                  
     digitalWrite(IN8, LOW);      
 }
void motor_4_Dung(){
     digitalWrite(IN7, LOW);
     digitalWrite(IN8, LOW);
}
