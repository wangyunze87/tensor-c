CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Wpedantic -g
TARGET  = tensor.exe
OBJS    = main.o tensor.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c tensor.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-del /Q $(OBJS) $(TARGET)

.PHONY: all clean
