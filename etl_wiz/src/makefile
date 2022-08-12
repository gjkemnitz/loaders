INCLUDES=-I../include

CC=gcc

CFILES=entry_point.c
CFLAGS=-Wall -Werror -ansi

OBJS=entry_point.o

%.o: %.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: etl_wiz

clean:
	$(RM) $(OBJS) etl_wiz

etl_wiz: $(OBJS)
	$(CC) $(DEBUGFLAG) -o etl_wiz $(OBJS)
