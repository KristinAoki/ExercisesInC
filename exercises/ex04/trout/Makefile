main: trout.h util.h trout.c util.c main.c
	gcc -g trout.c util.c main.c -o main -Wall

trout: trout.h  util.h trout.c util.c
	gcc -g trout trout.c util.c -o trout

util: util.h util.c
	gcc -g util.c -o util
