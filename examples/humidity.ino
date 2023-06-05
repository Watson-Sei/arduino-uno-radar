#include "DHT.h"

#define DHTPIN 2      // デジタルの2番ピンにDHTセンサーを接続
#define DHTTYPE DHT11 // DHT11センサーを使用

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600); // シリアル通信の初期化
    Serial.println("DHT11 test!"); // シリアル通信に文字列を送信

    dht.begin(); // DHTセンサーの初期化
}

void loop()
{
    delay(2000); // 2秒待機

    float h = dht.readHumidity(); // 湿度の取得
    float t = dht.readTemperature(); // 温度の取得

    if (isnan(h) || isnan(t)) // 取得に失敗した場合
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F(" °C"));
}