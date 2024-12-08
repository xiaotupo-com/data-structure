#include "list.h"

void list_add(struct list_head*new, struct list_head* head)
{
    if (list_empty(head)) {
        head->next = new;
        head->prev = new;
        new->next = head;
        new->prev = head;
    } else {
        new->prev = head;
        new->next = head->next;
        head->next = new;
        
    }
}

void list_add_tail(struct list_head* new, struct list_head *head)
{
    if (list_empty(head)) {
        head->next = new;
        head->prev = new;
        new->next = head;
        new->prev = head;
    } else {
        head->prev->next = new;
        new->next = head;
        new->prev = head->prev;
        head->prev = new;
    }
}
