CC = gcc
CFLAGS=-O2 -Wall
LIBS = -lpthread
CINC = -I$(CSAPP2DIR)/include
CSAPPLIB = csapp.o

all: dns echoclient echoserveri echoclient-rpt

dns: dns.c $(CSAPPLIB)
	$(CC) $(CINC) $(CFLAGS) dns.c $(CSAPPLIB) $(LIBS) -o dns

echoclient: echoclient.c $(CSAPPLIB)
	$(CC) $(CINC) $(CFLAGS) echoclient.c $(CSAPPLIB) $(LIBS) -o echoclient

echoclient-rpt: echoclient-rpt.c $(CSAPPLIB)
	$(CC) $(CINC) $(CFLAGS) echoclient-rpt.c $(CSAPPLIB) $(LIBS) -o echoclient-rpt

echoserveri: echoserveri.c $(CSAPPLIB)
	$(CC) $(CINC) $(CFLAGS) echoserveri.c $(CSAPPLIB) $(LIBS) -o echoserveri
