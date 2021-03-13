// Khai báo Chân Step Motor dan nhan
     #define EN 13
     #define Z_STP 11
     #define Z_DIR 12
// Khai báo chân Motor DC
  // Motor ep nhan
     #define IN1 5
     #define IN2 6
// Khai báo chân cảm biến hồng ngoại
     #define CBN 8   
// bảng điều khiển.
     #define START 4
     #define STOP  2
     #define STATUS 3
     #define STEP2 A1
     #define DC5   A0
// biến để phục vụ nút ấn.
  int start =0;
  int status1 = 0;
///++++++++++++++ chương trình con +++++++++++++++++
// ngừng khẩn cấp
void NGUNGKHANCAP(){
  motor_1_Dung(); 
  step_Dung();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
// Khai báo Step motor 1 - 2
      pinMode(EN, OUTPUT);
      pinMode(Z_DIR, OUTPUT);
      pinMode(Z_STP, OUTPUT);
//Khai báo motor 1
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
// khai bao cam bien.
      pinMode(CBN,INPUT_PULLUP);    
// KHAI BÁO NÚT ẤN.
      pinMode(START,INPUT_PULLUP);
      pinMode(STOP,INPUT_PULLUP);
      pinMode(STATUS,INPUT_PULLUP);
      pinMode(STEP2,INPUT_PULLUP);
      pinMode(DC5,INPUT);
// ngừng khẩn cấp stop
     attachInterrupt(0, NGUNGKHANCAP, LOW); // gọi hàm tat liên tục khi còn nhấn nút
 // trang thai ban dau.   
       motor_1_Dung();      
      
}// end setup

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(START)==LOW){start =1;}
 
 if(start ==1)
   { // tự động
  if (digitalRead(STATUS)==LOW)
  { 
     motor_1_Tien(220);
     if (digitalRead(CBN)==LOW){
          delay(250);
          step(false, Z_DIR, Z_STP, 500);
        }else{
              step_Dung();
             }
  }// end tu dong
// thu cong
 if(digitalRead(STATUS)==HIGH){
   
    int ADC1=analogRead(DC5);
    int feed1 = map(ADC1,0,1023,0,255);
    motor_1_Tien(feed1);

    if(analogRead(STEP2)<500){status1 = 1;}

    if(status1 == 1){
      step(false, Z_DIR, Z_STP, 500);
      status1 =0;
    }
 }// end thu cong
}// end start.
}// end loop

//------------------------------Chương Trình Con----------------------------
//---------------Hàm điều khiển hướng và số bước của động cơ ---------------
void step(boolean dir, byte dirPin, byte stepperPin, int steps)
     { digitalWrite(EN, LOW);               // Cho phép Step motor chạy
       digitalWrite(dirPin, dir);
       delay(30);
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
