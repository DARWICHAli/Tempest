#
# Ce Makefile contient les cibles suivantes :
#
# all      : compile le programme
# clean    : supprime les fichiers générés automatiquement

CFLAGS = -g -Wall -Wextra -Werror -Wvla # obligatoires

PROGS = main

all: $(PROGS)

clean:
	rm -f $(PROGS)
