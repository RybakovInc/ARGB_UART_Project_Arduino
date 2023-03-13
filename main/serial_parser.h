#ifndef SERIAL_PARSER_H_
#define SERIAL_PARSER_H_

#include "HardwareSerial.h"
#include "project_defs.h"

static void Read_Serial(uint8_t *data)
{
  data[0] = Serial.read();
  data[1] = Serial.read();
}

static uint8_t Map_Percents_to_Byte (uint8_t input)
{
  uint8_t output;
  output = map(input, 0, 100, 0, 255);
  return output;
}

static config_struct_t Read_Commands(config_struct_t output_str, uint8_t *data)
{
  switch(data[0])
  {
    case CMD_CHANGEPWR:
      output_str.pwrstate = data[1];
      break;
    case CMD_CHANGEBRIGHTNESS:
      output_str.brightness = Map_Percents_to_Byte(data[1]);
      break;
  }
}

extern config_struct_t Parse_Serial(config_struct_t in_struct)
{
  uint8_t incoming_data[2];
  
  
}


#endif /*SERIAL_PARSER_H*/