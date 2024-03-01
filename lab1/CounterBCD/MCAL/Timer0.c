#include "Timer0.h"

#include <avr/interrupt.h>
#include <avr/io.h>

#include "../common/macros.h"

#include <stddef.h>

static void (*_compareMatchCallback)() = NULL;
static void (*_overflowCallback)() = NULL;
static Timer0_clock_t _clock = TIMER0_NO_CLOCK;
static u8 _timerCount = 0;

inline void Timer0_init(Timer0_waveform_t waveform, Timer0_action_t action,
                        Timer0_clock_t clock, u8 timerCount, u8 outputCompare,
                        void (*compareMatchCallback)(),
                        void (*overflowCallback)()) {

  _clock = clock;
  _timerCount = timerCount;
  _compareMatchCallback = compareMatchCallback;
  _overflowCallback = overflowCallback;

  TCCR0 = waveform | action | TIMER0_NO_CLOCK;

  OCR0 = outputCompare;

  SET_BIT(TIMSK, OCIE0, _compareMatchCallback != NULL);
  SET_BIT(TIFR, OCF0, _compareMatchCallback != NULL);

  SET_BIT(TIMSK, TOIE0, _overflowCallback != NULL);
  SET_BIT(TIFR, TOV0, _overflowCallback != NULL);
}

inline void Timer0_start() {
  TCNT0 = _timerCount;
  TCCR0 |= _clock;
}

inline void Timer0_stop() {
  SET_BIT(TCCR0, CS02, 0);
  SET_BIT(TCCR0, CS01, 0);
  SET_BIT(TCCR0, CS00, 0);
}

inline void Timer0_setCount(u8 count) { TCNT0 = count; }

inline u8 Timer0_getCount() { return TCNT0; }

inline void Timer0_setOutputCompare(u8 oc) { OCR0 = oc; }

ISR(TIMER0_COMP_vect) { _compareMatchCallback(); }

ISR(TIMER0_OVF_vect) { _overflowCallback(); }
