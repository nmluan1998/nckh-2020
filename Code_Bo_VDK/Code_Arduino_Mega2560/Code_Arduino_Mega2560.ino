// Khai báo Chân Step Motor step mam xoay chai
     #define EN 16
     #define Y_STP 15
     #define Y_DIR 14
// Khai báo chân Motor DC
  // Motor 1 - bang tai 
     #define IN1 7
     #define IN2 6
  // Motor 2- Băng tải 3
     #define IN3 9
     #define IN4 8
  // Motor 3 - Mâm xoay cấp nắp
     #define IN5 5
     #define IN6 4
  // Motor 4 - Bom nuoc
     #define IN7 3
     #define IN8 2
// Khai báo Chân relay                       
     #define RELAY1  28   
     #define RELAY2  30  
     #define RELAY3  32  
     #define RELAY4  34   
     #define RELAY5  36 
     #define RELAY6  38  
// Khai báo chân cảm biến hồng ngoại
     #define CBCR 40
     #define CBDG2 42
     #define CBDG1 44
// bảng điều khiển.
     #define START 26
     #define STOP  18
     #define STATUS 19
     #define STEP1 49
     #define DC1   A0
     #define DC2   A1
     #define DC3   A2
     #define DC4   A3
     #define XL1_ON  23
     #define XL1_OFF 25
     #define XL2_ON  27
     #define XL2_OFF 29
     #define XL3_ON  31
     #define XL3_OFF 33
     #define XL4_ON  37
     #define XL4_OFF 39
     #define XL5_ON  41
     #define XL5_OFF 43
     #define XL6_ON  45
     #define XL6_OFF 47

// Khai báo biến toàn cục
        // Khai báo biến hàm milli
           unsigned long time2 = 0;
           unsigned long time3 = 0;
           unsigned long time4 = 0;
           unsigned long time5 = 0;
           unsigned long time6 = 0;
           unsigned long time7 = 0;
           unsigned long time8 = 0;
           unsigned long time9 = 0;
           unsigned long time11 = 0;
           unsigned long time12 = 0;
           unsigned long time13 = 0;
           unsigned long time14 = 0;
           unsigned long time15 = 0;
           unsigned long time16 = 0;
           unsigned long time17 = 0;
           unsigned long time18 = 0;
           unsigned long time19 = 0;
           unsigned long time20 = 0;
          
        // Biến toan cuc.
           int nap = 0;
           int bandau = 0;
           int dem= 0;
           int dem2=0;
           int dem3=0;
           int Speed1 , Speed2 ;
           int donggoi = 0;
           int donggoi1 = 0;
           int donggoi2 = 0;
           int daychai = 0;
           int dongnap = 0;
           int got = 0;
           int bom = 0;
           int chothuchien = 0;
           // biến để phục vụ nút ấn.
           int start =0;
           int statusrelay = 0;
