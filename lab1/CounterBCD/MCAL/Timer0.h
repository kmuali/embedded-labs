#ifndef _TIMER0_H
#define _TIMER0_H

#include <avr/io.h>

#include "../common/types.h"

typedef enum : u8 {
  TIMER0_NORMAL = (0 << WGM01) | (0 << WGM00),
  TIMER0_PWM_PHASE_CORRECT = (0 << WGM01) | (1 << WGM00),
  TIMER0_CTC = (1 << WGM01) | (0 << WGM00),
  TIMER0_PWM_FAST = (1 << WGM01) | (1 << WGM00),
} Timer0_waveform_t;

typedef enum : u8 {
  TIMER0_NONE_OC0 = (0 << COM01) | (0 << COM00),
  TIMER0_TOGGLE_OC0 = (0 << COM01) | (1 << COM00),
  TIMER0_CLEAR_OC0 = (1 << COM01) | (0 << COM00),
  TIMER0_SET_OC0 = (1 << COM01) | (1 << COM00),

} Timer0_action_t;

typedef enum : u8 {
  TIMER0_NO_CLOCK = (0 << CS02) | (0 << CS01) | (0 << CS00),
  TIMER0_PRESCALLER_1 = (0 << CS02) | (0 << CS01) | (1 << CS00),
  TIMER0_PRESCALLER_8 = (0 << CS02) | (1 << CS01) | (0 << CS00),
  TIMER0_PRESCALLER_64 = (0 << CS02) | (1 << CS01) | (1 << CS00),
  TIMER0_PRESCALLER_256 = (1 << CS02) | (0 << CS01) | (0 << CS00),
  TIMER0_PRESCALLER_1024 = (1 << CS02) | (0 << CS01) | (1 << CS00),
  TIMER0_PIN_T0_FALLING_EDGE = (1 << CS02) | (1 << CS01) | (0 << CS00),
  TIMER0_PIN_T0_RISING_EDGE = (1 << CS02) | (1 << CS01) | (1 << CS00),
} Timer0_clock_t;

void Timer0_init(Timer0_waveform_t waveform, Timer0_action_t action,
                 Timer0_clock_t clock, u8 timerCount, u8 outputCompare,
                 void (*compareMatchCallback)(), void (*overflowCallback)());
void Timer0_start();
void Timer0_stop();
void Timer0_setCount(u8 count);
u8 Timer0_getCount();
void Timer0_setOutputCompare(u8 oc);

#endif
