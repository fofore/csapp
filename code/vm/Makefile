CC=gcc
CFLAGS=-O2 

all: badrefs ptr

badrefs: badrefs.c
	$(CC) $(CFLAGS) -m32 -o badrefs badrefs.c

ptr: ptr.c
	$(CC) $(CFLAGS) -o ptr ptr.c

clean:
	rm -f *~ badrefs ptr
