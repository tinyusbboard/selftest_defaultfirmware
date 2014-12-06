#ifndef __MAIN_H_1c0fdb4cd9ec4e16951610dd60361c6a
#define __MAIN_H_1c0fdb4cd9ec4e16951610dd60361c6a 1

//====================================================================
// Macro to access also flash above 64kB
// http://sourceware.org/binutils/docs/as/AVR_002dModifiers.html
//--------------------------------------------------------------------
#define selftest_farptr_of(var)                  \
({ uint_farptr_t tmp;                               \
   __asm__ (                                        \
       "ldi    %A[output], lo8(%[ptrof])"  "\n\t"   \
       "ldi    %B[output], hi8(%[ptrof])"  "\n\t"   \
       "ldi    %C[output], hh8(%[ptrof])"  "\n\t"   \
       "mov    %D[output], __zero_reg__"   "\n\t"   \
       : [output]   "=d" (tmp)                      \
       : [ptrof]    "i"  (&(var))                   \
    );                                              \
   tmp;                                             \
})
//-------------------------------------------------------------------

#if (FLASHEND>131071)
#	define MYPGM_READ_BYTE(addr)	pgm_read_byte_far(addr)
#else
#	define MYPGM_READ_BYTE(addr)	pgm_read_byte(addr)
#endif

#endif