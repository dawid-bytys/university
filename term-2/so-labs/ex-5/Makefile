.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc

PRODUCER =  producer
CONSUMER = consumer
MAIN = main
QUEUE = queue
IN = in.txt
OUT = out.txt
BUFFER_SIZE = 5

EXEC_PRODUCER = $(PRODUCER).x
EXEC_CONSUMER = $(CONSUMER).x
EXEC_MAIN = $(MAIN).x

OBJ_PRODUCER = $(PRODUCER).o
OBJ_CONSUMER = $(CONSUMER).o
OBJ_MAIN = $(MAIN).o

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_PRODUCER) $(EXEC_CONSUMER) $(EXEC_MAIN)

$(EXEC_PRODUCER): $(OBJ_PRODUCER)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_CONSUMER): $(OBJ_CONSUMER)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_MAIN): $(OBJ_MAIN)
	$(CO) -o $@ $(LFLAGS) $^


.PHONY: run

run: $(EXEC_MAIN)
	./$(EXEC_MAIN) $(EXEC_PRODUCER) $(EXEC_CONSUMER) $(QUEUE) $(IN) $(OUT) $(BUFFER_SIZE)

diff:
	diff -s $(in) $(out)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))