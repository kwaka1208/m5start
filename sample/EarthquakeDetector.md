```cpp
#include <M5Stack.h>
#include "MPU6886.h"

float accX, accY, accZ;
float prevX, prevY, prevZ;
float threshold = 0.5; // 地震検知しきい値 (G単位)

void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Earthquake Detector Ready");
}

void loop() {
  M5.IMU.getAccelData(&accX, &accY, &accZ);

  // 直前との差を計算
  float deltaX = accX - prevX;
  float deltaY = accY - prevY;
  float deltaZ = accZ - prevZ;
  float delta = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);

  if (delta > threshold) {
    alertEarthquake();
  }

  // 現在値を次回のため保存
  prevX = accX;
  prevY = accY;
  prevZ = accZ;

  delay(50);
}

void alertEarthquake() {
  // ディスプレイ警告
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setCursor(50, 100);
  M5.Lcd.println("EARTHQUAKE!!");

  // ブザー音
  M5.Speaker.tone(1000, 500); // 1000Hzで0.5秒鳴らす

  delay(1000); // 1秒間警告表示
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("Monitoring...");
}
```