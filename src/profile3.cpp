#include <Keyboard.h>
#include "MediaKeyboard.h"
#include "profile.h"
#include "hardware.h"

button_func_t button_func_map_3[NUM_BUTTONS] =
    {
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
        {
            "NUT turbo",
            {'N', 'U', 'T'},
            false,
            true,
        },
};

                                    /* both directions per encoder */
button_func_t encoder_func_map_3[NUM_ENCODERS * 2] =
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

