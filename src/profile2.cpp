#include <Keyboard.h>
#include "MediaKeyboard.h"
#include "profile.h"
#include "hardware.h"

button_func_t button_func_map_2[NUM_BUTTONS] =
    {
        {
            "Alt",
            {KEY_LEFT_ALT, NULL, NULL},
            false,
            false,
        },
        {
            "Tab",
            {KEY_TAB, NULL, NULL},
            false,
            false,
        },
        {
            "Win <-",
            {KEY_LEFT_GUI, KEY_LEFT_ARROW, KEY_ESC},
            true,
            false,
        },
        {
            "Win ->",
            {KEY_LEFT_GUI, KEY_RIGHT_ARROW, KEY_ESC},
            true,
            false,
        },
        {
            "Win ^",
            {KEY_LEFT_GUI, KEY_UP_ARROW, KEY_ESC},
            true,
            false,
        },
        {
            "Win v",
            {KEY_LEFT_GUI, KEY_DOWN_ARROW, KEY_ESC},
            true,
            false,
        },
        {
            "7: N/A",
            {NULL, NULL , NULL},
            false,
            false,
        },
        {
            "8: N/A",
            {NULL, NULL, NULL},
            false,
            false,
        },
        {
            "N/A",
            {NULL, NULL, NULL},
            false,
            true,
        },
        {
            "P1 Quick Switch",
            {KEY_PROFILE1_TEMP, NULL, NULL},
            false,
            false,
        },
        {
            "N/A",
            {NULL, NULL, NULL},
            true,
            false,
        },
        {
            "Profile Switch",
            {NULL, NULL, NULL},
            false,
            false,
        },
};

                                    /* both directions per encoder */
button_func_t encoder_func_map_2[NUM_ENCODERS * 2] =
{
        {
            "N/A",
            {NULL, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "N/A",
            {NULL, NULL, NULL},
            false,  /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "N/A",
            {NULL, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "N/A",
            {NULL, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
};

