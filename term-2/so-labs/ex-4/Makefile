.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc

MAIN =  main
UTILS = utils
IN = in.txt
OUT = out.txt

EXEC_MAIN = $(MAIN).x

OBJ_MAIN = $(MAIN).o
OBJ_UTILS = $(UTILS).o

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_MAIN)

$(EXEC_MAIN): $(OBJ_MAIN) $(OBJ_UTILS)
	$(CO) -o $@ $(LFLAGS) $^


.PHONY: run

run: $(EXEC_MAIN)
	./$(EXEC_MAIN) $(IN) $(OUT)

diff:
	diff -s $(IN) $(OUT)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))