# Makefile para compilar app1

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/metrics.c src/utils.c
HEADERS = src/metrics.h src/utils.h
OUT = app1

all: $(OUT)

$(OUT): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
