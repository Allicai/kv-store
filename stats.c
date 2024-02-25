#include "stats.h"

// Exercise 3: fix concurrency bugs by Monitor

// FIXME:
// These statistics should be implemented as a Monitor,
// which keeps track of kvserver's status

int n_writes = 0;   // number of writes
int n_reads = 0;    // number of reads
int n_deletes = 0;  // number of deletes
int n_increases = 0;// number of increases


// TODO: define your synchronization variables here
// (hint: don't forget to initialize them)

/* your code here */
static pthread_mutex_t stats_mutex = PTHREAD_MUTEX_INITIALIZER;


// FIXME: implementation below is not thread-safe.
// Fix this by implementing them as a Monitor.

void inc_write() {
    pthread_mutex_lock(&stats_mutex);
    n_writes++;
    pthread_mutex_unlock(&stats_mutex);
}

void inc_read() {
    pthread_mutex_lock(&stats_mutex);
    n_reads++;
    pthread_mutex_unlock(&stats_mutex);
}

void inc_delete() {
    pthread_mutex_lock(&stats_mutex);
    n_deletes++;
    pthread_mutex_unlock(&stats_mutex);
}

void inc_increase() {
    pthread_mutex_lock(&stats_mutex);
    n_increases++;
    pthread_mutex_unlock(&stats_mutex);
}


int get_writes() {
    pthread_mutex_lock(&stats_mutex);
    int writes = n_writes;
    pthread_mutex_unlock(&stats_mutex);
    return writes;
}

int get_reads() {
    pthread_mutex_lock(&stats_mutex);
    int reads = n_reads;
    pthread_mutex_unlock(&stats_mutex);
    return reads;
}

int get_deletes() {
    pthread_mutex_lock(&stats_mutex);
    int deletes = n_deletes;
    pthread_mutex_unlock(&stats_mutex);
    return deletes;
}

int get_increases() {
    pthread_mutex_lock(&stats_mutex);
    int increases = n_increases;
    pthread_mutex_unlock(&stats_mutex);
    return increases;
}
