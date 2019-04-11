// File: list.h

#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    void *data;
} Node;

// A double linked list.
// Can function as queue and stack also.
typedef struct List {
    Node *head;  // Points to header node.
    Node *tail;  // Points to last node.
    Node *crnt;  // Points to current node (for list iteration).
    size_t n_items;
} List;

// Initializes a list.
// List must be already allocated.
void init_list(List *list);

void push_head(List *list, void *data);

void push_back(List *list, void *data);

void push(List *list, void *data);

void* pop_head(List *list);

void* pop_back(List *list);

void* pop(List *list);

void* checkout(List *list);

int mv_left(List *list);

int mv_right(List *list);

int mv_head(List *list);

int mv_tail(List *list);

size_t get_n_items(List *list);

void print_list(List *list, void (print_data)(void *));

void del_list(List *list, int test);

#endif  // #ifndef LIST_H
