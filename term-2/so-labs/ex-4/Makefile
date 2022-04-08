.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc

MAIN =  main

EXEC_MAIN = $(MAIN).x

OBJ_MAIN = $(MAIN).o

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_MAIN)

$(EXEC_MAIN): $(OBJ_MAIN)
	$(CO) -o $@ $(LFLAGS) $^


.PHONY: run

run: $(EXEC_MAIN)
	./$(EXEC_MAIN) $(in) $(out)

diff:
	diff -s $(in) $(out)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))