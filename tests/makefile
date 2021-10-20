# makefile for testing cs255's assignment 2
# author: @csd4802

CC = gcc
COPT = -ansi -pedantic -Wall -Wextra -O2

.PHONY: help

all: help
	gcc test.c  mystring_ptrs.c -Wall -std=c90 -pedantic -Wextra -O2
	./a.out

.PHONY: compile

compile:
	$(CC) $(COPT) -c mystring_ptrs.c
	$(CC) $(COPT) -c mystring_ars.c	

.PHONY: compile_arrays

compile_arrays:
		$(CC) $(COPT) -c mystring_ars.c

.PHONY: compile_ptrs

compile_ptrs:
		$(CC) $(COPT) -c mystring_ptrs.c

.PHONY: link

link : compile
	$(CC) $(COPT) test.c mystring_ptrs.o -o pointers
	$(CC) $(COPT) test.c mystring_ars.o -o arrays

.PHONY: link_arrays

link_arrays : compile_arrays
	$(CC) $(COPT) test.c mystring_ars.o -o arrays

.PHONY: link_pointers

link_pointers : compile_ptrs
	$(CC) $(COPT) test.c mystring_ptrs.o -o pointers

.PHONY: test

test: link
	sh test.sh ./pointers tests/
	sh test.sh ./arrays tests/

.PHONY: test_arrays

test_arrays: link_arrays
	sh test.sh ./arrays tests/

.PHONY: test_pointers

test_pointers: link_pointers
	sh test.sh ./pointers tests/

.PHONY: clean

clean:
	rm -rf ./a.out
	rm -rf *.o
	rm -rf pointers
	rm -rf arrays

.PHONY: help

help:
	@printf "\tTo test the pointers implementation run -> make test_pointers\n\n"
	@printf "\tTo test the arrays implementation run -> make test_arrays\n\n"
	@printf "\tTo test everything run -> make test\n\n"
	@printf "\tMake should just provide an ./a.out file based on pointers implementation\n\n"
	@printf "\tMake clean will remove object files and executables\n\n"
