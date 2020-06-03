#include <Servo.h>
Servo khop1a, khop2_1a, khop2_2a, khop3a, khop4a, khop5a, khop1b, khop2b, khop3b;

const byte spd = 1; // speed

int btn1, btn2, btn3, btn4, btn5, btn6, swt, sensor1, sensor2, x, y, temp3, temp4;
void setup()
{
  //Serial.begin(9600);
  for (int i = 22; i <= 34; i++)
    if (i % 2 == 0) pinMode(i, INPUT);
  digitalWrite(22, HIGH); // Swtich

  khop1a.attach(31);
  khop2_1a.attach(33);
  khop2_2a.attach(35);
  khop3a.attach(37);
  khop4a.attach(39);
  khop5a.attach(41);
  khop1b.attach(43);
  khop2b.attach(45);
  khop3b.attach(47);

  khop1a.write(120);
  khop2_1a.write(120);
  khop2_2a.write(120);
  khop3a.write(120);
  khop4a.write(45);
  khop5a.write(40);
  khop1b.write(45);
  khop2b.write(45); 
  khop3b.write(45);
}


void loop()
{
     swt = digitalRead(22);
     btn1 = digitalRead(24);
     btn2 = digitalRead(26);
     btn3 = digitalRead(28);
     btn4 = digitalRead(30);
     btn5 = digitalRead(32);
     btn6 = digitalRead(34);
     sensor1 = analogRead(A1);
     sensor2 = analogRead(A2);
     temp3 = analogRead(A3);
     temp4 = analogRead(A4);
     //getData(); // show temperature and humidity on LCD
    //read_Control; // read buttons and sensors;
    //Processing(); // x, y, map A1 A2;

    sensor1 = map(sensor1, 0, 1023, 0, 180);
    sensor2 = map(sensor2, 0, 1023, 0, 180);
    if (temp3 < 400) x = 0; else if (temp3 > 600) x = 2; else  x= 1;
    if (temp4 < 400) y = 0; else if (temp4 > 700) y = 2; else  y = 1;
    if (swt == 1) khop5a.write(0); else khop5a.write(50);
    if (btn1 == 1) khop3a.write(khop3a.read()-spd); else khop3a.write(khop3a.read());  
    if (btn2 == 1) khop3a.write(khop3a.read()+spd); else khop3a.write(khop3a.read());
    if (x == 1) khop1a.write(khop1a.read()); else if (x == 0) khop1a.write(khop1a.read()+spd); else if (x == 2) khop1a.write(khop1a.read()-spd);
    if (y == 1) 
      {
        khop2_1a.write(khop2_1a.read());
        khop2_2a.write(khop2_2a.read());
      }
     else if (y == 2) {
        khop2_1a.write(khop2_1a.read()+spd);
        khop2_2a.write(khop2_2a.read()+spd);
     }
     else if (y == 0) {
        khop2_1a.write(khop2_1a.read()-spd);
        khop2_2a.write(khop2_2a.read()-spd);
     }

     if (btn5 == 1) khop1b.write(khop1b.read()-spd); else khop1b.write(khop1b.read());
     if (btn4 == 1) khop1b.write(khop1b.read()+spd); else khop1b.write(khop1b.read());
//     
     if (btn6 == 1) khop2b.write(khop2b.read()-spd); else khop2b.write(khop2b.read());
     if (btn3 == 1) khop2b.write(khop2b.read()+spd); else khop2b.write(khop2b.read());
     khop3b.write(sensor2); 
     khop4a.write(sensor1);
    //testSerial();
    delay(20);
}



void testSerial(){
      Serial.print(digitalRead(22)); Serial.print("\t");
      Serial.print(digitalRead(24)); Serial.print("\t");
      Serial.print(digitalRead(26)); Serial.print("\t");
      Serial.print(digitalRead(28)); Serial.print("\t");
      Serial.print(digitalRead(30)); Serial.print("\t");
      Serial.print(digitalRead(32)); Serial.print("\t");
      Serial.print(digitalRead(34)); Serial.print("\t");
      Serial.print(analogRead(A1)); Serial.print("\t");
      Serial.print(analogRead(A2)); Serial.print("\t");
      Serial.print(analogRead(A3)); Serial.print("\t");
      Serial.print(analogRead(A4)); Serial.print("\t");
      Serial.println();
      delay(300);
}





