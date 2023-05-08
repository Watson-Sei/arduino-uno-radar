int Trigger = 3 // デジタルピン3をトリガーに設定
int Echo = 2 // デジタルピン2をエコーに設定

double duration = 0
double distance = 0
double speed_of_sound = 331.5 + 0.6 * 25; // 25度の場合の音速

void setup()
{
    Serial.begin(9600); // シリアル通信の初期化
    pinMode(Trigger, OUTPUT); // トリガーを出力に設定
    pinMode(Echo, INPUT); // エコーを入力に設定
}

void loop()
{
    digitalWrite(Trigger, LOW); // トリガーをLOWに設定
    delayMicroseconds(2); // 2マイクロ秒待機
    digitalWrite(Trigger, HIGH); // トリガーをHIGHに設定
    delayMicroseconds(10); // 10マイクロ秒待機
    digitalWrite(Trigger, LOW); // トリガーをLOWに設定
    duration = pulseIn(Echo, HIGH); // エコーのパルス幅を取得

    if (duration > 0 ) {
        duration = duration / 2; // 往復の時間を計算
        distance = duration * speed_of_sound * 100 / 1000000; // 距離を計算
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    }

    delay(200); // 200ミリ秒待機
}