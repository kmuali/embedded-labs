#ifndef _BCD7SEG_H
#define _BCD7SEG_H

#include "../MCAL/DIO.h"

#define BCD7SEG_PIN_A DIO_PB0
#define BCD7SEG_PIN_B DIO_PB1
#define BCD7SEG_PIN_C DIO_PB2
#define BCD7SEG_PIN_D DIO_PB4

#define BCD7SEG_UNIT_DELAY_MS 1

static const DIO_pin_t _COM[4] = {
    DIO_PA3, // COM 1
    DIO_PA2, // COM 2
    DIO_PB5, // COM 3
    DIO_PB6, // COM 4
};

void BCD7Seg_init();
void BCD7Seg_set(u16 value);
void BCD7Seg_refresh();

#endif
