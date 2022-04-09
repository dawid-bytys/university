.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc

SEND = send
SIGNAL = signal
GROUP = group

EXEC_SEND = $(SEND).x
EXEC_SIGNAL = $(SIGNAL).x
EXEC_GROUP = $(GROUP).x

OBJ_SEND = $(SEND).o
OBJ_SIGNAL = $(SIGNAL).o
OBJ_GROUP = $(GROUP).o

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_SEND) $(EXEC_SIGNAL) $(EXEC_GROUP)

$(EXEC_SIGNAL): $(OBJ_SIGNAL)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_SEND): $(OBJ_SEND)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC_GROUP): $(OBJ_GROUP)
	$(CO) -o $@ $(LFLAGS) $^


.PHONY: run_send run_group

run_send: $(EXEC_SEND)
	./$(EXEC_SEND) $(signal_type) $(signal_num)

run_group: $(EXEC_GROUP)
	./$(EXEC_GROUP) $(signal_type) $(signal_num)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))