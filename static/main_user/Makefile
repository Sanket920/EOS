libstatic.a: add.o mul.o div.o
	ar crv libstatic.a add.o mul.o div.o

main: add.o sub.o
	gcc -o main main.o add.o sub.o

main.o: main.c
	gcc -c -o main.o main.c

add.o:add.c
	gcc -c -o add.o add.c

mul.o:mul.c
	gcc -c -o mul.o mul.c	 

div.o:div.c
	gcc -c -o div.o div.c
	
clean:
	rm -rf *.o *.a main  		