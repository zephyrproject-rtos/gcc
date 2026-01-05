#if   defined __RX_64BIT_DOUBLES__
#undef FLOAT_ONLY
#elif defined __RX_32BIT_DOUBLES__
#define DF SF
#define FLOAT_ONLY
#else
#error "RX double size not defined"
#endif

#define LIBGCC2_FLOAT_BIT_ORDER_MISMATCH 0
