/* STM 32 Blue Pill Keyboard.
 *
 * 
 */

/************************************************
 * Includes 
 * *********************************************/
#include <Keyboard.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <RotaryEncoder.h>
#include "MediaKeyboard.h"
#include "logo.c"
#include "hardware.h"
#include "profile.h"


/************************************************
 * Defines
 * *********************************************/
#define PROFILE_CHANGE_BUTTON 12 /* button 12 is e2 button */
#define PROFILE_CHANGE_DWELL 1000 /* how long to hold button */

/************************************************
 * Statics
 * *********************************************/
static uint8_t cur_func_profile = 1;
static bool changing_profile = false;

static button_func_t *button_profiles[NUM_PROFILES] = {button_func_map_1, button_func_map_2, button_func_map_3};
static button_func_t *encoder_profiles[NUM_PROFILES] = {encoder_func_map_1, encoder_func_map_3, encoder_func_map_3};


/************************************************
 * Globals
 * *********************************************/
RotaryEncoder encoder_1(ENCODER_1_CLK_PIN, ENCODER_1_DAT_PIN, 
                        RotaryEncoder::LatchMode::FOUR0);

RotaryEncoder encoder_2(ENCODER_2_CLK_PIN, ENCODER_2_DAT_PIN, 
                        RotaryEncoder::LatchMode::FOUR0);

Adafruit_SSD1306 display(OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, &Wire, 
                         OLED_RESET);


/************************************************
 * Foward Declarations 
 * *********************************************/
void oled_onoff(bool onoff);
void oled_func_msg(char * word);

/************************************************
 * Function Implementations
 ***********************************************/
void oled_protect(bool just_turned_on)
{
    static uint32_t last_on_time;

    uint32_t cur_time = millis();

    if(cur_time - last_on_time >= 5000 && just_turned_on == false)
    {
        oled_onoff(false);
    }
    else if(just_turned_on == true)
    {
        last_on_time = millis();
    }
    /* otherwise, keep waiting */
}


void oled_onoff(bool onoff)
{
    static bool cur_onoff = false;

    if (onoff && !cur_onoff)
    {
        cur_onoff = onoff;
        oled_protect(true);
    }
    else if(!onoff && cur_onoff)
    {
        display.clearDisplay();
        display.display();
        cur_onoff = onoff;
    }
}

void oled_banner(char * text)
{
    display.setTextSize(1);
    display.setTextColor(BLACK, WHITE);
    
    display.drawRect(0, 0, OLED_SCREEN_WIDTH, 10, WHITE);
    display.fillRect(0, 0, OLED_SCREEN_WIDTH, 10, WHITE);
    display.setCursor(10, 1);
    display.println(text);
}

void oled_func_msg(char *word)
{
    oled_onoff(true);
    display.clearDisplay();


    char banner_msg[20];
    snprintf(banner_msg, 20, "Profile: %i", cur_func_profile);
    oled_banner(banner_msg);

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(5, 30);
    display.println(word);
    display.display();
}

void oled_debug(char *msg)
{
    display.drawRect(0, OLED_SCREEN_HEIGHT-8, OLED_SCREEN_WIDTH, 8, BLACK);
    display.fillRect(0, OLED_SCREEN_HEIGHT-8, OLED_SCREEN_WIDTH, 8, BLACK);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, OLED_SCREEN_HEIGHT - 8);
    display.println(msg);
    display.display();
}


void encoder_1_tick_isr()
{
  encoder_1.tick();
}

void encoder_2_tick_isr()
{
  encoder_2.tick();
}

void press_keys(uint8_t *func)
{
    if(changing_profile == true)
    {
        return;
    }

    for (int i = 0; i < MAX_BUTTON_FUNCS; i++)
    {
        uint8_t key = *(func + i);
        switch (key)
        {
        case (VOLUME_UP):
        case (VOLUME_DOWN):
        case (VOLUME_MUTE):
        case (MEDIA_PLAY_PAUSE):
        case (MEDIA_STOP):
        case (MEDIA_NEXT):
        case (MEDIA_PREV):
        case (MEDIA_FAST_FOWARD):
        case (MEDIA_REWIND):
        {
            MediaKeyboard.press(key);
            break;
        }
        case (NULL):
        {
            break;
        }
        default:
            Keyboard.press(key);
        }
    }
}

