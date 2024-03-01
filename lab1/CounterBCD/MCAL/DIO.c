#include "DIO.h"

#include "../common/macros.h"

#include <avr/io.h>

inline void DIO_setPortDirection(DIO_port_t port, DIO_direction_t direction) {
  switch (port) {
  case DIO_PA:
    DDRA = direction ? 0xff : 0x00;
    break;
  case DIO_PB:
    DDRB = direction ? 0xff : 0x00;
    break;
  case DIO_PC:
    DDRC = direction ? 0xff : 0x00;
    break;
  case DIO_PD:
    DDRD = direction ? 0xff : 0x00;
    break;
  }
}

inline void DIO_setPortValue(DIO_port_t port, u8 value) {
  switch (port) {
  case DIO_PA:
    PORTA = value;
    break;
  case DIO_PB:
    PORTB = value;
    break;
  case DIO_PC:
    PORTC = value;
    break;
  case DIO_PD:
    PORTD = value;
    break;
  }
}

inline u8 DIO_getPortValue(DIO_port_t port) {
  switch (port) {
  case DIO_PA:
    return PINA;
  case DIO_PB:
    return PINB;
  case DIO_PC:
    return PINC;
  case DIO_PD:
    return PIND;
  }
}

inline void DIO_setPinDirection(DIO_pin_t pin, DIO_direction_t direction) {
  switch (pin & 0xF0) {
  case DIO_PA:
    SET_BIT(DDRA, pin & 0x0F, direction);
    break;
  case DIO_PB:
    SET_BIT(DDRB, pin & 0x0F, direction);
    break;
  case DIO_PC:
    SET_BIT(DDRC, pin & 0x0F, direction);
    break;
  case DIO_PD:
    SET_BIT(DDRD, pin & 0x0F, direction);
    break;
  }
}

inline void DIO_setPinLevel(DIO_pin_t pin, DIO_level_t level) {
  switch (pin & 0xF0) {
  case DIO_PA:
    SET_BIT(PORTA, pin & 0x0F, level);
    break;
  case DIO_PB:
    SET_BIT(PORTB, pin & 0x0F, level);
    break;
  case DIO_PC:
    SET_BIT(PORTC, pin & 0x0F, level);
    break;
  case DIO_PD:
    SET_BIT(PORTD, pin & 0x0F, level);
    break;
  }
}

inline u8 DIO_getPinLevel(DIO_pin_t pin) {
  switch (pin & 0xF0) {
  case DIO_PA:
    return GET_BIT(PINA, pin & 0x0F);
  case DIO_PB:
    return GET_BIT(PINB, pin & 0x0F);
  case DIO_PC:
    return GET_BIT(PINC, pin & 0x0F);
  case DIO_PD:
    return GET_BIT(PIND, pin & 0x0F);
  }
}

inline void DIO_setPullUpDisable(DIO_level_t level) {
  SET_BIT(SFIOR, PUD, level);
}
