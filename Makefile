# Les parametres de compilation et edition des liens
# pour compiler un programme sous GNU/Linux+Xenomai

CFLAGS=-Wall $(shell xeno-config --skin=alchemy --cflags)
LDFLAGS= $(shell xeno-config --skin=alchemy --ldflags)

temp: temp.o

clean:
	rm -f *.o temp

