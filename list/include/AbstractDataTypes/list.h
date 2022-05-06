#pragma once
#include <stdbool.h>

/**
 * Opaque type for list
 **/
typedef struct myL list;

/**
 * Returns either a new list or null if the memory isnt sufficient
 **/
list *l_create();
/**
 * Frees the given list
 * If the list is not empty, all Nodes will be freed as well
 **/
void l_destroy(list *liste);

/**
 * Returns the size of the list
 **/
int l_size(list *liste);

/**
 * Returns wether the list is empty or not
 **/
bool l_empty(list *liste);

/**
 * Appends the given data to the list
 * Return true on Success, false on failure
 * Can fail if Memory isnt sufficient
 **/
bool l_append(list *liste, void *data);
/**
 * Inserts the given Data at the index of the list
 * Returns true on Success
 * If the index is out of range, false is returned
 **/
bool l_insert(list *liste, void *data, int index);

/**
 * Removes the node at the given index
 * Returns true on Success
 * If the Index is out of range, false is returned
 **/
bool l_remove(list *liste, int index);
/**
 * Frees the Lists from all its Nodes
 **/
void l_clear(list *liste);

/**
 * Applies the given function to every Node in the last
 **/
bool l_forEach(list *liste, void (*func)(void *));

/**
 * Returns the data at the specified index
 * If the index is out of range, null is returned
 **/
void *l_get(list *liste, int index);
