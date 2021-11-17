.PHONY = All clean

cc := gcc
PRO_DIR := .
CFLAGS = -I

static1:
	ar rcs lib/static/libstatic.a obj/hello.o obj/helloViet.o 

link:
	gcc obj/main.o -Llib/static -lstatic -o bin/statically-linked

Rule1:
	$(cc) -c -o obj/main.o  $(PRO_DIR)/src/main.c -I $(PRO_DIR)/inc
	$(cc) -c -o obj/hello.o  $(PRO_DIR)/src/hello.c -I $(PRO_DIR)/inc
	$(cc) -c -o obj/helloViet.o  $(PRO_DIR)/src/helloViet.c -I $(PRO_DIR)/inc


All: 
	$(cc) -o hello  $(PRO_DIR)/src/main.c $(PRO_DIR)/src/hello.c $(PRO_DIR)/src/helloViet.c -I $(PRO_DIR)/inc 
clean:
	rm -rf hello
