build:
	gcc -g -I/libfdr -c main.c
	gcc -g -o main main.o libfdr/libfdr.a