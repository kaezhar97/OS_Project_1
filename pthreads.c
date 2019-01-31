#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int SharedVariable = 0;

void SimpleThread(int which) {

	int num, val;

	for (num = 0; num < 20; num++) {
	
		if (random() > RAND_MAX/2){
			usleep(500);
		}

		val = SharedVariable;
		printf("***thread %d sees value %d\n", which, val);
		SharedVariable = val + 1;
	}

	val = SharedVariable;
	printf("Thread %d sees final value %d\n", which, val);
}


int main(int argc, char* argv[]) {

	SimpleThread(4);
	return 0;
}
