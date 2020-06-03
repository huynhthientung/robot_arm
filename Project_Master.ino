// created by Huynh Thien Tung on July 21st 2017
// This program is used for NRF, Joystick, Button and module MPU6050 - GY521
// TRANSMITTER
#include <SPI.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;
const int SW_pin = 8; 
const int X_pin = A1; // X
const int Y_pin = A2; // Y
int a, b, c, d, e, f, g, x, y, swtich; 

#define OUTPUT_READABLE_ACCELGYRO

void setup(){ 
//  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
//  Wire.begin();
//  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
//        Fastwire::setup(400, true);
//  #endif  
    Serial.begin(9600);
   // accelgyro.initialize();
  // set pins servo, type pins
    for (int i = 2; i <= 8; i++) pinMode(i, INPUT);
    digitalWrite(SW_pin, HIGH);
}
 
void loop(){
  // write code here
  x = getX();
  y = getY();
  swtich = digitalRead(SW_pin); // pin 8
  a = digitalRead(2);
  b = digitalRead(3);
  
//   Serial.print(a); Serial.print("\t");
//   Serial.print(b); Serial.print("\t");
//   Serial.print(x); Serial.print("\t");
//   Serial.print(y); Serial.print("\t");
//   Serial.print(swtich); Serial.print("\t");/
//   Serial.println();
    if (x == 0) Serial.write('0'); else if (x == 1) Serial.write('1'); else if (x == 2) Serial.write('2');
    //if (y == 0) Serial.write(3); else if (y == 1) Serial.write(4); else if (y == 2) Serial.write(5); delay(5);
//    if (swtich == 0) Serial.write(6); else if (swtich == 1) Serial.write(7); delay(5);
//    if (a == 1 && b == 0) Serial.write(8); else if (a == 0 && b == 1) Serial.write(9); else if (a == 0 && b == 0) Serial.write(10); delay(5);

//  //////////////////
//  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
//    #ifdef OUTPUT_READABLE_ACCELGYRO
//     // set ax ay
//    #endif
    
   
} 
int getX(){
  int  x = analogRead(A1);
  if (x < 100) return 0; 
  if (x > 100 && x < 900) return 1; 
  if (x > 900) return 2;
}
int getY(){
  int y = analogRead(A2);
  if (y < 100) return 3; 
  if (y > 100 && y < 900) return 4; 
  if (y > 900) return 5;
}
