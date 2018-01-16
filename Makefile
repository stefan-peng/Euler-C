CFLAGS=-Wall -pedantic –std=c9x -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion

CC=gcc

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%.o,$(SRCS))

all: $(PROGS)

%.o: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -rf $(PROGS)