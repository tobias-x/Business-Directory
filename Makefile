dict: dict.o
	gcc -o dict dict.o

dict.o: dict.c llbuilder.c llbuilder.h
	gcc -c dict.c
