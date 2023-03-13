#ifndef PROJECT_DEFS_H_
#define PROJECT_DEFS_H_

#define NUMLEDS 60
#define STRIP_PIN 4

typedef enum
{
  MODE_OFF,
  MODE_SOLID_COLOR,
  MODE_RAINBOW,
  MODE_BREATHING,
  MODE_FADE_IN_FADE_OUT,
  MODE_FADE_IN_FADE_OUT_CHANGE_COLOR,
  MODE_TWO_SOLID_COLORS
} MODES;

typedef enum
{
  CMD_CHANGEPWR,
  CMD_CHANGEMODE,
  CMD_CHANGEBRIGHTNESS,
  CMD_CHANGECOLOR,
  CMD_CHANGECENTER,
  CMD_CHANGE_STEP,
  CMD_CHANGE_SPEED
} COMMANDS;

typedef struct
{
  // General config fields
  uint8_t res:4;
  uint8_t pwrstate:1;
  uint8_t mode:3;
  //configuration, related to RGB strip
  uint8_t brightness;
  //solid color config
  uint8_t color;
  //dynamic effects config
  uint8_t center_point;
  uint8_t start_value;
  uint8_t step;
  uint8_t speed;
} config_struct_t;

#endif /*PROJECT_DEFS_H_*/