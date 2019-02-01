#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

int sharedVariable = 0;

void* simpleThread(void* threadIndex) {

	int num, val;

	int* indexPointer = (int *)threadIndex;
	int which = *indexPointer;	


	printf("This function happens with thread %d \n", which);

	for (num = 0; num < 20; num++) {
	
		if (random() > RAND_MAX/2){
			usleep(500);
		}


		val = sharedVariable;
		printf("***thread %d sees value %d\n", which, val);
		sharedVariable = val + 1;

	}

	val = sharedVariable;
	printf("Thread %d sees final value %d\n", which, val);
	pthread_exit(NULL);
}

bool validateArgument(char* argument) {
	int i = 0;

	if (strcmp(argument, "") == true){
		return false;
	}

	while (argument[i] != '\0') {
		if (!isdigit(argument[i])){
			return false;	
		}
		i++;
	}
	return true;
	
}

int main(int argc, char* argv[]) {

	int numberOfThreads = 0;

	if (argc > 1) {
		if (validateArgument(argv[1])) {
               		numberOfThreads = atoi(argv[1]);
        	}

	}

	printf("Number of threads: %d\n", numberOfThreads);
	
	int i;
	int createFailure;
	pthread_t threads[numberOfThreads];


	int indeces[numberOfThreads];

	for (i = 0; i < numberOfThreads; i++) {
		indeces[i] = i;
	} 

	for (i = 0; i < numberOfThreads; i++) {
		
		createFailure = pthread_create(&threads[i], NULL, &simpleThread, &indeces[i]); 
		if (createFailure) { printf("Thread %d not created successfully\n", i);}
		else { printf("Thread %d created successfully\n", i);}
	}
	
	for (i = 0; i < numberOfThreads; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}
