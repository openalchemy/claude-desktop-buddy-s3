#pragma once
#include <M5Unified.h>

using TFT_eSprite = M5Canvas;
using TFT_eSPI    = LovyanGFX;

typedef m5::rtc_time_t RTC_TimeTypeDef;
typedef m5::rtc_date_t RTC_DateTypeDef;

// StickS3 red LED (active-low). Main declares its own LED_PIN const.
#ifndef BUDDY_DEFAULT_LED_PIN
#define BUDDY_DEFAULT_LED_PIN 19
#endif

namespace compat {
inline void setScreenBrightness0_100(uint8_t v) {
  if (v > 100) v = 100;
  M5.Display.setBrightness((uint16_t)v * 255 / 100);
}
inline void screenPower(bool on) {
  if (on) M5.Display.wakeup();
  else    M5.Display.sleep();
}
inline float batVoltageV() { return M5.Power.getBatteryVoltage() / 1000.0f; }
inline int   batCurrentMA() { return M5.Power.getBatteryCurrent(); }
inline float vbusVoltageV() {
  int mv = M5.Power.getVBUSVoltage();
  return mv > 0 ? mv / 1000.0f : 0.0f;
}
inline int chipTempC() { return (int)temperatureRead(); }
inline void getAccel(float* ax, float* ay, float* az) {
  M5.Imu.getAccel(ax, ay, az);
}
inline void beep(uint16_t freq, uint16_t durMs) {
  M5.Speaker.tone(freq, durMs);
}
inline void powerOff() { M5.Power.powerOff(); }
}
