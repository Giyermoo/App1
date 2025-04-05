CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =
SRC = src/main.c src/metrics.c src/utils.c
OBJ = $(SRC:.c=.o)
OUT = app1

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

.PHONY: clean all
