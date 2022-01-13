#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include "FastLED.h"

#define NUM_LEDS1 132
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds1[NUM_LEDS1];
char auth[] = "0XG-mvttwXjrvdxswgFJCAQCYUiYze4d";
char ssid[] = "HSS008";
char pass[] = "58695599890492759959";
#define PIN1 D1

int data=255;
int r,g,b;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  FastLED.addLeds<LED_TYPE, PIN1, COLOR_ORDER>(leds1, NUM_LEDS1).setCorrection( TypicalLEDStrip );
}

BLYNK_WRITE(V3)
{
  r = param[0].asInt();
  g = param[1].asInt();
  b = param[2].asInt();

  static1(r, g, b,data);
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V2)
{
data = param.asInt(); 
static1(r, g, b,data);
}
void static1(int r, int g, int b,int brightness)
{
  FastLED.setBrightness(brightness);
  for (int i = 0; i < NUM_LEDS1; i++ )
  {
    leds1[i] = CRGB(r, g, b);
  }
  FastLED.show();
}
