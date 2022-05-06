#include "AbstractDataTypes/queue.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct myQNode
{
    struct myQNode *next;
    void *data;
} myQNode;

typedef struct myQ
{
    myQNode *head;
    myQNode *tail;
} queue;

queue *q_create()
{
    queue *schlange;
    schlange = malloc(sizeof(queue));
    // Check Return type of malloc
    if (schlange != NULL)
    {
        schlange->head = NULL;
        schlange->tail = NULL;
    }
    return schlange;
}

void q_destroy(queue *schlange)
{
    if (!q_empty(schlange))
    {
        myQNode *curr = schlange->head;
        myQNode *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            free(curr);
            curr = next;
            next = NULL;
        }
    }
    free(schlange);
}

bool q_enqueue(queue *schlange, void *data)
{
    myQNode *toEnqueue;
    toEnqueue = malloc(sizeof(myQNode));
    if (toEnqueue == NULL)
    {
        return false;
    }
    else
    {
        toEnqueue->next = NULL;
        toEnqueue->data = data;

        if (q_empty(schlange))
        {
            schlange->head = toEnqueue;
            schlange->tail = toEnqueue;
        }
        else
        {
            schlange->tail->next = toEnqueue;
            schlange->tail = toEnqueue;
        }
        return true;
    }
}

void q_dequeue(queue *schlange)
{
    myQNode *toDelete;
    if (!q_empty(schlange))
    {
        toDelete = schlange->head;
        schlange->head = schlange->head->next;
        free(toDelete);
    }
}

void *q_front(queue *schlange)
{
    if (!q_empty(schlange))
    {
        return (schlange->head->data);
    }
    else
    {
        return NULL;
    }
}

bool q_empty(queue *schlange)
{
    return (schlange->head == NULL);
}
