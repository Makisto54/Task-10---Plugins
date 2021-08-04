OBJ = add.o sub.o mul.o div.o
LIBS = libadd.so libsub.so libmul.so libdiv.so
.PHONY: clean

main: $(LIBS) main.c functions.h
	gcc -g main.c -o main -ldl

libadd.so: add.o
	gcc -shared -o libadd.so add.o

libsub.so: sub.o
	gcc -shared -o libsub.so sub.o

libmul.so: mul.o
	gcc -shared -o libmul.so mul.o

libdiv.so: div.o
	gcc -shared -o libdiv.so div.o

add.o: add.c functions.h 
	gcc -fPIC -c -g add.c -o add.o

sub.o: sub.c functions.h 
	gcc -fPIC -c -g sub.c -o sub.o

mul.o: mul.c functions.h 
	gcc -fPIC -c -g mul.c -o mul.o

div.o: div.c functions.h 
	gcc -fPIC -c -g div.c -o div.o	

clean: 
	rm *o main 