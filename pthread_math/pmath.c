#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"


int count = 0;

void *threadBody(void *param){
	for(int i = 0; i < 5000000; i++){
		count++;
	}
	pthread_exit(0);
}

int main (int argc, char *argv[]){
	int NUM_THREADS = atoi(argv[1]);
	pthread_t threads[NUM_THREADS];
	long i;
	int errc;
	
	for (int i = 0; i<NUM_THREADS;i++){
		long *p = malloc(sizeof(p));
		*p=i;
		errc=pthread_create(&threads[i],NULL, &threadBody,p);
		if (errc) printf("somtething gone wrong %i (er code %i)", i,errc);
		
	}
	for (int i =0;i<NUM_THREADS;i++){
		pthread_join(threads[i],NULL);
	}
	printf("result:%i\n", count);
	pthread_exit(0);
}
