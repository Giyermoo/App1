CC=gcc  # Cambia a g++ si estás usando C++
CFLAGS=-Wall -Wextra -g
LDFLAGS=
OBJ=MAIN.o metrics.o utils.o

app: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

MAIN.o: main.c metrics.h utils.h
	$(CC) $(CFLAGS) -c $<

metrics.o: metrics.c metrics.h utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) app

.PHONY: clean
