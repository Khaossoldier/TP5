CC = gcc

CFLAGS = -Wall -Werror -ansi -pedantic

CFLAGS += -D_XOPEN_SOURCE=500

CFLAGS += -g


## Cibles principales

all: multif



## Compilation séparée

multif.o: multif.c
	${CC} ${CFLAGS} -c $<


multif: multif.o
	${CC} ${CFLAGS} -o $@ $^
