CC = g++
CFLAGS = -g -Wall -std=c++17
OBJ = main_set_calculator.o set_calculator.o
EXEC = set_calculator

all: $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC) $^

%.o: %.cc
	$(CC) -c -o $@ $<

run: clean all
	./$(EXEC) infile.txt out.txt


.PHONY: clean

clean:
	 bash -O extglob -c "rm -vf !(*.cc|*.h|"makefile"|infile.txt|README.md)"