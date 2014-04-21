CC = gcc
CFLAGS = -O2 -Wall
LDLIBS = -lpthread


hello: hello.c csapp.o
	$(CC) $(CFLAGS) -o hello hello.c csapp.o $(LDLIBS)

statcheck: statcheck.c csapp.o
	$(CC) $(CFLAGS) -o statcheck statcheck.c csapp.o $(LDLIBS)

files: files.c csapp.o
	$(CC) $(CFLAGS) -o files files.c csapp.o $(LDLIBS)

ofiles: ofiles.c csapp.o
	$(CC) $(CFLAGS) -o ofiles ofiles.c csapp.o $(LDLIBS)

ffiles: ffiles.c csapp.o
	$(CC) $(CFLAGS) -o ffiles ffiles.c csapp.o $(LDLIBS)

iswitch: iswitch.c
	$(CC) $(CFLAGS) -o iswitch iswitch.c

iswitch2: iswitch2.c
	$(CC) $(CFLAGS) -o iswitch2 iswitch2.c

csapp.o: csapp.c
	$(CC) $(CFLAGS) -c csapp.c
