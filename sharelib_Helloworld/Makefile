.PHONY = All clean Rule1 Rule2 shared link 

cc := gcc
PRO_DIR := .
CFLAGS := -I

env:
	LD_LIBRARY_PATH = $(PRO_DIR)/bin/shared bin/use-shared-library

Rule1:
	$(cc) -c -o obj/main.o  $(PRO_DIR)/src/main.c -I $(PRO_DIR)/inc
	$(cc) -c -o obj/hello.o  $(PRO_DIR)/src/hello.c -I $(PRO_DIR)/inc
	$(cc) -c -o obj/helloViet.o  $(PRO_DIR)/src/helloViet.c -I $(PRO_DIR)/inc

Rule2:
	gcc -c -fPIC -o $(PRO_DIR)/obj/main/main.o -fPIC $(PRO_DIR)/src/main.c   -I $(PRO_DIR)/inc
	gcc -c -fPIC -o $(PRO_DIR)/obj/hello/hello.o -fPIC $(PRO_DIR)/src/hello.c   -I $(PRO_DIR)/inc 
	gcc -c -fPIC -o $(PRO_DIR)/obj/helloViet/helloViet.o -fPIC $(PRO_DIR)/src/helloViet.c   -I $(PRO_DIR)/inc

shared:
	gcc -shared  $(PRO_DIR)/obj/hello/hello.o  $(PRO_DIR)/obj/helloViet/helloViet.o -o bin/shared/libhello.so

link:
	gcc  $(PRO_DIR)/obj/main/main.o -Lbin/shared -lhello -o bin/use-shared-library

All: 
	$(cc) -o hello  $(PRO_DIR)/src/main.c $(PRO_DIR)/src/hello.c $(PRO_DIR)/src/helloViet.c -I $(PRO_DIR)/inc 
clean:
	rm -rf hello
