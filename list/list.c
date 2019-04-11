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

void push_head(List *list, void *data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->next = list->head->next;
	if (node->next != NULL)
		node->next->prev = node;
	node->prev = NULL;
	node->data = data;
	list->head->next = node;
	if (list->tail == NULL)
		list->tail = node;
	if (list->crnt == NULL)
		list->crnt = node;
	list->n_items++;
}

void push_back(List *list, void *data) {
	if (list->tail == NULL)
		return push_head(list, data);
	Node *node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->prev = list->tail;
	node->data = data;
	list->tail->next = node;
	list->tail = node;
	list->n_items++;
}