// ++++++++++++++++++++++++++++++++ chuong trinh con ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//---- chiết gót ---------
void chiet_got()
{
   if (digitalRead(CBCR) == LOW)
              {  
                got = 1; 
              }
   else       {
                delay(200);
                step(true, Y_DIR, Y_STP, 1000);  
                got = 0;  
              }
   if (got == 1){
                   motor_4_Tien(130);
                if (nap != 0){
                    if ( dongnap == 0){
                                  digitalWrite(RELAY2,LOW);
                                  dongnap = 1;
                                  time15 = millis();
                                  time11 = millis();
                                }
                    if (dongnap == 1){
                       if ((unsigned long) (millis() - time15) > 750 ){
                                digitalWrite(RELAY2,HIGH);   
                                dongnap = 2;
                                time16 = millis();
                       }   
                     }
                     if ( dongnap == 2 ){
                      if ((unsigned long) (millis() - time16) > 100 ){
                                digitalWrite(RELAY1,LOW);
                                dongnap = 3;
                                time17 = millis();
                      }    
                     }
                     if ( dongnap == 3){
                       if ((unsigned long) (millis() - time17) > 600 ){
                                digitalWrite(RELAY1,HIGH); 
                                dongnap = 4;
                                nap = 1;
                                dem2=1;                         
                       }  
                     }                         
              }else {
                     dongnap = 4; 
                     if( bom == 0){ time11 = millis(); 
                     bom = 1;}                     
              }
         }
        
 if (dongnap == 4){
  //Tắt động cơ bom       
   if ((unsigned long) (millis() - time11) > 3000 )
             {  
                 motor_4_Dung();                            
                 dem2=0;
                 delay(50);
                 step(true, Y_DIR, Y_STP, 1000);               
                 time11 = millis();
                 dongnap = 0;
                 time2 = millis();
                 nap = 1;
                 got = 0;
             }    
 }        
} // end chiet_rot
//---- đóng gói 6 chai --------
void dong_goi()
{
     if( chothuchien == 0){
        if ((unsigned long) (millis() - time4) > 500 )
           {digitalWrite(RELAY5,LOW);                    
            time5 = millis();
            chothuchien = 1;
           }}
      if( chothuchien == 1 ){
        if ((unsigned long) (millis() - time5) > 1500  )
             {
              digitalWrite(RELAY4,LOW);                           
              time6 = millis();
              chothuchien = 2;
             }} 
       if ( chothuchien == 2){
         if ((unsigned long) (millis() - time6) > 800 )
             {
              digitalWrite(RELAY5,HIGH);     
              time7= millis();
              chothuchien = 3;
              } }
       if ( chothuchien == 3){
         if ((unsigned long) (millis() - time7) > 1700  )
             {
              digitalWrite(RELAY6,LOW);              
              time8 = millis();
              chothuchien = 4;
             } }
        if ( chothuchien == 4 ){
         if ((unsigned long) (millis() - time8) > 1800)
             {
              digitalWrite(RELAY5,LOW);                            
              time9 = millis();
              chothuchien = 5;
             }  }
         if ( chothuchien == 5){
          if ((unsigned long) (millis() - time9) > 1500  )
             {
              digitalWrite(RELAY4,HIGH);                            
              time12 = millis();
              chothuchien = 6;
             }  }
      // đưa về vị trí đầu của rắp 6 chai.
         if( chothuchien == 6){
          if ((unsigned long) (millis() - time12) > 800 )
             {
                digitalWrite(RELAY5,HIGH);     
                time13 = millis();
                chothuchien = 7;
             }  }    
           if ( chothuchien == 7 ){
             if ((unsigned long)(millis() - time13) > 1500 ){
                      digitalWrite(RELAY6,HIGH);
                      time13 = millis();
                      chothuchien = 0;
                      donggoi1 = 0;
                    } } 
} // end dong_goi
// ---- đẩy 2 chai vào --------
void hai_chai()
{ 
  if (digitalRead(CBDG1) == LOW )
  {
    donggoi = 1;
  }
  if (digitalRead(CBDG2) == LOW ){
    donggoi2 = 1;
  }
  if (donggoi == 1 && donggoi2 == 1 ) 
              { 
                 if (daychai == 0 ){ 
                  digitalWrite(RELAY3,LOW);
                  time14 = millis(); 
                  daychai = 1;
                 }
                 if( daychai ==1 ){
                 if ((unsigned long)(millis() - time14) > 700 ){
                  digitalWrite(RELAY3,HIGH);           
                  dem++; 
                  donggoi = 0; 
                  donggoi2 = 0;
                  daychai =0; 
                  time3 = millis();                          
                    }
                  }
                }
               else { digitalWrite(RELAY3,HIGH); time3 = millis(); }                
}// end 2 chai
// ---- ngừng khẩn cấp.------
void NGUNGKHANCAP(){
  motor_1_Dung(); 
  motor_2_Dung(); 
  motor_3_Dung(); 
  motor_4_Dung(); 
  step_Dung();
}

