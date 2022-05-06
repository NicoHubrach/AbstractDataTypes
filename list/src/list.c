#include "AbstractDataTypes/list.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct myLNode
{
    struct myLNode *next;
    void *data;
} myLNode;

typedef struct myL
{
    myLNode *head;
    myLNode *tail;
    int size;
} list;

list *l_create()
{
    list *liste;
    liste = malloc(sizeof(list));
    // Check Return type of malloc
    if (liste != NULL)
    {
        liste->head = NULL;
        liste->tail = NULL;
        liste->size = 0;
    }
    return liste;
}

void l_destroy(list *liste)
{
    if (!l_empty(liste))
    {
        myLNode *curr = liste->head;
        myLNode *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            free(curr);
            curr = next;
            next = NULL;
        }
    }
    free(liste);
}

int l_size(list *liste)
{
    return liste->size;
}

bool l_empty(list *liste)
{
    return (liste->head == NULL);
}

bool l_append(list *liste, void *data)
{
    myLNode *toInsert;
    toInsert = malloc(sizeof(myLNode));
    if (toInsert == NULL)
    {
        return false;
    }
    else
    {
        toInsert->next = NULL;
        toInsert->data = data;

        if (l_empty(liste))
        {
            liste->head = toInsert;
            liste->tail = toInsert;
        }
        else
        {
            liste->tail->next = toInsert;
            liste->tail = toInsert;
        }
        liste->size += 1;
        return true;
    }
}

bool l_insert(list *liste, void *data, int index)
{
    if (index > liste->size)
    {
        return false;
    }
    else
    {
        // If the given Index is the one after the last index, than it appends the data
        if (index == liste->size)
        {
            return l_append(liste, data);
        }
        else
        {
            myLNode *curr = liste->head;
            myLNode *previous = NULL;
            for (int i = 0; i != index; ++i)
            {
                previous = curr;
                curr = curr->next;
            }

            myLNode *toInsert = malloc(sizeof(myLNode));
            // Check return type of malloc
            if (toInsert == NULL)
            {
                return false;
            }
            else
            {
                toInsert->data = data;
                toInsert->next = curr;
                previous->next = toInsert;

                liste->size += 1;
                return true;
            }
        }
    }
}
