CC = gcc
CFLAGS = -O2 -Wall

PROGS = forks execs internal external restart
all: $(PROGS)

forks: forks.c
	$(CC) $(CFLAGS) -o forks forks.c

execs: execs.c
	$(CC) $(CFLAGS) -o execs execs.c

internal: internal.c
	$(CC) $(CFLAGS) -o internal internal.c

external: external.c
	$(CC) $(CFLAGS) -o external external.c

restart: restart.c
	$(CC) $(CFLAGS) -o restart restart.c

clean:
	rm -rf *~ $(PROGS)

