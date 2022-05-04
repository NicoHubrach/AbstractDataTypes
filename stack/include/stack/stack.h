#pragma once

#include <stdbool.h>

/**
 * Opaque type for stack
 **/
typedef struct myS stack;

/**
 * Returns either a new stack or null if the memory isnt sufficient
 **/
stack *s_create();

/**
 * Frees the given Stack
 * If the Stack is not empty, all Nodes will be freed as well
 **/
void s_destroy();

/**
 * Inserts the data into the Stack
 **/
bool s_push(stack *stapel, void *data);

/**
 * Removes the last Element of the Stack
 **/
void s_pop(stack *stapel);

/**
 * Returns a pointer to the data of the last Element of the stack
 **/
void *s_top(stack *stapel);

/**
 * Returns wether the stack is empty or not
 **/
bool s_empty(stack *stapel);
