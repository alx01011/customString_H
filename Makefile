###################################################
#
# file: Makefile
#
# @Author:   Alexandros E. Antonakakis
# @Version:  10-02-2021
# @email:    csd4802@csd.uoc.gr
#
# Makefile
#
####################################################

CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

all: ar.exe ps.exe

ar.exe: src/main.o src/mystring_ars.o
	$(CC) $(CFLAGS) $^ -o $@

ps.exe: src/main.o src/mystring_ptrs.o
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f *.exe ./src/*.o


