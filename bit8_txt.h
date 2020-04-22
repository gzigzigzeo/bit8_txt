// (c) Viktor Sokolov, https://github.com/gzigzigzeo
// MIT license
#ifndef __BIT8_TXT
#define __BIT8_TXT

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Buffer definition
typedef struct {
  uint8_t* buf;
  uint8_t size;
} bit8_txt_buffer;

// Font, height == 8 bit
typedef struct {
	uint8_t width;
	uint8_t last_char;
	uint8_t bitmap[];
} bit8_txt_font_t;

void bit8_txt_clear_buffer(bit8_txt_buffer* buf);
void bit8_txt_puts(bit8_txt_buffer *buf, const ssd1306_font_t* font, char* message)

#ifdef __cplusplus
}
#endif

#endif
