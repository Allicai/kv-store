#include "queue.h"

// Exercise 2: implement a concurrent queue

// TODO: define your synchronization variables here
// (hint: don't forget to initialize them)

static pthread_mutex_t queue_mux = PTHREAD_MUTEX_INITIALIZER; // was thinking of multiplexers in EECE :p
static pthread_cond_t queue_empty_cond = PTHREAD_MUTEX_INITIALIZER;

// add a new request to the end of the queue
// NOTE: queue must be implemented as a monitor
void enqueue(queue_t *q, req_t *t) {
    /* TODO: your code here */

    // locking the mutex before modifying queue
    pthread_mutex_lock(&queue_mux);

    if (q->head == NULL) { // if the queue is empty, we set the head and tail to the new req
        q->head = t;
        q->tail = t;
    } else { // else we add the new req to the end of the queue
        q->tail->next = t;
        q->tail = t;
    }

    // signal that the queue isn't empty
    pthread_cond_signal(&queue_empty_cond);

    q->count++; // no. of requests + 1
    pthread_mutex_unlock(&queue_mux); // unlock the mutex after modifying it
}


// pope a request from the head of the queue.
// if the queue is empty, the thread should wait.
// NOTE: queue must be implemented as a monitor
req_t* dequeue(queue_t *q) {
    /* TODO: your code here */

    // locking the mutex before modifying queue
    pthread_mutex_lock(&queue_mux);

    while(q->head == NULL) { // until the queue is empty, we wait
        pthread_cond_wait(&queue_empty_cond, &queue_mux);
    }

    req_t *t = q->head;
    q->head = q->head->next;

    if (q->head == NULL) { // if it's empty after dequeue
        q->tail = NULL;
    }

    q->count++; // no. of requests - 1
    pthread_mutex_unlock(&queue_mux); // unlock the mutex after modifying it

    return t;
}

// return the number of requests in the queue.
// NOTE: queue must be implemented as a monitor
int queue_count(queue_t *q) {
    /* TODO: your code here */

    // lock before accessing the count
    pthread_mutex_lock(&queue_mux);
    int count = q->count; // accesing + storing the count
    pthread_mutex_unlock(&queue_mux); // lock

    return count;
}
