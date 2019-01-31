pthreads: pthreads.o
	gcc -Wall -g -c pthreads.c
	gcc -Wall -g pthreads.o -o pthreads
