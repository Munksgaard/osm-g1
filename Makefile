CC			=gcc
CFLAGS 		=-Wall -pedantic -std=c99 -ggdb
LDFLAGS		= -lpthread
PWD 		=$(shell basename `pwd`)
SRC_FILES	=$(shell find . -name "*.c")
SUB_TARGETS	=$(shell find . -name "*.[ch]")

default: $(PWD)

$(PWD): $(SUB_TARGETS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC_FILES)

run: $(PWD)
	./$(PWD)
	
totalitarian: 
	splint -strict $(SRC_FILES) 

clean:
	rm -r $(PWD) $(PWD).dSYM
