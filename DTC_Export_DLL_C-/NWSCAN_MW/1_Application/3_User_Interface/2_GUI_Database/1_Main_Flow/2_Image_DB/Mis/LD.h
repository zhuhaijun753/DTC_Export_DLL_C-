#ifndef __LD_H__
#define __LD_H__

#ifdef __LD_C__
const uint8 LD_key[];
#else
extern const uint8 LD_key[];
#endif

#endif
