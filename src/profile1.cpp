#include <Keyboard.h>
#include "MediaKeyboard.h"
#include "profile.h"
#include "hardware.h"

button_func_t button_func_map_1[NUM_BUTTONS] =
    {
        {
            "Play/Pause",
            {MEDIA_PLAY_PAUSE, NULL, NULL},
            true,
            false,
        },
        {
            "Prev",
            {MEDIA_PREV, NULL, NULL},
            true,
            false,
        },
        {
            "Next",
            {MEDIA_NEXT, NULL, NULL},
            true,
            false,
        },
        {
            "Stop",
            {MEDIA_STOP, NULL, NULL},
            true,
            false,
        },
        {
            "N/A",
            {NULL, NULL , NULL},
            false,
            false,
        },
        {
            "Prev Tab",
            {KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_TAB},
            true,
            false,
        },
        {
            "Next Tab",
            {KEY_LEFT_CTRL, KEY_TAB, NULL},
            true,
            false,
        },
        {
            "N/A",
            {NULL, NULL, NULL},
            false,
            false,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "P2 Quick Switch",
            {KEY_PROFILE2_TEMP, NULL, NULL},
            false,
            false,
        },
        {
            "Mute",
            {VOLUME_MUTE, NULL, NULL},
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
button_func_t encoder_func_map_1[NUM_ENCODERS * 2] =
{
        {
            "V+",
            {VOLUME_UP, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "V-",
            {VOLUME_DOWN, NULL, NULL},
            false,  /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "FF",
            {MEDIA_FAST_FOWARD, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "RW",
            {MEDIA_REWIND, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
};

