#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"



void *threadBody(void *param){
	for(int i = 0; i < 11; i++){
		printf("HELLO I AM THREAD %i OF PROCESS %d\n", gettid(), getpid());
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
	pthread_exit(0);
}
