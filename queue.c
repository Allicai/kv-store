#include "queue.h"

// Exercise 2: implement a concurrent queue

// TODO: define your synchronization variables here
// (hint: don't forget to initialize them)


// add a new request to the end of the queue
// NOTE: queue must be implemented as a monitor
void enqueue(queue_t *q, req_t *t) {
    /* TODO: your code here */


}

// pope a request from the head of the queue.
// if the queue is empty, the thread should wait.
// NOTE: queue must be implemented as a monitor
req_t* dequeue(queue_t *q) {
    /* TODO: your code here */


    return NULL;
}

// return the number of requests in the queue.
// NOTE: queue must be implemented as a monitor
int queue_count(queue_t *q) {
    /* TODO: your code here */


    return 0;
}
