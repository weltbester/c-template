# Compiler and flags
CC = clang
CFLAGS = -O3 -std=gnu99 -pedantic -Wall $(WARNFLAGS)
DBGFLAGS = -ggdb3 -DDEBUG -std=gnu99 -pedantic -Wall $(WARNFLAGS) -fsanitize=address,undefined

# Check if the platform supports -fsanitize=leak
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	ifneq ($(shell clang -fsanitize=leak -o /dev/null -x c /dev/null 2>&1 | grep ' unsupported option '),)
		DBGFLAGS += -fsanitize=address
	endif
else
	DBGFLAGS += -fsanitize=leak
endif

# Warning flags
export WARNFLAGS = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wshadow -Wno-unused -fno-diagnostics-show-option -fno-builtin -fno-inline -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0

# Source and object files
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
DBGOBJS = $(patsubst %.c,%.dbg.o,$(SRCS))

# Targets
.PHONY: all clean cleaner cleanest backup doc depend

all: myProgram myProgram-debug

myProgram: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

myProgram-debug: $(DBGOBJS)
	$(CC) -o $@ $(DBGFLAGS) $(DBGOBJS)

%.dbg.o: %.c
	$(CC) $(DBGFLAGS) -c -o $@ $<

# Clean targets
clean:
	-$(RM) *.o *#* *~
	find . -type f | xargs touch
	rm -rf $(OBJS)

cleaner: clean
	rm -f myProgram myProgram-debug

cleanest: clean
	rm -f *.c *.h Makefile

# Documentation
doc:
	doxygen

# Backup
backup: %.c %.h Makefile
	cp $? /Volumes/NITRO-NV\ 1/Skripte/Transfer
	touch backup

# Dependencies
depend:
	makedepend $(SRCS)
	makedepend -a -o .dbg.o $(SRCS)

# DO NOT DELETE
anotherFile.o: anotherHeader.h someHeader.h
oneFile.o: oneHeader.h someHeader.h

# Parallelizing computation (here: 8 Tasks in parallel)!
# make -j8
