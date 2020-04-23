csrc = $(wildcard *.c)
ccsrc = $(wildcard *.cc)
obj = $(csrc:.c=.o) $(ccsrc:.cc=.o)

test: $(obj)
	$(CXX) -std=c++11 -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(obj)
	rm -f $(TARGET).elf

