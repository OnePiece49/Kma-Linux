.PHONY : clean all main SegmenlDefault CoreDump

main:	
	gcc -g -o  main main.c

all:
	gcc -g -o main main.c
	gcc -g -o testProcess testProcess.c
	gcc -g -o SegmenlDefault.c SegmenlDefault

SegmenlDefault:
	gcc -g -o SegmenlDefault SegmenlDefault.c

clean:
	rm -rf main testProcess SegmenlDefault 