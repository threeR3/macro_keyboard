#ifndef MEDIAKEYBOARD_H
#define MEDIAKEYBOARD_H

#include <Arduino.h>


#define DO_KEYBOARD 1

#ifdef DO_KEYBOARD
#if !defined(USBCON) || !defined(USBD_USE_HID_COMPOSITE)

#error "USB HID not enabled! Select 'HID' in the 'Tools->USB interface' menu."

#else

#define VOLUME_UP         0xFFE9
#define VOLUME_DOWN       0xFFEA
#define VOLUME_MUTE       0xFFE2
#define MEDIA_PLAY_PAUSE  0xFFCD
#define MEDIA_STOP        0xFFB7
#define MEDIA_NEXT        0xFFB5
#define MEDIA_PREV        0xFFB6
#define MEDIA_FAST_FOWARD 0xFFB3
#define MEDIA_REWIND      0xFFB4

 
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