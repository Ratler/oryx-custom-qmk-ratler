#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif

#ifdef ACHORDION_ENABLE
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
  uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (!(1 <= row && row <= 3)) {
    return true;
  }

  switch (tap_hold_keycode) {
  // Exceptionally allow symbol layer LTs + row 0 in same-hand chords.
  case KC_BSPC:
  case KC_ESCAPE:
    return true;
    break;
    // Exceptionally allow G + J as a same-hand chord.
    // case NUM_G:
    //  if (other_keycode == KC_J) { return true; }
    //  break;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}
#endif
