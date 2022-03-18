.PHONY : clean all main

main:	
	gcc -o main main.c  -pthread

all:
	gcc -o main main.c -pthread
	gcc -o testThread testThread.c -pthread

clean:
	rm -rf main testThread