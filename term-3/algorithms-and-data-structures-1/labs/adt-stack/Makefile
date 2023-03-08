CC = g++
LIBS =
CFLAGS = -Wall -std=c++11
OBJECTS = main.o rpn.o
HFILES = mystack.hpp rpn.hpp
TARGET = main.out

%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)


.PHONY: clean

clean:
	$(RM) $(TARGET) *.o core *.gch *.out