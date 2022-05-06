#pragma once

#include <stdbool.h>

/**
 * Opaque type for queue
 **/
typedef struct myQ queue;

/**
 * Returns either a new queue or null if the memory isnt sufficient
 **/
queue *q_create();

/**
 * Frees the given Queue
 * If the Queue is not empty, all Nodes will be freed as well
 **/
void q_destroy();

/**
 * Appends the data to the queue
 **/
bool q_enqueue(queue *schlange, void *data);

/**
 * Removes the first Element of the Queue
 **/
void q_dequeue(queue *schlange);

/**
 * Returns a pointer to the data of the first Element of the queue
 **/
void *q_front(queue *schlange);

/**
 * Returns wether the queue is empty or not
 **/
bool q_empty(queue *schlange);
