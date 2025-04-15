#include <Arduino.h>
#include <M5Stack.h>

int cnt = 0; // カウント値

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Hello World!");
}

void loop() {
  M5.update();
  // Aボタンが押されたら+1
  if(M5.BtnA.wasPressed())
  {
    M5.Lcd.clear(); // 画面全体を消去
    cnt++;
  }

  // Bボタンが押されたら-1
  if(M5.BtnB.wasPressed())
  {
    M5.Lcd.clear(); // 画面全体を消去
    cnt--;
  }

  // Cボタンが押されたら0
  if(M5.BtnC.wasPressed())
  {
    M5.Lcd.clear(); // 画面全体を消去
    cnt = 0;
  }

  delay(30);
  M5.Lcd.drawString("CNT=" + String(cnt), 0, 40); // カウント値を表示
} 
