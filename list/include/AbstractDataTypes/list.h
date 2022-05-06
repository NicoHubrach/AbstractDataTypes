#pragma once
#include <stdbool.h>

typedef struct myL list;

list *l_create();
void l_destroy(list *liste);

int l_size(list *liste);

bool l_empty(list *liste);

bool l_append(list *liste, void *data);
bool l_insert(list *liste, void *data, int index);

bool l_remove(list *liste, int index);
void l_clear(list *liste);

bool l_forEach(list *liste, void (*func)(void *));

void *l_get(list *liste, int index);
