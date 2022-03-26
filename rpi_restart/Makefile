PIN_NUMBER = 12

CC = gcc
LDFLAGS = -lwiringPi
CCFLAGS := -DPIN_NUMBER=$(PIN_NUMBER)
TARGET = rpi_restart

SRCS = rpi_restart.c

all:
	$(CC) $(SRCS) $(CCFLAGS) -o $(TARGET) $(LDFLAGS)

clean:
	rm $(TARGET)
