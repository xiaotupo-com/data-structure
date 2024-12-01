#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

typedef int node_data_t;

typedef struct node {
    node_data_t data;
    struct node *next;
} node_t;

typedef enum { HEAD, BACK } node_mode_t;

node_t *node_init();
void node_insert(node_t *head, node_t *back, node_data_t data,
                 node_mode_t mode);
void print_node(node_t *n);
void delete_head(node_t * head);
node_data_t node_pop(node_t* head, node_t* back);

#endif