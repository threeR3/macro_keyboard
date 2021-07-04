#ifndef PROFILE_H
#define PROFILE_H
/************************************************
 * Includes 
 * *********************************************/
#include <Keyboard.h>
#include <stdint.h>
#include <stdbool.h>
#include "hardware.h"


/************************************************
 * Defines 
 * *********************************************/

#define NUM_PROFILES     3
#define MAX_BUTTON_FUNCS 3
#define MAX_MSG_LEN      24

/* These keys will quick switch to the specified profile when pressed and 
   go back when released */
#define KEY_PROFILE1_TEMP 0xFF
#define KEY_PROFILE2_TEMP 0xFE
#define KEY_PROFILE3_TEMP 0XFD 


/************************************************
 * Typedefs 
 * *********************************************/

typedef struct
{
    char msg[MAX_MSG_LEN]; /* OLED message when pressed */
    uint16_t func[MAX_BUTTON_FUNCS]; /* what keystrokes to send when pressed */
    bool one_shot; /* key action happens once per press */
    bool turbo; /* while key is held, key will act like being spammed */

} button_func_t;


extern button_func_t button_func_map_1[NUM_BUTTONS];
extern button_func_t encoder_func_map_1[NUM_ENCODERS * 2];
 

extern button_func_t button_func_map_2[NUM_BUTTONS];
extern button_func_t encoder_func_map_2[NUM_ENCODERS * 2];
 
 
extern button_func_t button_func_map_3[NUM_BUTTONS];
extern button_func_t encoder_func_map_3[NUM_ENCODERS * 2];
 


#endif /*PROFILE_H */