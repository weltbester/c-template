CC = gcc
CFLAGS = -std=c11 -pedantic -Wall -Wextra -Wwrite-strings -O3
DBGFLAGS = -std=c11 -pedantic -Wall -Wextra -Wwrite-strings -ggdb3 -DDEBUG
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
DBGOBJS=$(patsubst %.c,%.dbg.o,$(SRCS))
.PHONY: clean cleaner backup  doc depend all
all: myProgram myProgram-debug
myProgram: $(OBJS)
	   gcc -o $@ -O3 $(OBJS)
myProgram-debug: $(DBGOBJS)
		 gcc -o $@ -ggdb3 $(DBGOBJS)
%.dbg.o: %.c
	 gcc $(DBGFLAGS) -c -o $@ $<
clean:
	#rm -f myProgram myProgram-debug *.o *.c~ *.h~
	-$(RM) *.o *#* *~
cleaner: clean
	rm myProgram myProgram-debug
cleanest: clean
	rm *.c *.h Makefile
doc:
	doxygen
backup: %.c %.h Makefile
	cp $? /Volumes/NITRO-NV\ 1/Skripte/Transfer
	touch backup
depend:
	makedepend $(SRCS)
	makedepend -a -o .dbg.o  $(SRCS)
# DO NOT DELETE
anotherFile.o: anotherHeader.h someHeader.h
oneFile.o: oneHeader.h someHeader.h
