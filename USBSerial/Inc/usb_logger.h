#ifndef _USB_LOGGER_H
#define _USB_LOGGER_H

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
#endif

#define MAX_LOG_STR_LEN 80
char mLogString[MAX_LOG_STR_LEN];

void _log( char *str );

#endif  // _USB_LOGGER_H