void setup()
{     
  Serial.begin(9600);
// Khai báo Step motor 1 - 2
      pinMode(EN, OUTPUT);
      // Động cơ bước 
      pinMode(Y_DIR, OUTPUT);
      pinMode(Y_STP, OUTPUT);
      
// Khai báo motor 1-5
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(IN5, OUTPUT);
      pinMode(IN6, OUTPUT);
      pinMode(IN7, OUTPUT);
      pinMode(IN8, OUTPUT);

// cam bien
      pinMode(CBCR, INPUT_PULLUP);
      pinMode(CBDG1, INPUT_PULLUP);
      pinMode(CBDG2,INPUT_PULLUP);  
// KHAI BÁO NÚT ẤN.
      pinMode(START,INPUT_PULLUP);
      pinMode(STOP,INPUT_PULLUP);
      pinMode(STATUS,INPUT_PULLUP);
      pinMode(STEP1,INPUT_PULLUP);
      pinMode(DC1,INPUT);
      pinMode(DC2,INPUT);
      pinMode(DC3,INPUT);
      pinMode(DC4,INPUT);
      pinMode(XL1_ON,INPUT_PULLUP);
      pinMode(XL1_OFF,INPUT_PULLUP);
      pinMode(XL2_ON,INPUT_PULLUP);
      pinMode(XL2_OFF,INPUT_PULLUP);
      pinMode(XL3_ON,INPUT_PULLUP);
      pinMode(XL3_OFF,INPUT_PULLUP);
      pinMode(XL4_ON,INPUT_PULLUP);
      pinMode(XL4_OFF,INPUT_PULLUP);
      pinMode(XL5_ON,INPUT_PULLUP);
      pinMode(XL5_OFF,INPUT_PULLUP);
      pinMode(XL6_ON,INPUT_PULLUP);
      pinMode(XL6_OFF,INPUT_PULLUP);
// ngừng khẩn cấp stop
     attachInterrupt(5, NGUNGKHANCAP,LOW); // gọi hàm tat liên tục khi còn nhấn nút
     statusrelay = 0;
// Khai báo chân relay 1-6, đk van 1-6    
      pinMode(RELAY2, OUTPUT);    // đẩy nắp
      pinMode(RELAY1, OUTPUT);    // Đóng nắp
      pinMode(RELAY3, OUTPUT);    // đẩy 2 chai
      pinMode(RELAY5, OUTPUT);    // kéo chai lên
      pinMode(RELAY4, OUTPUT);    // kẹp chai 
      pinMode(RELAY6, OUTPUT);    // kéo chai qua trái
             // Trạng Thái ban đầu của relay
                digitalWrite(RELAY1,HIGH);         
                digitalWrite(RELAY2,HIGH);
                digitalWrite(RELAY3,HIGH);         
                digitalWrite(RELAY4,HIGH);
                digitalWrite(RELAY5,HIGH);         
                digitalWrite(RELAY6,HIGH);
              // trsng thái ban dau cua dong co.
                motor_1_Dung(); 
                motor_2_Dung(); 
                motor_3_Dung(); 
                motor_4_Dung(); 
               
// Khởi tạo hàm mili()    
      time2 = millis();
      time3 = millis(); 
      time4 = millis();
      time5 = millis(); 
      time6 = millis(); 
      time7 = millis(); 
      time8 = millis(); 
      time9 = millis(); 
      time11  = millis();
      time12  = millis(); 
      time13  = millis();
      time14  = millis();  
      time15  = millis();
      time16  = millis(); 
      time17  = millis();
      time18  = millis(); 
      time19  = millis();
      time20  = millis(); 
      

}// end setup


