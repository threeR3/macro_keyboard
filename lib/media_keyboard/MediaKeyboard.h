#ifndef MEDIAKEYBOARD_H
#define MEDIAKEYBOARD_H

#include <Arduino.h>


#define DO_KEYBOARD 1

#ifdef DO_KEYBOARD
#if !defined(USBCON) || !defined(USBD_USE_HID_COMPOSITE)

#error "USB HID not enabled! Select 'HID' in the 'Tools->USB interface' menu."

#else

#define VOLUME_UP 0xE9
#define VOLUME_DOWN 0xEA
#define VOLUME_MUTE 0xE2
#define MEDIA_PLAY_PAUSE 0xCD
#define MEDIA_STOP 0xB7
#define MEDIA_NEXT 0xB5
#define MEDIA_PREV 0xB6
#define MEDIA_FAST_FOWARD 0xB3
#define MEDIA_REWIND 0xB4

 
class MediaKeyboard_ {
private:
public:
	MediaKeyboard_(void);
	void begin(void);
	void end(void);
	
	void press(uint8_t mediaKey);
	void release();
};
extern MediaKeyboard_ MediaKeyboard;

#endif
#endif
#endif /* DO_KEYBOARD */