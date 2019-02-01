pthreads: pthreads.o
	gcc -Wall -g -c pthreads.c -lpthread
	gcc -Wall -g pthreads.o -o pthreads -lpthread
