// (c) Viktor Sokolov, https://github.com/gzigzigzeo
// MIT license
#ifndef __BIT8_TXT
#define __BIT8_TXT

#include <stdint.h>
#include <string.h>

namespace txt8 {
// Font, height == 8 bit
typedef struct {
	uint8_t width;
	uint8_t last_char;
	uint8_t bitmap[];
} font_t;

// enum BIT8_TXT_MODE = {
//   BIT8_TXT_MODE_UNDERLINE = 0b00001, // \1
//   BIT8_TXT_MODE_OVERLINE  = 0b00010, // \2
//   BIT8_TXT_MODE_STHROUGH  = 0b00100, // \4
//   BIT8_TXT_MODE_INVERT    = 0b01000, // \8
//   BIT8_TXT_MODE_NORMAL    = 0b10000  // \16
// };

template<int N> // N == number of bytes in a buffer
class Txt8 {
public:
  static uint8_t buf[N];

  // Clears current buffer
  static void Clear()
  {
    memset(buf, 0, N);
  }

  // Draws string into buffer and returns pointer to the last char drawn
  static char *Echo(char *message)
  {
    Clear();

    char* msg_p = message;         // Current char pointer
    char* font_p = NULL;           // Pointer to current char font bitmap
    char* max_p = msg_p + (N / 8); // Pointer to max possible char in the message
    char c;

    while ((c = *msg_p++) && (msg_p < max_p)) {

    }

    return msg_p;
  }
};

template<int N> uint8_t Txt8<N>::buf[N];

}

#endif
