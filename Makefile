CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/main.c
OUT = hex2exe

build: $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)