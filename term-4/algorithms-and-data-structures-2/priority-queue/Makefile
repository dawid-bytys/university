CC = g++
LIBS =
CFLAGS = -Wall -std=c++11

BIN_DIR = bin
SRC_DIR = src
INC_DIR = include

OBJECTS = $(SRC_DIR)/main.o $(SRC_DIR)/PriorityQueue.o
HFILES = $(INC_DIR)/PriorityQueue.h
TARGET = $(BIN_DIR)/main.out

%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)


.PHONY: clean

clean:
	$(RM) $(TARGET) **/*.o core **/*.gch **/*.out