void loop()
{
if (digitalRead(START)==LOW){start =1;}
 if(start ==1)
 { // tự động
  if (digitalRead(STATUS)==LOW)
  { 
    delay(50);
    statusrelay = 0;
// Trạng thái ban đầu
if(bandau==0){  
                // Cho phép băng tải & mâm xoay cấp nắp chạy  
                motor_1_Tien(200);    // Băng tải 1
                motor_2_Tien(200);    // Băng tải 2
                motor_3_Tien(200);    // Motor cấp nắp
                delay(300);
                step(true, Y_DIR, Y_STP, 1000);
                bandau = 1;
                time2 = millis();
                time3 = millis(); 
                time4 = millis();
                time5 = millis(); 
                time6 = millis(); 
                time7 = millis(); 
                time8 = millis(); 
                time9 = millis(); 
                time11  = millis();
                time12  = millis();
                time13 = millis();
                time14  = millis(); 
                time15 = millis(); 
                time16 = millis(); 
                time17  = millis();
                time18  = millis();
                time19 = millis();
                time20  = millis(); 
             }
// --- thực hiện chức năng chiết gói và đóng nắp. -----             
 if ((unsigned long) (millis() - time2) > 400 )
                       { 
                          chiet_got();                        
                       }    
//--- Đẩy 2 chai vào cụm đóng gói. --------
  if ((unsigned long) (millis() - time3) > 1000)
              {
                 hai_chai();
              } // end if day 2 chai.          
// Đóng gói 
if (dem == 3)
              {
                 donggoi1 = 1;
                 if(dem >= 3) dem = 0;
                 time4 = millis(); 
              }// end đóng gói.
if(donggoi1 == 1)
         {         
          dong_goi();
         }
}// end tư động.
// --------------------------------------
// thủ công
if(digitalRead(STATUS)==HIGH)
      {
          if(digitalRead(STEP1)==LOW){step(true, Y_DIR, Y_STP, 1000);}else{step_Dung();}
          int ADC1=analogRead(DC1);
          int feed1 = map(ADC1,0,1023,0,255);
          motor_1_Tien(feed1);    // Băng tải 1
          
          int ADC2=analogRead(DC2);
          int feed2 = map(ADC2,0,1023,0,255);
          motor_2_Tien(feed2);    // Băng tải 2
         
          int ADC3=analogRead(DC3);
          int feed3 = map(ADC3,0,1023,255,0);
          motor_3_Tien(feed3);    // Motor cấp nắp

          int ADC4=analogRead(DC4);
          int feed4 = map(ADC4,0,1023,0,255);
          motor_4_Tien(feed4);  // bơm nước

          delay(50);
          if (digitalRead(XL1_ON)==LOW){statusrelay = 1;}
          if (statusrelay == 1){digitalWrite(RELAY1,LOW);}
          if (digitalRead(XL1_OFF)==LOW){statusrelay = 2;}
          if (statusrelay == 2){digitalWrite(RELAY1,HIGH);}

          if (digitalRead(XL2_ON)==LOW){statusrelay = 3;}
          if (statusrelay == 3){digitalWrite(RELAY2,LOW);}
          if (digitalRead(XL2_OFF)==LOW){statusrelay = 4;}
          if (statusrelay == 4){digitalWrite(RELAY2,HIGH);}

          if (digitalRead(XL3_ON)==LOW){statusrelay = 5;}
          if (statusrelay == 5){digitalWrite(RELAY3,LOW);}
          if (digitalRead(XL3_OFF)==LOW){statusrelay = 6;}
          if (statusrelay == 6){digitalWrite(RELAY3,HIGH);}

          if (digitalRead(XL4_ON)==LOW){statusrelay = 7;}
          if (statusrelay == 7){digitalWrite(RELAY4,LOW);}
          if (digitalRead(XL4_OFF)==LOW){statusrelay = 8;}
          if (statusrelay == 8){digitalWrite(RELAY4,HIGH);}

          if (digitalRead(XL5_ON)==LOW){statusrelay = 9;}
          if (statusrelay == 9){digitalWrite(RELAY5,LOW);}
          if (digitalRead(XL5_OFF)==LOW){statusrelay = 10;}
          if (statusrelay == 10){digitalWrite(RELAY5,HIGH);}

          if (digitalRead(XL6_ON)==LOW){statusrelay = 11;}
          if (statusrelay == 11){digitalWrite(RELAY6,LOW);}
          if (digitalRead(XL6_OFF)==LOW){statusrelay = 12;}
          if (statusrelay == 12){digitalWrite(RELAY6,HIGH);}  

          delay(50);
          bandau = 0;
      }// end thủ công.
}// end start.
}// end loop.

//---------------Hàm điều khiển hướng và số bước của động cơ ---------------
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
     {
      digitalWrite(EN, HIGH);     
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
