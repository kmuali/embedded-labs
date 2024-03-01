#include <stdlib.h>
#include <string.h>

#include "HAL/BCD7Seg.h"
#include "HAL/Keypad.h"

#include "MCAL/DIO.h"
#include "MCAL/Timer0.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

int main() {
  u8 c = 0;
  Keypad_key_t key;

  Keypad_init();
  BCD7Seg_init();
  BCD7Seg_set(c);
  Timer0_init(TIMER0_NORMAL, TIMER0_NONE_OC0, TIMER0_PRESCALLER_1024, 0, 0,
              NULL, BCD7Seg_refresh);
  Timer0_start();
  sei();

  while (1) {
    Keypad_getPressedKey(&key);
    switch (key) {
    case KEYPAD_KEY_1:
      c = 0;
      break;
    case KEYPAD_KEY_2:
      if (--c == -1) {
        c = 99;
      }
      break;
    case KEYPAD_KEY_3:
      if (++c == 100) {
        c = 0;
      }
      break;
    default:
      break;
    }
    if (Keypad_isPressedKey(key)) {
      BCD7Seg_set(c);
      _delay_ms(200);
    }
  }
}
