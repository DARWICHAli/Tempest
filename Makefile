#
# Ce Makefile contient les cibles suivantes :
#
# all      : compile le programme
# clean    : supprime les fichiers générés automatiquement

CC = g++
CFLAGS = -g -Wall -Wextra -Werror -Wvla

PROGS = main

all: $(PROGS)

$(PROGS): $(PROGS).cpp
	$(CC) $(CFLAGS) -o $(PROGS) $(PROGS).cpp

clean:
	rm -f $(PROGS)
