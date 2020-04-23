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

enum Mode {
  Normal        = 0b11111, // \31
  Inverted      = 0b00001, // \1
  Underline     = 0b00010, // \2
  Overline      = 0b00100, // \4
  StrikeThrough = 0b01000  // \8
};

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
  static const char *Echo(const char *message, const Font* font)
  {
    Clear();

    uint8_t* msg_p = (uint8_t*)message; // Current char pointer

    // Pointer to max possible char in the message
    uint8_t* max_msg_p = msg_p + (N / font->width);

    uint8_t *font_p = NULL; // Pointer to current char font bitmap
    uint8_t *buf_p = buf;   // Pointer to current buffer position
    uint8_t c;              // Current char
    uint8_t mode = Normal;  // Normal mode

    while ((c = *msg_p++) && (msg_p < max_msg_p)) {
      // Current char sets the mode
      if (c < ' ') {
        mode = c;
        continue;
      }

      // Start of a char in a font
      font_p = font->bitmap + ((c - ' ') * font->width);

      // Copy & mask char
      for (uint8_t x = 0; x < font->width; x++) {
        uint8_t res_c = *(font_p++);

        if (mode == Inverted) {
          res_c = ~res_c;
        }

        if (mode == Underline) {
          res_c |= 0b10000001;
        }

        if (mode == Overline) {
          res_c |= 0b10000000;
        }

        if (mode == StrikeThrough) {
          res_c |= 0b00010000;
        }

        *(buf_p++) = res_c;
      }
    }

    return (const char*)msg_p;
  }
};

template<int N> uint8_t Txt8<N>::buf[N];

}

#endif


// 	while((*c != 0) && (message - c < buf->size / font->width)) {
// 		char current_char = *c;

// 		if (current_char < ' ') {
// 		  mask = 0x1;
// 		  c++;
// 		  continue;
// 		}

// 		if ((current_char > font->last_char) || (current_char < ' ')) {
// 			current_char = ' ';
// 		}

// 		current_char -= ' ';

// //memcpy(buffer_pointer, font_bitmap + (current_char * font->width), font->width);
// 		for (char* b = font_bitmap + (current_char * font->width); b < font_bitmap + (current_char * font->width) + font->width; b++) {
// 			*(buffer_pointer++) = (*b) | mask;
// 		};

// 		//buffer_pointer += font->width;

// 		c++;
// 	}
