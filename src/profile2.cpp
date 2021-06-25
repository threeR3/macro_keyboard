#include <Keyboard.h>
#include "MediaKeyboard.h"
#include "profile.h"
#include "hardware.h"

button_func_t button_func_map_2[NUM_BUTTONS] =
    {
        {
            "1: Play/Pause",
            {MEDIA_PLAY_PAUSE, NULL, NULL},
            true,
            false,
        },
        {
            "2: Prev",
            {MEDIA_PREV, NULL, NULL},
            true,
            false,
        },
        {
            "3: Next",
            {MEDIA_NEXT, NULL, NULL},
            true,
            false,
        },
        {
            "4: Stop",
            {MEDIA_STOP, NULL, NULL},
            true,
            false,
        },
        {
            "5: N/A",
            {NULL, NULL, NULL},
            false,
            false,
        },
        {
            "6: N/A",
            {NULL, NULL, NULL},
            false,
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
            "9: NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "10: Ctrl-Alt-.",
            {KEY_RIGHT_CTRL, KEY_RIGHT_ALT, '.'},
            false,
            false,
        },
        {
            "1e: Mute",
            {VOLUME_MUTE, NULL, NULL},
            true,
            false,
        },
        {
            "2e: ",
            {NULL, NULL, NULL},
            false,
            false,
        },
};

                                    /* both directions per encoder */
button_func_t encoder_func_map_2[NUM_ENCODERS * 2] =
{
        {
            "1e+: V+",
            {VOLUME_UP, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "1e-: V-",
            {VOLUME_DOWN, NULL, NULL},
            false,  /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "2e+: FF",
            {MEDIA_FAST_FOWARD, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
        {
            "2e-: RW",
            {MEDIA_REWIND, NULL, NULL},
            false, /* not implemented for encoders */
            false, /* not implemented for encoders */
        },
};

