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

inline static void l_push_front(list *liste, myLNode *node)
{
    node->next = liste->head;
    liste->head = node;
}

inline static void l_push_back(list *liste, myLNode *node)
{
    liste->tail->next = node;
    liste->tail = node;
}

bool l_empty(list *liste)
{
    return (liste->size == 0);
}

bool l_append(list *liste, void *data)
{
    myLNode *toInsert;
    toInsert = malloc(sizeof(myLNode));
    if (toInsert == NULL)
    {
        return false;
    }
    toInsert->next = NULL;
    toInsert->data = data;

    if (l_empty(liste))
    {
        liste->head = toInsert;
        liste->tail = toInsert;
    }
    else
    {
        l_push_back(liste, toInsert);
    }

    liste->size += 1;
    return true;
}

bool l_insert(list *liste, void *data, int index)
{
    // Wenn der Index nicht in die Liste passt
    if (index > liste->size)
    {
        return false;
    }

    // Erstelle myLNode Object
    myLNode *toInsert = malloc(sizeof(myLNode));
    // Check return type of malloc
    if (toInsert == NULL)
    {
        return false;
    }
    toInsert->data = data;
    toInsert->next = NULL;

    // Wenn die Liste leer ist, stopfe Daten vorne dran
    if (l_empty(liste))
    {
        liste->head = toInsert;
        liste->tail = toInsert;
    }
    else if (index == liste->size)
    {
        l_push_back(liste, toInsert);
    }
    else if (index == 0)
    {
        l_push_front(liste, toInsert);
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

        toInsert->next = curr;
        previous->next = toInsert;
    }

    liste->size += 1;
    return true;
}

bool l_remove(list *liste, int index)
{
    // Wenn die Liste nicht leer ist
    if (!l_empty(liste))
    {
        // Wenn der angefragte Index innerhalb der Liste ist
        if (index >= 0 && index < liste->size)
        {
            if (index == 0)
            {
                myLNode *toDelete = liste->head;
                liste->head = liste->head->next;
                free(toDelete);
            }
            else
            {
                myLNode *curr = liste->head;
                myLNode *prev = NULL;
                for (int i = 0; i != index; ++i)
                {
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = curr->next;
                free(curr);
            }
            liste->size -= 1;
        }
    }
    return false;
}

void l_clear(list *liste)
{
    int size = liste->size;
    for (int i = 0; i < size; ++i)
    {
        l_remove(liste, 0);
    }
}

bool l_forEach(list *liste, void (*func)(void *))
{
    if (!l_empty(liste))
    {
        myLNode *curr = liste->head;
        while (curr != NULL)
        {
            func(curr->data);
            curr = curr->next;
        }
        return true;
    }
    return false;
}

void *l_get(list *liste, int index)
{
    if (index >= 0 && index < liste->size)
    {
        myLNode *curr = liste->head;
        for (int i = 0; i != index; ++i)
        {
            curr = curr->next;
        }
        return curr->data;
    }
    else
    {
        return NULL;
    }
}
