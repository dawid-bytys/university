.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))

EXERCISE_A = ex-a
EXERCISE_B = ex-b
EXERCISE_C = ex-c
EXERCISE_D = ex-d
EXERCISE_E = ex-e

EXEC_EXERCISE_A = $(EXERCISE_A).x
EXEC_EXERCISE_B = $(EXERCISE_B).x
EXEC_EXERCISE_C = $(EXERCISE_C).x
EXEC_EXERCISE_D = $(EXERCISE_D).x
EXEC_EXERCISE_E = $(EXERCISE_E).x

OBJS_EXERCISE_A = $(EXERCISE_A).o
OBJS_EXERCISE_B = $(EXERCISE_B).o
OBJS_EXERCISE_C = $(EXERCISE_C).o
OBJS_EXERCISE_D = $(EXERCISE_D).o
OBJS_EXERCISE_E = $(EXERCISE_E).o

LFLAGS = -Wall -std=c99 -pedantic -O

CO = gcc
LD = $(CO)

%.o: %.c
	$(CO) $(LFLAGS) -c $<

.PHONY: all
all: $(EXEC_EXERCISE_A) $(EXEC_EXERCISE_B) $(EXEC_EXERCISE_C) $(EXEC_EXERCISE_D) $(EXEC_EXERCISE_E)

$(EXEC_EXERCISE_A): $(OBJS_EXERCISE_A)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC_EXERCISE_B): $(OBJS_EXERCISE_B)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC_EXERCISE_C): $(OBJS_EXERCISE_C)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC_EXERCISE_D): $(OBJS_EXERCISE_D)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC_EXERCISE_E): $(OBJS_EXERCISE_E)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: run_a run_b run_c run_d run_e

run_a: $(EXEC_EXERCISE_A)
	./$(EXEC_EXERCISE_A)

run_b: $(EXEC_EXERCISE_B)
	./$(EXEC_EXERCISE_B)

run_c: $(EXEC_EXERCISE_C)
	./$(EXEC_EXERCISE_C)

run_d: $(EXEC_EXERCISE_D)
	./$(EXEC_EXERCISE_D)

run_e: $(EXEC_EXERCISE_E)
	./$(EXEC_EXERCISE_E)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR))