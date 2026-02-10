#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Details{
	int rc, wc;
	sem_t mutex, w_mutex, rw_mutex, r_mutex;
} details;

void *write(void *args){
	details *d = (details *)args;
	sem_wait(&(d->w_mutex));
	d->wc++;
	if(d->wc == 1){
		sem_wait(&(d->r_mutex));
	}
	//provided writer finished
	sem_post(&(d->rw_mutex));
	return d;
}

