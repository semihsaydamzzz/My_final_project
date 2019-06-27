#include <Servo.h>

int data;     //androidden gelecek data 0-1-2-3-4


int ballast = 9;

Servo servoMotor1;
Servo servoMotor2;
Servo servoMotor3;

void setup() {

  Serial.begin(9600); //bluetooth çalışma bandı

  pinMode(ballast, OUTPUT);
  
  servoMotor1.attach(5);
  servoMotor2.attach(3);
  servoMotor3.attach(6);

}

void loop() {

  if(Serial.available()>0)
   {
    data=Serial.read();  //data değerini alacağ
    
    if(data=='0')  //motorlar durmalı
    {
      delay(15);
      //analogWrite(ballastt, 0);  
      analogWrite(ballast, 0);

      /*servoMotor1.write(90); //motorları ortaya getirip durdurcan
      servoMotor2.write(90);
      servoMotor3.write(90); */

      servoMotor1.write(90); // ilk motoru sıfır konumuna getir.
      servoMotor2.write(90);
      servoMotor3.write(90);
      delay(1000);
    }
    

    if(data=='1') // ileri tuşuna basılırsa      //not servo kaç dereceden başlar bilinmiyor. derecelerle vb oynanacak. bir de aynı anda bu 3 motorun çalışması sağlanacak şu an aynı anda çalışmıyor
    {

      while(data != '0')
      {
        
      servoMotor1.write(100);
      servoMotor2.write(95);
      servoMotor3.write(100);
      delay(200);

      servoMotor1.write(80);
      servoMotor2.write(85);
      servoMotor3.write(80);
      delay(200);

      data = Serial.read();
       
      }
      stop();
     

      

    }

    if(data=='2') // sağ tuşuna basılır. ballast tank boşalsın ve aşağı insin robot
    {
     while (data != '0')
     {
    //analogWrite(ballastt, 0);
    analogWrite(ballast, 180);   //bu değerle oynanabilir. 180 demek 3.5 V demektir.
    delay(2000);
     }
     //stop();
    }

    if(data=='3') // sol tuşuna basılır. Ballast tank dolsun ve robot yükselsin
    {
      while(data != '0')
      {
     //analogWrite(ballastt, 180);  //ballast tankın dc motorunun artısına 3.5v gönderdim
     analogWrite(ballast, 0);
     delay(2000);
     
      }
      //stop();
    }

    if(data=='4') // aşağı tuşuna basılır. Şuan boşta. bunu far yapabiliriz. Veya motoru daha hızlı döndürme yapabiliriz.
    {
      
    }

    if(data=='5') // hızlı ileri
    {

      while(data != '0')
      {
      servoMotor1.write(120);
      servoMotor2.write(80);
      servoMotor3.write(120);
      delay(150);

      servoMotor1.write(60);
      servoMotor2.write(100);
      servoMotor3.write(60);
      delay(150);

      data=Serial.read();
      
      }
      stop();
     
      
    }

    if(data=='6') // Yavaş ileri
    {
       while(data != '0')
      {
        
      
      servoMotor1.write(120);
      servoMotor2.write(75);
      servoMotor3.write(120);
      delay(500);

      servoMotor1.write(70);
      servoMotor2.write(105);
      servoMotor3.write(70);
      delay(500);

      data=Serial.read();
      delay(15);
      }
      stop();
    }

    if(data=='7') // Sola dön
    {
       while(data != '0')
      {
        
      
      servoMotor1.write(120);
      servoMotor2.write(70);
      servoMotor3.write(120);
      delay(150);

      servoMotor1.write(110);
      servoMotor2.write(100);
      servoMotor3.write(110);
      delay(700);

      data=Serial.read();
      delay(15);
      }
      stop();
    }

    if(data=='8') // Sağa dön
    {
       while(data != '0')
      {
        
      
      servoMotor1.write(70);
      servoMotor2.write(120);
      servoMotor3.write(100);
      delay(700);

      servoMotor1.write(110);
      servoMotor2.write(90);
      servoMotor3.write(100);
      delay(150);

    
      data=Serial.read();
      delay(15);
      }
      stop();
    }

    
   }
}

void stop()
    {
      servoMotor1.write(90); // ilk motoru sıfır konumuna getir.
      servoMotor2.write(90);
      servoMotor3.write(90);
      delay(1000);

      analogWrite(ballast, 0);
      analogWrite(ballast, 0);
      
    }


     

    
