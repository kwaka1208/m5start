# Wi-Fiに接続してwebサイトにアクセスする

1. srcフォルダのmain.cppをコピーして別のファイル名に変更する
2. 新しくmain.cppを作成し、以下の内容を入力する
3. includeフォルダのenv.h.tmpをenv.hにリネームする
4. env.hの"your-ssid"と"your-password"をWi-FiのSSIDとパスワードに変更する
5. M5Stackへ転送し、実行して表示されたメッセージを教えてください。

```cpp
#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "env.h"

void setup() {
  M5.begin();
  WiFi.begin(SSID, PASS);
  M5.Lcd.setTextSize(2.5);
  M5.Lcd.println("Connecting to internet...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }

  M5.Lcd.println("");
  M5.Lcd.println("Connected!");
  M5.Lcd.print("IP: ");
  M5.Lcd.println(WiFi.localIP());

  HTTPClient http;
  http.begin("https://lab.crssrds.jp/test/data.html"); // サーバー側のIP
  int httpCode = http.GET();
  M5.Lcd.print("http status: ");
  M5.Lcd.println(httpCode);
  if (httpCode > 0) {
    String payload = http.getString();
    M5.Lcd.println("Response:");
    M5.Lcd.println(payload);
  } else {
    M5.Lcd.println("Request failed");
  }
  http.end();
}

void loop() {
}
```