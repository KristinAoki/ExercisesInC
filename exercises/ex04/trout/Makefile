main: trout.h util.h trout.c util.c main.c
	gcc -g trout.c util.c main.c -o main -Wall && ./main 127.0.0.1

trout: trout.h  util.h trout.c util.c
	gcc -g trout.c util.c -o trout && ./trout

util: util.h util.c
	gcc -g util.c -o util && ./util

test_util: test_util.c util.c util.h minunit.h
	gcc -g test_util.c util.c -o test_util && ./test_util
