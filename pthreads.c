#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

int sharedVariable = 0;

void simpleThread(int which) {

	int num, val;

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
}

bool validateArgument(char* argument) {
	int i = 0;
	while (argument[i] != '\0') {
		if (!isdigit(argument[i])){
			return false;	
		}
		i++;
	}
	return true;
	
}

int main(int argc, char* argv[]) {

	int numberOfThreads;

	if (validateArgument(argv[1])) {
		numberOfThreads = atoi(argv[1]);	
	}
	

	printf("Number of threads: %d\n", numberOfThreads);
	
	return 0;
}
