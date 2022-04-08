.SUFFIXES: .c .cpp .o .x .h
DIR = `basename $(CURDIR)`

NAME1 = get_ids
NAME2 = processes

EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o

EXEC2  = $(NAME2).x  
OBJS2  = $(NAME2).o

LFLAGS = -Wall -std=c99 -pedantic -O

CO = gcc

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2) 

$(EXEC1): $(OBJS1)
	$(CO) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2)
	$(CO) -o $@ $(LFLAGS) $^

.PHONY: run
run: $(EXEC2) $(EXEC1)
	./$(EXEC2) ./$(EXEC1)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
