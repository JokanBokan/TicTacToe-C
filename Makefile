CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/main.c src/board.c src/utils.c
TARGET = tictactoe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)