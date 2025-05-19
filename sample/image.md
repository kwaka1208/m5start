## 画像表示

```cpp
#include <M5Stack.h>
#include <SPIFFS.h>

void setup() {
  M5.begin();  // M5.begin() に config を渡すのが推奨
  M5.Lcd.setRotation(1);  // 画面の回転方向を設定

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed");
    return;
  }

  if (!SPIFFS.exists("/test.jpg")) {
    Serial.println("File not found: /test.jpg");
    return;
  }

  // 画像を描画
  M5.Lcd.drawJpgFile(SPIFFS, "/test.jpg", 0, 0);
}

void loop() {
  // 何もしないループ
}
```