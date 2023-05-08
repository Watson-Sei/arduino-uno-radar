#include <Servo.h>

Servo myservo; // サーボモーターを制御するためのオブジェクトを作成

int pos = 0;

void setup() 
{
    myservo.attach(9); // サーボモーターをデジタルピン9に接続
}

void loop()
{
    for (pos = 0; pos <= 180; pos+= 1) {
        myservo.write(pos);
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
    }
}

