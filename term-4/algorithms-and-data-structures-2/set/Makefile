CC = g++
LIBS =
CFLAGS = -Wall -std=c++11
OBJECTS = main.o set_array/setArr.o set_list/setList.o
HFILES = set_array/setArr.h set_list/setList.h
TARGET = main.out

%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)


.PHONY: clean

clean:
	$(RM) $(TARGET) **/*.o core **/*.gch **/*.out