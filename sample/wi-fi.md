```cpp
#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "settings.h"

void setup() {
  M5.begin();
  WiFi.begin(SSID, PASS);
  M5.Lcd.println("Connecting to M5StackNet...");

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