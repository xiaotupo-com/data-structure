#ifndef _LIST_H
#define _LIST_H

#include "types.h"

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

/********************************************************************************
 * @brief 判断 list 是否为头节点
 * 
 * @param list 
 * @param head 
 * @return int 
 ********************************************************************************/
static inline int list_is_head(const struct list_head *list, const struct list_head *head)
{
	return list == head;
}

#define list_for_each(pos, head) \
	for (pos = (head)->next; !list_is_head(pos, (head)); pos = pos->next)

/********************************************************************************
 * @brief 判断链表是否为空
 * 
 * @param head 
 * @return int 
 ********************************************************************************/
static inline int list_empty(const struct list_head* head) {
	return head->next == head;
}

void list_add(struct list_head*new, struct list_head* head);
void list_add_tail(struct list_head* new, struct list_head* head);
void list_print(struct list_head* head);

#endif
