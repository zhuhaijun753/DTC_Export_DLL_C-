#ifndef FATTIME_H_

#include "integer.h"

#define TimeToInt(Year,Month,Day,Hour,Minute,Second) (((Year - 1980)<<25) | \
                                                     (Month << 21) | \
                                                     (Hour << 11) |\
                                                     (Day << 16) | \
                                                     (Minute << 5) | \
                                                     (Second))

DWORD get_fattime (void);

#endif
