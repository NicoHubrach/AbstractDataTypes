#include "stack/stack.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct mySNode
{
    struct mySNode *next;
    void *data;
} mySNode;

typedef struct myS
{
    mySNode *top;
} stack;

stack *s_create()
{
    stack *stapel;
    stapel = malloc(sizeof(stack));
    if (stapel != NULL)
    {
        stapel->top = NULL;
    }
    return stapel;
}

void s_destroy(stack *stapel)
{
    if (!s_empty(stapel))
    {
        mySNode *curr = stapel->top;
        mySNode *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            free(curr);
            curr = next;
            next = NULL;
        }
    }
    free(stapel);
}

bool s_push(stack *stapel, void *data)
{
    mySNode *toPush;
    toPush = malloc(sizeof(mySNode));
    if (toPush == NULL)
    {
        return false;
    }
    else
    {
        toPush->next = NULL;
        toPush->data = data;

        if (s_empty(stapel))
        {
            stapel->top = toPush;
        }
        else
        {
            toPush->next = stapel->top;
            stapel->top = toPush;
        }

        return true;
    }
}

void s_pop(stack *stapel)
{
    mySNode *toDelete;
    if (!s_empty(stapel))
    {
        toDelete = stapel->top;
        stapel->top = stapel->top->next;
        free(toDelete);
    }
}

void *s_top(stack *stapel)
{
    if (!s_empty(stapel))
    {
        return (stapel->top->data);
    }
}

bool s_empty(stack *stapel)
{
    return (stapel->top == NULL);
}
