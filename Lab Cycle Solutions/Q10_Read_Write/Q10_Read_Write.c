#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Details{
	int rc, wc;
	sem_t mutex, w_mutex, rw_mutex, r_mutex;
} details;



