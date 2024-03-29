#ifndef SERIAL_COMMANDS_H
#define SERIAL_COMMANDS_H

#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define MOVE_MOTOR_CMD      ("MOVE_MOTOR_STEPS")
#define STOP_MOTOR_CMD      ("STOP_MOTOR")
#define MOVE_CONT_CMD       ("MOVE_MOTOR_CONT")
#define READ_SENSOR_CMD     ("READ_SENSOR")
#define PUMP_ON_CMD         ("PUMP_ON")
#define PUMP_OFF_CMD        ("PUMP_OFF")
#define LIGHT_ON_CMD        ("LIGHT_ON")
#define LIGHT_OFF_CMD       ("LIGHT_OFF")
#define LED_ON_CMD          ("LED_IND_ON")
#define LED_OFF_CMD         ("LED_IND_OFF")

typedef struct {

    const uint8_t command[32];
    uint8_t n_args;

} command_attributes;

uint8_t parse_commands(uint8_t* buf, command_attributes* command_list, uint8_t);

#endif