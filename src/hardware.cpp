/************************************************
 * Includes 
 * *********************************************/
#include <Arduino.h>
#include "hardware.h"


/************************************************
 * Statics 
 * *********************************************/

button_hw_t button_hw_map[NUM_BUTTONS] =
    {
        {
            BUTTON_01_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_02_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_03_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_04_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_05_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_06_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_07_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_08_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_09_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            BUTTON_10_PIN,
            HIGH,
            100,
            0,
            0,
            LOW,
        },
        {
            ENCODER_1_BUT_PIN,
            LOW,
            300,
            0,
            0,
            HIGH,
        },
        {
            ENCODER_2_BUT_PIN,
            LOW,
            100,
            0,
            0,
            HIGH,
        },
};
