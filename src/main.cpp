#include "Config7inCrow.hpp"

LGFX lcd;

void setup() {
  Serial.begin(115200); 
  Serial.println();
  Serial.println("LCD Init.");

  lcd.init();
  lcd.setBrightness(255);

  lcd.fillScreen(TFT_WHITE);
  delay(250);
  lcd.fillScreen(TFT_RED);
  delay(250);
  lcd.fillScreen(TFT_GREEN);
  delay(250);
  lcd.fillScreen(TFT_BLUE);
  delay(250);
  lcd.fillScreen(TFT_BLACK);
  
  lcd.setTextSize((std::max(lcd.width(), lcd.height()) + 255) >> 8);
  lcd.setTextDatum(textdatum_t::middle_center);
  lcd.drawString("touch the screen", lcd.width() >> 1, lcd.height() >> 1);
}

void loop() {
  int32_t x, y;
  if (lcd.getTouch(&x, &y)) {
    Serial.printf("X:%d Y:%d\n",x, y);
    lcd.fillCircle(x, y, 15, TFT_WHITE);
  }
  delay(100);
}