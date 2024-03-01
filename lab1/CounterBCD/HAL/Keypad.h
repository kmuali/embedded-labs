#ifndef _KEYPAD_H
#define _KEYPAD_H

/*       COL_1   COL_2   COL_3   COL_4
 * ROW_1     1       2       3       4
 * ROW_2     5       6       7       8
 * ROW_3     9      10      11      12
 * ROW_4    13      14      15      16
 *
 * Rows are outputs
 * Cols are inputs
 */

#include "../MCAL/DIO.h"
#include "../common/macros.h"

#ifndef KEYPAD_IS_MATRIX
#define KEYPAD_IS_MATRIX 1
#endif

typedef enum : u8 {
  KEYPAD_KEY_NONE = 0,
  KEYPAD_KEY_1 = 1,
  KEYPAD_KEY_2 = 2,
  KEYPAD_KEY_3 = 3,
  KEYPAD_KEY_4 = 4,
  KEYPAD_KEY_5 = 5,
  KEYPAD_KEY_6 = 6,
  KEYPAD_KEY_7 = 7,
  KEYPAD_KEY_8 = 8,
  KEYPAD_KEY_9 = 9,
  KEYPAD_KEY_10 = 10,
  KEYPAD_KEY_11 = 11,
  KEYPAD_KEY_12 = 12,
  KEYPAD_KEY_13 = 13,
  KEYPAD_KEY_14 = 14,
  KEYPAD_KEY_15 = 15,
  KEYPAD_KEY_16 = 16,
} Keypad_key_t;

#if KEYPAD_IS_MATRIX
static const DIO_pin_t _ROWS[4] = {
    DIO_PC5,
    DIO_PC4,
    DIO_PC3,
    DIO_PC2,
};
#endif

static const DIO_pin_t _COLS[4] = {
    DIO_PD7,
    DIO_PD6,
    DIO_PD5,
    DIO_PD3,
};

void Keypad_init();
void Keypad_getPressedKey(Keypad_key_t *pKey);
void Keypad_waitUntilReleaseKey(Keypad_key_t key);
u8 Keypad_isPressedKey(Keypad_key_t key);

#endif
