#include "txt8.h"
#include "txt8_font4.h"
#include <assert.h>
#include <iostream>

using namespace std;

using Buf128 = txt8::Txt8<128>;

static Buf128 screen;

void test_Clear() {
  screen.buf[0] = 1;
  screen.Clear();
  assert(screen.buf[0] == 0);
  cout << "txt8::Txt8::Clear() passed.\n";
}

void test_Echo_normal() {
  screen.Echo("1", &txt8::Font4);

  assert(screen.buf[0] == 0x44);
  assert(screen.buf[1] == 0x7E);
  assert(screen.buf[2] == 0x40);
  assert(screen.buf[3] == 0x00);

  cout << "txt8::Txt8::Echo_normal() passed.\n";
}

void test_Echo_mode_inverted() {
  screen.Echo("\1 ", &txt8::Font4);

  assert(screen.buf[0] == 0xFF);
  assert(screen.buf[1] == 0xFF);
  assert(screen.buf[2] == 0xFF);
  assert(screen.buf[3] == 0xFF);

  cout << "txt8::Txt8::Echo_mode_inverted() passed.\n";
}

int main() {
  test_Clear();
  test_Echo_normal();
  test_Echo_mode_inverted();

  return 0;
}
