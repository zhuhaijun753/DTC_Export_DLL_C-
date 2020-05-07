#ifndef __DTC_H__
#define __DTC_H__

#ifdef __DTC_C__
const uint8 dtc_key[];
#else
extern const uint8 dtc_key[];
#endif

#endif
