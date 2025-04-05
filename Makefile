CC=gcc  # Cambia a g++ si estás usando C++
CFLAGS=-Wall -Wextra -g
LDFLAGS=
OBJ=MAIN.o METRICS.o utils.o

app: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

MAIN.o: MAIN.c METRICS.h utils.h
	$(CC) $(CFLAGS) -c $<

METRICS.o: METRICS.c METRICS.h utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) app

.PHONY: clean
