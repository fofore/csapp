CC=gcc
CFLAGS=-O2 -Wall
LIBS=-lpthread

FILES = Makefile README csapp.h csapp.c echoclient.c echoclient.pl echoserveri.pl echoserveri.c echoserverp.c echoservert.c echoservers.c echo.c echoclientub.c

PROGS = echoclient echoserveri echoserverp echoservert echoservers echoclientub

all: $(PROGS)

echoclient: echoclient.c csapp.o csapp.h
	$(CC) $(CFLAGS) $(LIBS) -o echoclient echoclient.c csapp.o

echoclientub: echoclientub.c csapp.o csapp.h
	$(CC) $(CFLAGS) $(LIBS) -o echoclientub echoclientub.c csapp.o

echoserveri: echoserveri.c csapp.o csapp.h echo.o echo.h
	$(CC) $(CFLAGS) $(LIBS) -o echoserveri echoserveri.c csapp.o echo.o

echoserverimin: echoserverimin.c csapp.o csapp.h echo.o echo.h
	$(CC) $(CFLAGS) $(LIBS) -o echoserverimin echoserverimin.c csapp.o echo.o

echoserverp: echoserverp.c csapp.o csapp.h echo.o echo.h
	$(CC) $(CFLAGS) $(LIBS) -o echoserverp echoserverp.c csapp.o echo.o

echoservert: echoservert.c csapp.o csapp.h echo.o echo.h
	$(CC) $(CFLAGS) $(LIBS) -o echoservert echoservert.c csapp.o echo.o

echoservers: echoservers.c csapp.o csapp.h
	$(CC) $(CFLAGS) $(LIBS) -o echoservers echoservers.c csapp.o

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

echo.o: echo.c csapp.h
	$(CC) $(CFLAGS) -c echo.c

clean:
	rm -f *.o *~ *.exe *.tar
	rm -f $(PROGS)

echo.tar: $(FILES)
	tar cvf echo.tar $(FILES)

tar: echo.tar