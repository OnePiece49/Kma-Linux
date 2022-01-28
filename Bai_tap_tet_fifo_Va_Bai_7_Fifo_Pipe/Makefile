.PHONY : all clean clientFifo serverFifo

all:
	gcc -o Myclient Myclient.c
	gcc -o Myserver Myserver.c

clientFifo:
	gcc -o clientFifo clientFifo.c

serverFifo:
	gcc -o serverFifo serverFifo.c

Myclient:
	gcc -o Myclient Myclient.c

Myserver:
	gcc -o Myserver Myserver.c

clean:
	rm -rf serverFifo
	rm -rf clientFifo
	rm -rf Myclient
	rm -rf Myserver