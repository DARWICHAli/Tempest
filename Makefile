CC ?= g++
CFLAGS ?= -Wall -Wextra -g -pthread
LDFLAGS ?= -pthread
LDLIBS ?= -lrt

PROGS = main

ALL = $(PROGS)

.PHONY: all
all: $(ALL)

$(PROGS): %: %.o
	$(CC) $(CFLAGS)  $^ $(LDLIBS) -o $@

$(PROGS:%=%.o): %.o: %.cpp

.PHONY: clean

clean:
	rm -f $(ALL) $(ALL:%=%.o)
