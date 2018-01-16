CFLAGS=-Wall -pedantic -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion

CC=gcc-7

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%.o,$(SRCS))

all: $(PROGS)

%.o: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -rf $(PROGS)
