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
	rm -fr $(PWD)
	rm -rf *.aux *.log *.out *.toc *.eps *.data *.o *.hi *~ \#*\# egeberg-munksgaard-G1.tar.gz egeberg-munksgaard-G1 rapport.pdf

rapport:
	pdflatex rapport.tex

archive: default rapport
	mkdir egeberg-munksgaard-G1
	cp $(SUB_TARGETS) Makefile rapport.pdf egeberg-munksgaard-G1
	tar czvf egeberg-munksgaard-G1.tar.gz egeberg-munksgaard-G1
	rm -rf egeberg-munksgaard-G1
