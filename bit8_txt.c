#include "bit8_txt.h"

void bit8_txt_clear(bit8_txt_buffer* buf) {
  memset(buf->buf, 0, buf->size);
}

void bit8_txt_puts(bit8_txt_buffer *buf, const ssd1306_font_t* font, char* message) {
	bit8_txt_clear(buf);

	uint8_t* buffer_pointer = buf->buf;
	char* font_bitmap = (char*)font->bitmap;
	char* c = message;

	while((*c != 0) && (message - c < buf->size / font.width)) {
		char current_char = *c;

		if ((current_char > font->last_char) || (current_char < ' ')) {
			current_char = ' ';
		}

		current_char -= ' ';

		memcpy(buffer_pointer, font_bitmap + (current_char * font->width), font->width);
		buffer_pointer += font->width;

		c++;
	}
}
