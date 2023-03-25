CC = g++
LIBS =

BIN_DIR=bin
SRC_DIR=src
INC_DIR=include

CFLAGS = -Wall -std=c++11 -pedantic
OBJECTS = $(SRC_DIR)/main.o
HFILES = $(INC_DIR)/graph.h $(INC_DIR)/edge.h
TARGET = $(BIN_DIR)/main

%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)


.PHONY: clean

clean:
	$(RM) $(TARGET) **/*.o core **/*.gch **/*.out