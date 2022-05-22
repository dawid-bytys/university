.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc

MAIN = main
MULTIPLIER = multiplier
SEM = sem
UTILS = utils
PROCESSES_COUNT = 3
CRITICAL_SECTIONS_COUNT = 3
STORE = store.txt

EXEC_MAIN = $(MAIN).x
EXEC_MULTIPLIER = $(MULTIPLIER).x

OBJ_MULTIPLIER = $(MULTIPLIER).o
OBJ_MAIN = $(MAIN).o
OBJ_UTILS = $(UTILS).o
OBJ_SEM = $(SEM).o

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_MULTIPLIER) $(EXEC_MAIN)

$(EXEC_MAIN): $(OBJ_MAIN) $(OBJ_UTILS) $(OBJ_SEM)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_MULTIPLIER): $(OBJ_MULTIPLIER) $(OBJ_UTILS) $(OBJ_SEM)
	$(CO) -o $@ $(LFLAGS) $^

.PHONY: run

run: $(EXEC_MULTIPLIER)
	./$(EXEC_MULTIPLIER) $(EXEC_MAIN) $(STORE) $(PROCESSES_COUNT) $(CRITICAL_SECTIONS_COUNT)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))