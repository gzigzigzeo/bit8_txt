// (c) Viktor Sokolov, https://github.com/gzigzigzeo
// MIT license
#ifndef __BIT8_TXT
#define __BIT8_TXT

#include <stdint.h>
#include <string.h>

namespace txt8 {
// // Buffer definition
// typedef struct {
//   uint8_t* buf;
//   uint8_t size;
// } bit8_txt_buf_t;

// // Font, height == 8 bit
// typedef struct {
// 	uint8_t width;
// 	uint8_t last_char;
// 	uint8_t bitmap[];
// } bit8_txt_font_t;

// enum BIT8_TXT_MODE = {
//   BIT8_TXT_MODE_UNDERLINE = 0b00001, // \1
//   BIT8_TXT_MODE_OVERLINE  = 0b00010, // \2
//   BIT8_TXT_MODE_STHROUGH  = 0b00100, // \4
//   BIT8_TXT_MODE_INVERT    = 0b01000, // \8
//   BIT8_TXT_MODE_NORMAL    = 0b10000  // \16
// };

template <int N>
class Txt8 {
public:
  // Clears current buffer
  void Clear();

  // Draws string into buffer and returns pointer to the last char drawn
  //char *puts(char *message);
private:
  uint8_t buf[N];
};

template <int N>
void Txt8<N>::Clear() {
  memset(buf, 0, sizeof(buf));
};

};

#endif
