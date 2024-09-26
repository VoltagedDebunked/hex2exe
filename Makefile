CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/main.c
OUT = main

build: $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)