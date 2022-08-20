INCLUDES=-I../include

CC=gcc

CFILES=entry_point.c
CFLAGS=-Wall -Werror -ansi
DEBUGFLAGS=-g

OBJS=entry_point.o \
     lang_parse.o

%.o: %.c
	$(CC) $(DEFINES) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c $< -o $@

all: etl_wiz

clean:
	$(RM) $(OBJS) etl_wiz parse_test

etl_wiz: $(OBJS)
	$(CC) $(DEBUGFLAGS) -o etl_wiz $(OBJS)

parse_test: lang_parse.o
	$(CC) $(DEBUGFLAGS) -o parse_test lang_parse.o
