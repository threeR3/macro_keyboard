#ifndef HARDWARE_H
#define HARDWARE_H
/************************************************
 * Includes 
 * *********************************************/
#include <Arduino.h>

/************************************************
 * Defines 
 * *********************************************/

#define ENCODER_1_CLK_PIN PA5
#define ENCODER_1_DAT_PIN PA4

#define ENCODER_2_CLK_PIN PA3
#define ENCODER_2_DAT_PIN PA2

#define ENCODER_1_BUT_PIN PB1
#define ENCODER_2_BUT_PIN PB0

#define BUTTON_01_PIN     PB12
#define BUTTON_02_PIN     PB13
#define BUTTON_03_PIN     PB14
#define BUTTON_04_PIN     PB15
#define BUTTON_05_PIN     PA15
#define BUTTON_06_PIN     PB3
#define BUTTON_07_PIN     PB4
#define BUTTON_08_PIN     PB5
#define BUTTON_09_PIN     PA7
#define BUTTON_10_PIN     PA6

#define NUM_BUTTONS       12
#define NUM_ENCODERS      2

#define OLED_RESET           -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_SCREEN_ADDRESS  0x3C
#define OLED_SCREEN_WIDTH    128 // OLED display width, in pixels
#define OLED_SCREEN_HEIGHT   64 // OLED display height, in pixels

/************************************************
 * Typedefs 
 * *********************************************/

typedef struct
{
    int button; /* what pin is this button on */
    int act_state; /* active HIGH or LOW */
    int t_db; /* time required to change state once pressed */
    int t_pressed;  /* time button was last pressed */
    int t_released; /* time button was last released */
    int prev_state; /* state of the button when it was last checked */

} button_hw_t;

/************************************************
 * External variables
 * *********************************************/
extern button_hw_t button_hw_map[NUM_BUTTONS];

#endif /* HARDWARE_H */