template <int N>
void Txt8<N>::clear()
{
  memset(buf, 0, N);
};

template <int N>
const char *Txt8<N>::echo(const char *message, const Font *font)
{
  clear();

  uint8_t *msg_p = (uint8_t *)message; // Current char pointer

  // Pointer to max possible char in the message
  uint8_t *max_msg_p = msg_p + (N / font->width);

  uint8_t *font_p = NULL; // Pointer to current char font bitmap
  uint8_t *buf_p = buf;   // Pointer to current buffer position
  uint8_t c;              // Current char
  uint8_t mode = Normal;  // Normal mode

  while ((c = *msg_p++) && (msg_p < max_msg_p))
  {
    // Current char sets the mode
    if (c < ' ')
    {
      mode = c;
      continue;
    }

    // Start of a char in a font
    font_p = font->bitmap + ((c - ' ') * font->width);

    // Copy & mask char
    for (uint8_t x = 0; x < font->width; x++)
    {
      uint8_t res_c = *(font_p++);

      if (mode & Inverted)
      {
        res_c = ~res_c;
      }

      if (mode & Underline)
      {
        res_c |= 0b10000001;
      }

      if (mode & Overline)
      {
        res_c |= 0b10000000;
      }

      if (mode & StrikeThrough)
      {
        res_c |= 0b00010000;
      }

      *(buf_p++) = res_c;
    }
  }

  return (const char *)msg_p;
}
