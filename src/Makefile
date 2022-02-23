CC = gcc
CFLAGS = -O3 -std=gnu99 -pedantic -Wall $$warnflags_2
DBGFLAGS = -ggdb3 -DDEBUG -std=gnu99 -pedantic -Wall $$warnflags_2
export warnflags_1 = -Wreturn-stack-address -pedantic -Wall -Wextra -Wwrite-strings
export warnflags_2 = -Wfloat-equal -Wtype-limits -Wpointer-arith  -Wshadow -Wno-unused -fno-diagnostics-show-option -fno-builtin -fno-inline -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0

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
        find . -type f | xargs touch
        rm -rf $(OBJS)
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

#Parallelizing computation (here: 8 Tasks in parallel)!
# make -j8
