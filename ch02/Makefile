CC := g++
CFLAGS := -Wall -Wpedantic -std=c++20 -g
SRCS := $(wildcard *.cc)
.PHONY: all clean
all: $(patsubst %.cc,%.elf,$(SRCS))
%.elf: %.cc
	$(CC) $(CFLAGS) -o $@ $<
clean:
	-rm $(wildcard *.elf)
