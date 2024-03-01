#include "BCD7Seg.h"

#include "../common/macros.h"

#include "../MCAL/DIO.h"
#include "util/delay.h"

void BCD7Seg_init() {
  DIO_setPinDirection(BCD7SEG_PIN_A, DIO_OUTPUT);
  DIO_setPinDirection(BCD7SEG_PIN_B, DIO_OUTPUT);
  DIO_setPinDirection(BCD7SEG_PIN_C, DIO_OUTPUT);
  DIO_setPinDirection(BCD7SEG_PIN_D, DIO_OUTPUT);

  for (DIO_pin_t const *pPin = _COM; pPin < END(_COM); pPin++) {
    DIO_setPinDirection(*pPin, DIO_OUTPUT);
    DIO_setPinLevel(*pPin, DIO_HIGH);
  };
}

static u16 _value;

inline void BCD7Seg_set(u16 value) { _value = value; }

void BCD7Seg_refresh() {
  u8 bcd;
  u16 value = _value;
  for (DIO_pin_t const *pPin = _COM; pPin < END(_COM); pPin++) {
    bcd = value % 10;
    DIO_setPinLevel(*pPin, DIO_LOW);
    DIO_setPinLevel(BCD7SEG_PIN_A, bcd & 0x1);
    DIO_setPinLevel(BCD7SEG_PIN_B, bcd & 0x2);
    DIO_setPinLevel(BCD7SEG_PIN_C, bcd & 0x4);
    DIO_setPinLevel(BCD7SEG_PIN_D, bcd & 0x8);
    value /= 10;
    _delay_ms(BCD7SEG_UNIT_DELAY_MS);
    DIO_setPinLevel(*pPin, DIO_HIGH);
    if (!value) {
      break;
    }
  };
}
