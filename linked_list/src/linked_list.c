#include "linked_list.h"

#include <malloc.h>

/********************************************************************************
 * @brief 初始化链表，返回一个头节点
 *
 * @return Node*
 ********************************************************************************/
node_t *node_init()
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->next = NULL;
    return node;
}

/********************************************************************************
 * @brief 可以从两个方向（头部和尾部）插入数据
 *
 * @param head
 * @param back
 * @param data
 * @param mode 控制从头插入数据还是从尾部插入数据
 ********************************************************************************/
void node_insert(node_t *head, node_t *back, node_data_t data,
                 node_mode_t mode)
{
    if (head->next == NULL && back->next == NULL) {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->next = NULL;
        node->data = data;

        head->next = node; // 让链表头的next 指向新节点
        back->next = node; // 让 back 节点等于新节点
    } else {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->data = data;

        switch (mode) {
        case HEAD:
            node->next = head->next;
            head->next = node;
            break;
        case BACK:
            node->next = NULL;
            back->next->next = node;
            back->next = node;
            break;

        default:
            break;
        }
    }
}

/********************************************************************************
 * @brief 从链表头部开始遍历
 *
 * @param n
 ********************************************************************************/
void print_node(node_t *n)
{
    n = n->next;
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void delete_head(node_t * head)
{
    node_t* temp = head->next; // 创建临时指针，指向 第一个数据节点
    head->next = temp->next;
    temp->next = NULL;
    free(temp);
}

node_data_t node_pop(node_t* head, node_t* back)
{
    node_data_t result;
    node_t* temp = head->next;
    while (temp != NULL)
    {
        if (temp->next->next == NULL) {
            temp->next = NULL;
            result = back->next->data;
            free(back->next);
            back->next = temp;
        }
        temp = temp->next;
    }
    return result;
}