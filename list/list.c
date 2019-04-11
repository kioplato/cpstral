// File: list.c

#include "list.h"

#include <stdlib.h>

void init_list(List *list) {
	list->tail = NULL;
	list->crnt = NULL;
	list->n_items = 0;
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
	list->head->prev = NULL;
	list->head->data = NULL;
}
