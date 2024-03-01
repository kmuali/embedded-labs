#ifndef _DIO_H
#define _DIO_H

#include "../common/types.h"

typedef enum : u8 {
  DIO_INPUT = 0,
  DIO_OUTPUT = 1,
} DIO_direction_t;

typedef enum : u8 {
  DIO_LOW = 0,
  DIO_HIGH = 1,
} DIO_level_t;

typedef enum : u8 {
  DIO_PA = 0xA0,
  DIO_PB = 0xB0,
  DIO_PC = 0xC0,
  DIO_PD = 0xD0,
} DIO_port_t;

/* Block to generate DIO_pin_t
 * enum {DIO_PA0 = 0xA0, DIO_PA1 = 0xA1, ..., DIO_PD7 = 0xD7}
 */
#define _DIO_ENUM(X)                                                           \
  DIO_P##X##0 = 0x##X##0, DIO_P##X##1 = 0x##X##1, DIO_P##X##2 = 0x##X##2,      \
  DIO_P##X##3 = 0x##X##3, DIO_P##X##4 = 0x##X##4, DIO_P##X##5 = 0x##X##5,      \
  DIO_P##X##6 = 0x##X##6, DIO_P##X##7 = 0x##X##7
typedef enum : u8 {
  _DIO_ENUM(A),
  _DIO_ENUM(B),
  _DIO_ENUM(C),
  _DIO_ENUM(D),
} DIO_pin_t;

void DIO_setPortDirection(DIO_port_t port, DIO_direction_t direction);

void DIO_setPortValue(DIO_port_t port, u8 value);

u8 DIO_getPortValue(DIO_port_t port);

void DIO_setPinDirection(DIO_pin_t pin, DIO_direction_t direction);

void DIO_setPinLevel(DIO_pin_t pin, DIO_level_t level);

u8 DIO_getPinLevel(DIO_pin_t pin);

void DIO_setPullUpDisable(DIO_level_t level);

#endif
