TARGET = bit8_test

OBJS += $(wildcard *.c)
OBJS += $(wildcard *.cc)

CFLAGS = -std=c++11

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(wildcard *.o)
	rm -f $(TARGET)
