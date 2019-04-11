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

#endif  // #ifndef LIST_H
