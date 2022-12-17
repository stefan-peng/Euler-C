CFLAGS=-Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion
LDFLAGS=-lm

CC=cc

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%.o,$(SRCS))

all: $(PROGS)

%.o: %.c
	$(CC) $(CFLAGS)  -o $@ $< $(LDFLAGS)

clean:
	rm -rf $(PROGS)
