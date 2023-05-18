#include "ergosplit_controls.h"

#include "color.h"
#include "rgblight.h"



void keyboard_post_init_user(void) {
    setPinOutput(SINGLELEDPIN);
    rgblight_setrgb(RGB_AZURE);
    writePinHigh(SINGLELEDPIN);
}