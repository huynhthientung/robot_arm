
#include <Servo.h>

Servo khop1, khop2, khop3, khop4;
char blue;
void setup(){

    Serial.begin(9600);
    khop1.attach(6);
    khop2.attach(9);
    khop3.attach(10);
    khop4.attach(11); 
    defaultPosition();
}
void loop(){

  if (Serial.available() > 0) blue = Serial.read();

  switch(blue){


    case '0':
      stopArmRobot();
      break;
    case '1':
      quayTraiTuTu();
      break;
    case '2':
      nangLenBac2();
      break;
    case '3':
      nangLenBac3();
      break;
    case '4':
      xoayTraiBac4();
      break;
    case '5':
      quayPhaiTuTu();
      break;
    case '6': 
      haXuongBac2();
      break;
    case '7': 
      haXuongBac3();
      break;
    case '8': 
      xoayPhaiBac4();
      break;
  }
  
}
void stopArmRobot(){
    servoPosition(khop1.read(),khop2.read(), khop3.read(), khop4.read());
}
void servoPosition(int servo1, int servo2, int servo3, int servo4){
    khop1.write(servo1);
    khop2.write(servo2);
    khop3.write(servo3);
    khop4.write(servo4);
}
void quayTraiTuTu(){
    khop1.write(khop1.read() + 1);
    delay(50);
}
void quayPhaiTuTu(){
    khop1.write(khop1.read() - 1);
    delay(50);
}
void nangLenBac2(){
    khop2.write(khop2.read() + 1);
    //delay(50);  
}
void haXuongBac2(){
    khop2.write(khop2.read()- 1);
    //delay(50);  
}
void nangLenBac3(){
    khop3.write(khop3.read()+ 1);
    delay(50);  
}
void haXuongBac3(){
    khop3.write(khop3.read()- 1);
    delay(50);  
}
void xoayTraiBac4(){
    khop4.write(khop4.read() + 1);
    delay(50);  
}
void xoayPhaiBac4(){
    khop4.write(khop4.read()- 1);
    delay(50);  
}
void defaultPosition(){
    khop1.write(20);
    khop2.write(90);
    //khop3.write(80);
    //khop4.write(100);
}

