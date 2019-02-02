unsync: pthreads.o
	gcc -Wall -g -c pthreads.c -lpthread
	gcc -Wall -g pthreads.o -o pthreads -lpthread

sync: pthreads.o
	gcc -Wall -g -c pthreads.c -lpthread -DPTHREAD_SYNC=1
	gcc -Wall -g pthreads.o -o pthreads -lpthread
