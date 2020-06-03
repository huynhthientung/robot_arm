#include <Servo.h>
//https://www.youtube.com/watch?v=oXKKiZGe95s
//http://linhkienrobotics.com/tin-tuc/code-mau-canh-tay-robot-dieu-khien-bang-may-tinh-new11048.html
Servo khop1;  //0-180
Servo khop2;  //0-80-150
Servo khop3;  //0-100
Servo khop4;  //0-100

int bluetoothByte = 0;

void setup()
{
  Serial.begin (9600);
  khop1.attach(2);//0-180
  khop2.attach(3);//0-80-150
  khop3.attach(4);//0-100
  khop4.attach(5);//0-100
}

void loop()
{
  bluetoothRobotArm();
}

void bluetoothRobotArm()
{
  if (Serial.available() > 0)
    bluetoothByte = Serial.read();
  switch (bluetoothByte)
  {
    case '0':
      stopArm();
      break;
    case '1':
      vuonRa1Buoc();
      break;
    case '2':
      thuVao1Buoc();
      break;
    case '3':
      quayTrai1Buoc();
      break;
    case '4':
      quayPhai1Buoc();
      break;
    case '5':
      nangLen1Buoc();
      break;
    case '6':
      haXuong1Buoc();
      break;
    case '7':
      kep1Buoc();
      break;
    case '8':
      moRa1Buoc();
      break;


  }
}

void stopArm()
{
  servoPosition(khop1.read(), khop2.read(), khop3.read(), khop4.read());
}

void kep()
{
  khop4.write(0);
}
void kep1Buoc()
{
  khop4.write(khop4.read() - 1);
  delay(50);
}

void moRa()
{
  khop4.write(100);
}
void moRa1Buoc()
{
  khop4.write(khop4.read() + 1);
  delay(50);
}

void moRaTuTu()
{
  for (int i = khop4.read(); i <= 130; i++)
  {
    khop4.write(i);
    delay(10);
  }
}
void kepTuTu()
{
  for (int i = khop4.read(); i >= 0; i--)
  {
    khop4.write(i);
    delay(10);
  }
}
void nangLenTuTu()
{
  for (int i = khop2.read(); i <= 90; i++)
  {
    khop2.write(i);
    delay(50);
  }
}
void nangLen1Buoc()
{
  khop2.write(khop2.read() + 1);
  delay(50);
}

void haXuongTuTu()
{
  for (int i = khop2.read(); i >= 50; i--)
  {
    khop2.write(i);
    delay(50);
  }
}
void haXuong1Buoc()
{
  khop2.write(khop2.read() - 1);
  delay(50);
}
void haXuong()
{
  khop2.write(50);
}
void nangLen()
{
  khop2.write(90);
}

void vuonRa()
{
  khop3.write(0);
}

void vuonRa1Buoc()
{
  khop3.write(khop3.read() - 1);
  delay(50);
}
void vuonRaTuTu()
{
  for (int i = khop3.read(); i >= 0; i--)
  {
    khop3.write(i);
    delay(50);
  }
}

void thuVao()
{
  khop3.write(100);
}

void thuVao1Buoc()
{
  khop3.write(khop3.read() + 1);
  delay(50);
}
void thuVaoTuTu()
{
  for (int i = khop3.read(); i <= 100; i++)
  {
    khop3.write(i);
    delay(50);
  }
}
void quayTrai()
{
  khop1.write(180);
}

void quayTrai1Buoc()
{
  khop1.write(khop1.read() + 1);
  delay(50);
}
void quayPhai()
{
  khop1.write(0);
}

void quayPhai1Buoc()
{
  khop1.write(khop1.read() - 1);
  delay(50);
}
void quayTraiTuTu()
{
  for (int i = khop1.read(); i <= 180; i++)
  {
    khop1.write(i);
    delay(50);
  }
}
void quayPhaiTuTu()
{
  for (int i = khop1.read(); i >= 0; i--)
  {
    khop1.write(i);
    delay(50);
  }
}

void readyPosition()
{
  khop1.write(90);
  khop2.write(100);
  khop3.write(80);
  khop4.write(100);
}

void testMove()
{
  for (int i = 0; i <= 180; i++)
  {
    khop1.write(i);
    delay (20);
  }
  for (int i = 180; i >= 0; i--)
  {
    khop1.write(i);
    delay (20);
  }
  readyPosition();
  delay(500);
  for (int i = 0; i <= 100; i++)
  {
    khop2.write(i);
    delay (20);
  }
  for (int i = 100; i >= 0; i--)
  {
    khop2.write(i);
    delay (20);
  }

  readyPosition();
  delay(500);
  for (int i = 0; i <= 80; i++)
  {
    khop3.write(i);
    delay (20);
  }
  for (int i = 80; i >= 0; i--)
  {
    khop3.write(i);
    delay (20);
  }
  readyPosition();
  delay(500);
  for (int i = 0; i <= 100; i++)
  {
    khop4.write(i);
    delay (20);
  }
  for (int i = 100; i >= 0; i--)
  {
    khop4.write(i);
    delay (20);
  }
}
void servoPosition (byte servo1, byte servo2, byte servo3, byte servo4)
{
  khop1.write(servo1);
  khop2.write(servo2);
  khop3.write(servo3);
  khop4.write(servo4);
}


void turnAround ()
{
  for (int i = 0; i <= 180; i++)
  {
    khop1.write(i);
    delay (20);
  }
  for (int i = 180; i >= 0; i--)
  {
    khop1.write(i);
    delay (20);
  }
}
