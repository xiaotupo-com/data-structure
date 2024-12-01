#include <stdio.h>
#include <stddef.h>
#include "linked_list.h"
#include "utils.h"

int main()
{
    node_t* head = node_init();
    node_t* back = node_init();

    Line();
    node_insert(head, back, 1, HEAD); // 1
    node_insert(head, back, 2, HEAD); // 2-1
    node_insert(head, back, 3, HEAD); // 3-2-1
    node_insert(head, back, 4, HEAD); // 4-3-2-1
    print_node(head);

    Line();
    node_insert(head, back, 5, BACK); // 4-3-2-1-5
    node_insert(head, back, 6, BACK); // 4-3-2-1-5-6
    print_node(head);
    Line();
    // printf("head->next->data: %d\n", head->next->data);
    delete_head(head);
    print_node(head);
    Line();
    node_data_t result;
    result = node_pop(head, back);
    printf("删除的数据为：%d\n", result);
    print_node(head);
    Line();
    result = node_pop(head, back);
    printf("删除的数据为：%d\n", result);
    print_node(head);
    Line();
}
