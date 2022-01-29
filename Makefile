CC = g++ -g
CFLAGS = -W -Wall
SOURCES = $(wildcard *.cpp)
EXEC = main

$(EXEC) : *.o
	$(CC) $(CFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm $(EXEC) *.o