void release_keys(uint8_t *func)
{
    if(changing_profile == true)
    {
        return;
    }

    for (int i = 0; i < MAX_BUTTON_FUNCS; i++)
    {
        uint8_t key = *(func + i);
        switch (key)
        {
        case (VOLUME_UP):
        case (VOLUME_DOWN):
        case (VOLUME_MUTE):
        case (MEDIA_PLAY_PAUSE):
        case (MEDIA_STOP):
        case (MEDIA_NEXT):
        case (MEDIA_PREV):
        case (MEDIA_FAST_FOWARD):
        case (MEDIA_REWIND):
        {
            MediaKeyboard.release();
            break;
        }
        case (NULL):
        {
            break;
        }
        default:
            Keyboard.release(key);
        }
    }
}


void process_profile(uint32_t t_now)
{
    static uint8_t new_profile = 0;
    static bool button_been_released = true;
    uint32_t t_pressed  = button_hw_map[PROFILE_CHANGE_BUTTON - 1].t_pressed;
    uint32_t t_released = button_hw_map[PROFILE_CHANGE_BUTTON - 1].t_released;

    /* check if button is still being held down and it's been long enough */
    if (t_pressed > t_released &&
        t_now - t_pressed >= PROFILE_CHANGE_DWELL
        && button_been_released == true)
    {
        button_been_released = false;
        if(changing_profile == false)
        {
            new_profile = cur_func_profile;
            Keyboard.releaseAll();
            MediaKeyboard.release();
            oled_protect(true);
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(WHITE);
            display.setCursor(5, 20);
            char msg[16];
            snprintf(msg, 16, "Profile: %i", new_profile);
            display.println(msg);
            display.display();
        }
        else
        {
            cur_func_profile = new_profile;
            oled_protect(true);
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(WHITE);
            display.setCursor(20, 10);
            char msg[16];
            snprintf(msg, 16, "Profile");
            display.println(msg);
            display.setCursor(20, 10+18);
            snprintf(msg, 16, "Changed");
            display.println(msg);
            display.display();
            delay(500); /* force a delay here */
        }
        changing_profile = !changing_profile;
    }
    else if (t_released > t_pressed)
    {
        /* we've released the button after holding it for at least
           PROFILE_CHANGE_DWELL. 
        */ 
       button_been_released = true;
    }

    if (changing_profile == true)
    {
        static uint32_t en_pos = 0;
        static uint32_t last_change_time = 0; /* to slow down encoder */
        int new_pos = encoder_2.getPosition();
        if (en_pos != new_pos)
        {
            if (t_now - last_change_time > 100)
            {
                last_change_time = t_now;
                if (new_pos < en_pos)
                {
                    if(new_profile > 1) new_profile--;
                }
                else
                {
                    if(new_profile < NUM_PROFILES) new_profile++;
                }
                oled_protect(true);
                display.clearDisplay();
                display.setTextSize(2);
                display.setTextColor(WHITE);
                display.setCursor(5, 20);
                char msg[16];
                snprintf(msg, 16, "Profile: %i", new_profile);
                display.println(msg);
                display.display();
            }
            en_pos = new_pos;
        }
    }
}

void process_buttons(uint32_t t_now)
{
    button_func_t *button_func_map = button_profiles[cur_func_profile - 1];
    for (int i = 0; i < NUM_BUTTONS; i++)
    {

        if (button_hw_map[i].button == 0)
            continue;

        button_func_t button_func = *(button_func_map + i);

        int button_state = digitalRead(button_hw_map[i].button);
        uint32_t t_pressed_delta = t_now - button_hw_map[i].t_pressed;

        if (button_state == button_hw_map[i].act_state)
        {
            if (button_state != button_hw_map[i].prev_state)
            {
                button_hw_map[i].t_pressed = t_now;
                if (button_func.func != 0)
                {
                    press_keys(button_func.func);
                    if (button_func.one_shot == true &&
                        button_func.turbo == false)
                    {
                        release_keys(button_func_map[i].func);
                    }
                }
                if (changing_profile == false)
                    oled_func_msg(button_func.msg);
            }
            else if (button_state == button_hw_map[i].prev_state &&
                     button_func.turbo == true)
            {
                if (button_func.func != NULL)
                {
                    release_keys(button_func.func);
                    press_keys(button_func.func);
                }
            }
        }
        else /* button is not active state */
        {
            if (button_state != button_hw_map[i].prev_state)
            {
                button_hw_map[i].t_released = t_now;
                if (button_func_map[i].func != NULL)
                {
                    release_keys(button_func_map[i].func);
                }
            }
        }

        if (button_state != button_hw_map[i].prev_state && 
            t_pressed_delta > button_hw_map[i].t_db)
        {
            button_hw_map[i].prev_state = button_state;
        }
    }
}

