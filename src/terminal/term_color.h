#ifndef TERM_COLOR_H
#define TERM_COLOR_H
#include "ftypes.h"
namespace fth
{
#define TC_BLACK 30
#define TC_RED 31
#define TC_GREEN 32
#define TC_YELLOW 33
#define TC_BLUE 34
#define TC_MAGENTA 35
#define TC_CYAN 36
#define TC_WHITE 37
#define TERMINAL_FOREGROUND_COL(color) color
#define TERMINAL_BACKGROUND_COL(color) color + 10

#define TS_RESET 0
#define TS_BOLD 1
#define TS_UNDERLINE 4
#define TS_INVERSE 7
#define TS_BOLD_OFF 21
#define TS_UNDERLINE_OFF 24
#define TS_INVERSE_OFF 27

#define TERM_DEF2STR(a) #a

#define TERM_FG_COLOR_STR(color) "\033[;" TERM_DEF2STR(color) "m"

#define TERM_FG_BG_COLOR_STR(colorfg, colorbg) "\033[" TERM_DEF2STR(colorbg) ";" TERM_DEF2STR(colorfg) "m"

#define TERM_COLOR_RESET() "\033[0m"
} // namespace fth
#endif // TERM_COLOR_H
