/*
 * Effects specific for staircase.
 */

#include "FX.h"

/*
  Wipes a segment on, from the center to the outside
*/
uint16_t WS2812FX::mode_wipe_on(void) {
  if (now > SEGENV.aux0) {
    SEGENV.aux0 = now + 200;

    if (SEGMENT.getOption(SEG_OPTION_ON)) {
        if (SEGENV.aux1 < SEGLEN) {
          SEGENV.aux1 += 1;
        }
    } else {
        if (SEGENV.aux1 > 0) {
          SEGENV.aux1 -= 1;
        }
    }
  }

  int long half = SEGLEN/2;
  int long left = half - SEGENV.aux1;
  int long right = half + SEGENV.aux1;

  for (int i = 0; i < SEGLEN; i++) {
    if ((i > left) && (i < right)) {
      setPixelColor(i, SEGCOLOR(0));
    } else {
      setPixelColor(i, BLACK);
    }
  }

  return FRAMETIME;
}