void process_encoders()
{
    if (changing_profile == true)
    {
        return;
    }

    button_func_t *encoder_func_map = encoder_profiles[cur_func_profile - 1];
    button_func_t enc_1p_func = *(encoder_func_map);
    button_func_t enc_1n_func = *(encoder_func_map + 1);
    button_func_t enc_2p_func = *(encoder_func_map + 2);
    button_func_t enc_2n_func = *(encoder_func_map + 3);

    static int en_1_pos = 0;
    int new_pos_1 = encoder_1.getPosition();
    if (en_1_pos != new_pos_1)
    {
        if (new_pos_1 < en_1_pos)
        {
            press_keys(enc_1n_func.func);
            release_keys(enc_1n_func.func);
            oled_func_msg(enc_1n_func.msg);
        }
        else
        {
            press_keys(enc_1p_func.func);
            release_keys(enc_1p_func.func);
            oled_func_msg(enc_1p_func.msg);
        }
        en_1_pos = new_pos_1;
    }

    static int en_2_pos = 0;
    int new_pos_2 = encoder_2.getPosition();
    if (en_2_pos != new_pos_2)
    {
        if (new_pos_2 < en_2_pos)
        {
            press_keys(enc_2n_func.func);
            release_keys(enc_2n_func.func);
            oled_func_msg(enc_2n_func.msg);
        }
        else
        {
            press_keys(enc_2p_func.func);
            release_keys(enc_2p_func.func);
            oled_func_msg(enc_2p_func.msg);
        }
        en_2_pos = new_pos_2;
    }
}

void setup()
{
    /* initialize pins */
    for (int i = 0; i < NUM_BUTTONS; i++)
    {

        if (button_hw_map[i].button == 0)
            continue;

        if (button_hw_map[i].act_state == HIGH)
        {
            pinMode(button_hw_map[i].button, INPUT_PULLDOWN);
        }
        else
        {
            pinMode(button_hw_map[i].button, INPUT_PULLUP);
        }
    }

    attachInterrupt(digitalPinToInterrupt(ENCODER_1_CLK_PIN), 
                    encoder_1_tick_isr, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_1_DAT_PIN), 
                    encoder_1_tick_isr, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_2_CLK_PIN), 
                    encoder_2_tick_isr, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_2_DAT_PIN), 
                    encoder_2_tick_isr, CHANGE);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_SCREEN_ADDRESS))
    {
        while (1)
        {
            delay(1000); /* stay here...dirty boy */
        } 
    }

    display.ssd1306_command(SSD1306_SETCONTRAST); // 0x81    
    display.ssd1306_command(0x25);
    display.clearDisplay();
    display.drawBitmap(0, 0, logo, LOGO_WIDTH, LOGO_HEIGHT, WHITE);
    display.display();
    oled_onoff(true);
    
#if DO_KEYBOARD
    MediaKeyboard.begin();
#endif
    delay(1000); // wait long enough to let the host configure device

}


void loop()
{
    static uint32_t t_last = 0;
    uint32_t t_now = millis();

    char debug_msg[32];

    // snprintf(debug_msg, 32, "0x%x 0x%x", &en, &profile_1.encoder_map);
    // oled_debug(debug_msg);

    oled_protect(false);
    process_buttons(t_now);
    process_encoders();
    process_profile(t_now);
    t_last = t_now;
}
