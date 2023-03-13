#include <FastLED.h>
#include "effects.h"
#include "project_defs.h"

CRGB strip[NUMLEDS];

config_struct_t Controller_Config;

void setup() 
{
  FastLED.addLeds<WS2812B, STRIP_PIN, GRB>(strip, NUMLEDS).setCorrection( TypicalLEDStrip );
  //FastLED.setBrightness(Controller_Config.brightness);
  Serial.begin(115200);
  pinMode(13, OUTPUT);

  Controller_Config.mode = MODE_TWO_SOLID_COLORS;
  Controller_Config.brightness = 16;
  Controller_Config.start_value = 16;
  Controller_Config.step = 10;
  Controller_Config.speed = 50;
  Controller_Config.color = COLOR_CYAN;

  Change_Brightness(Controller_Config.brightness);
}

void loop() 
{
  
  Controller_Config = Select_Mode(&strip[0], Controller_Config);
  FastLED.show();
    
  
}
