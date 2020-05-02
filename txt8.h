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
	uint8_t char_count;
	uint8_t* bitmap;
} Font;

// Display mode. Mode is bitmasks, so, you may combine bits.
// \9 would be inverted strike through, for example.
enum Mode {
  Inverted      = 0b00001, // \1
  Underline     = 0b00010, // \2
  Overline      = 0b00100, // \4
  StrikeThrough = 0b01000, // \8
  Normal        = 0b10000, // \16
};

// N == number of bytes in a buffer
template<int N>
class Txt8 {
public:
  static uint8_t buf[N];

  // Clears current buffer
  static void clear();

  // Draws string into buffer and returns pointer to the last char drawn
  static const char *echo(const char *message, const Font* font);
};

template<int N> uint8_t Txt8<N>::buf[N];

#include "txt8_impl.hpp"
}

#endif
