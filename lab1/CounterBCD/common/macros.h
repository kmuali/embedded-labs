#ifndef MACROS
#define MACROS

/* bit manipulation */
#define GET_BIT(var, bit) (!!((var) & (1 << (bit))))
#define SET_BIT_LOW(var, bit) ((var) &= ~(1 << (bit)))
#define SET_BIT_HIGH(var, bit) ((var) |= 1 << (bit))
#define SET_BIT(var, bit, level)                                               \
  ((level) ? SET_BIT_HIGH(var, bit) : SET_BIT_LOW(var, bit))

/* arrays */
#define LEN(a) (sizeof(a) / sizeof(*a))
#define END(a) ((a) + LEN(a))

#endif
