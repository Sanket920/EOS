CC = gcc

libdynamic.so:add.o mul.o div.o
	$(CC) -shared -fPIC -o libdynamic.so add.o mul.o div.o

main.o:main.c			
	$(CC) -c -o main.o main.c 

add.o:add.c 
	$(CC) -c -o add.o add.c

mul.o:mul.c 
	$(CC) -c -o mul.o mul.c 

div.o:div.c 
	$(CC) -c -o div.o div.c	

clean:
	rm -rf * .o * .a main
