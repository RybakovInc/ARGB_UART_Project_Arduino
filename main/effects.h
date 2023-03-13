#ifndef EFFECTS_H_
#define EFFECTS_H_

#include <FastLED.h>
#include "assert.h"
#include "stdint.h"
#include "project_defs.h"
#include "Arduino.h"

//TODO: доделать все эффекты, перенести все  дефайны и общие энумераторы в общий файл

typedef enum 
{
  COLOR_BLACK,
  COLOR_RED,
  COLOR_ORANGE,
  COLOR_YELLOW,
  COLOR_GREEN,
  COLOR_CYAN,
  COLOR_BLUE,
  COLOR_MAGENTA,
  COLOR_PURPLE,
  COLOR_WHITE
} COLOR_PALLETE;

static void Enable_Strip_Control_LED()
{
  digitalWrite(13,HIGH);
}

static void Disable_Strip_Control_LED()
{
  digitalWrite(13,LOW);
}

static void Fill_Solid_Color (CRGB *strip, uint8_t color)
{
  Enable_Strip_Control_LED();
    for (uint8_t i = 0; i < NUMLEDS; i++ )
    {
      switch (color)
      {
      case COLOR_BLACK: 
        strip[i] = CRGB::Black;
        break;        
      case COLOR_RED: 
        strip[i] = CRGB::Red;
        break;
      case COLOR_ORANGE: 
        strip[i] = CRGB::Orange;
        break; 
      case COLOR_YELLOW: 
        strip[i] = CRGB::Yellow;
        break; 
      case COLOR_GREEN: 
        strip[i] = CRGB::Green;
        break;
      case COLOR_CYAN: 
        strip[i] = CRGB::Cyan;
        break; 
      case COLOR_BLUE: 
        strip[i] = CRGB::Blue;
        break;
      case COLOR_MAGENTA: 
        strip[i] = CRGB::Magenta;
        break;
      case COLOR_PURPLE: 
        strip[i] = CRGB::Purple;
        break;
      case COLOR_WHITE:
        strip[i] = CRGB::White;
        break;
      default:
        strip[i] = CRGB::BlanchedAlmond;
        break;
      }
    }
    //FastLED.show();
  Disable_Strip_Control_LED();
}
static void Change_Brightness (uint8_t target)
{
  FastLED.setBrightness(target);
}
static void Fill_Gradient (CRGB *strip, config_struct_t conf_struct)
{
  for   (uint8_t counter = 0; counter < NUMLEDS; counter++)
  {
    strip[counter] = CHSV(conf_struct.start_value + (counter * conf_struct.step), 255 , conf_struct.brightness);
  }
}

static void Fill_Two_Colors (CRGB *strip, uint8_t color1, uint8_t color2)
{
  Enable_Strip_Control_LED();
    for (uint8_t i = 0; i < NUMLEDS; i++ )
    {
      uint8_t num_similar;
      num_similar = 10;
      if (i % num_similar == i % (num_similar*2))
      {
      switch (color1)
      {
        case COLOR_BLACK: 
          strip[i] = CRGB::Black;
          break;        
        case COLOR_RED: 
          strip[i] = CRGB::Red;
          break;
        case COLOR_ORANGE: 
          strip[i] = CRGB::Orange;
          break; 
        case COLOR_YELLOW: 
          strip[i] = CRGB::Yellow;
          break; 
        case COLOR_GREEN: 
          strip[i] = CRGB::Green;
          break;
        case COLOR_CYAN: 
          strip[i] = CRGB::Cyan;
          break; 
        case COLOR_BLUE: 
          strip[i] = CRGB::Blue;
          break;
        case COLOR_MAGENTA: 
          strip[i] = CRGB::Magenta;
          break;
        case COLOR_PURPLE: 
          strip[i] = CRGB::Purple;
          break;
        case COLOR_WHITE:
          strip[i] = CRGB::White;
          break;
        default:
          strip[i] = CRGB::BlanchedAlmond;
          break;
        }
      }
      else
      {
        strip[i] = CRGB::Magenta;
      }
  
    }
}

extern config_struct_t Select_Mode(CRGB *strip, config_struct_t conf_data)
{
  switch(conf_data.mode)
  {
    case MODE_OFF:
      Fill_Solid_Color(strip, COLOR_BLACK);
      break;
    case MODE_RAINBOW:
      Fill_Gradient(strip, conf_data);
      conf_data.start_value =  conf_data.start_value + conf_data.step;
      delay(conf_data.speed);
      break;
    case MODE_SOLID_COLOR:
      Fill_Solid_Color(strip, conf_data.color);
      break;
    case MODE_TWO_SOLID_COLORS:
      Fill_Two_Colors(strip, COLOR_CYAN, COLOR_MAGENTA);
      break;

  }
  return conf_data;
}

#endif /*EFFECTS_H_*/