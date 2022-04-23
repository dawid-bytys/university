.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc

PRODUCER =  producer
CONSUMER = consumer
FIFO = fifo

EXEC_PRODUCER = $(PRODUCER).x
EXEC_CONSUMER = $(CONSUMER).x
EXEC_FIFO = $(FIFO).x

OBJ_PRODUCER = $(PRODUCER).o
OBJ_CONSUMER = $(CONSUMER).o
OBJ_FIFO = $(FIFO).o

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_PRODUCER) $(EXEC_CONSUMER) $(EXEC_FIFO)

$(EXEC_PRODUCER): $(OBJ_PRODUCER)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_CONSUMER): $(OBJ_CONSUMER)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_FIFO): $(OBJ_FIFO)
	$(CO) -o $@ $(LFLAGS) $^


.PHONY: run

run: $(EXEC_FIFO)
	./$(EXEC_FIFO) $(fifo) $(in) $(out) $(buffer_size)

diff:
	diff -s $(in) $(out)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))