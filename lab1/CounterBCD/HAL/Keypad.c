#include "Keypad.h"

#include "../MCAL/DIO.h"
#include "../common/macros.h"

#include <util/delay.h>

/*
 * Rows are outputs
 * Cols are inputs
 */

#define _DEBOUNCE_DELAY_MS 30
#define _PROPAGATION_DELAY_MS 1

inline void Keypad_init() {
  DIO_pin_t const *pPin;

#if KEYPAD_IS_MATRIX
  for (pPin = _ROWS; pPin < END(_ROWS); pPin++) {
    DIO_setPinDirection(*pPin, DIO_OUTPUT);
  }
#endif

  for (pPin = _COLS; pPin < END(_COLS); pPin++) {
    DIO_setPinDirection(*pPin, DIO_INPUT);
  }
}

void Keypad_getPressedKey(Keypad_key_t *pKey) {
  *pKey = KEYPAD_KEY_NONE;
  u8 colIndex;

#if KEYPAD_IS_MATRIX
  u8 rowIndex;

  for (rowIndex = 0; rowIndex < LEN(_ROWS); rowIndex++) {
    DIO_setPinLevel(_ROWS[rowIndex], DIO_LOW);
  }

  _delay_ms(_PROPAGATION_DELAY_MS);

  for (colIndex = 0; !*pKey && colIndex < LEN(_COLS); colIndex++) {
    if (DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW) {

      for (rowIndex = 0; rowIndex < LEN(_ROWS); rowIndex++) {
        DIO_setPinLevel(_ROWS[rowIndex], DIO_HIGH);
      }

      for (rowIndex = 0; !*pKey && rowIndex < LEN(_ROWS); rowIndex++) {
        DIO_setPinLevel(_ROWS[rowIndex], DIO_LOW);

        _delay_ms(_PROPAGATION_DELAY_MS);

        if (DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW) {
          *pKey = rowIndex * LEN(_ROWS) + colIndex + 1;
        }

        DIO_setPinLevel(_ROWS[rowIndex], DIO_HIGH);
      }
    }
  }
#else
  for (colIndex = 0; !*pKey && colIndex < LEN(_COLS); colIndex++) {
    if (DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW) {
      *pKey = colIndex + 1;
    }
  }
#endif
}

void Keypad_waitUntilReleaseKey(Keypad_key_t key) {
  if (!key) {
    return;
  }

  u8 colIndex;
#if KEYPAD_IS_MATRIX
  u8 rowIndex;

  rowIndex = --key / LEN(_ROWS);
  colIndex = key % LEN(_COLS);

  DIO_setPinLevel(_ROWS[rowIndex], DIO_LOW);

  _delay_ms(_PROPAGATION_DELAY_MS);

  while (DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW) {
    _delay_ms(_DEBOUNCE_DELAY_MS);
  }

  DIO_setPinLevel(_ROWS[rowIndex], DIO_HIGH);
#else
  colIndex = key - 1;

  while (DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW) {
    _delay_ms(_DEBOUNCE_DELAY_MS);
  }
#endif
}

u8 Keypad_isPressedKey(Keypad_key_t key) {
  u8 colIndex;
#if KEYPAD_IS_MATRIX
  u8 rowIndex;

  rowIndex = --key / LEN(_ROWS);
  colIndex = key % LEN(_COLS);

  DIO_setPinLevel(_ROWS[rowIndex], DIO_LOW);

  _delay_ms(_PROPAGATION_DELAY_MS);

  return DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW;

  DIO_setPinLevel(_ROWS[rowIndex], DIO_HIGH);
#else
  colIndex = key - 1;

  return DIO_getPinLevel(_COLS[colIndex]) == DIO_LOW;
#endif
}
