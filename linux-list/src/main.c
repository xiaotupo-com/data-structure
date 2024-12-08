/********************************************************************************
 * @file main.c
 * @author xiaotupo (xiaotupo@163.com)
 * @brief Linux 链表学习项目
 * @version 0.1
 * @date 2024-12-05
 *
 * @copyright Copyright (c) 2024
 *
 ********************************************************************************/
#include <stdio.h>

#include "list.h"
#include "student.h"
#include "types.h"

int main()
{
    LIST_HEAD(my_list); // 创建一个头节点

    student_add(1, "张三丰", 12, MALE, &my_list);
    student_add(2, "李辉", 32, MALE, &my_list);
    student_add(3, "唐三", 26, MALE, &my_list);
    student_add(4, "李敏", 75, FEMALE, &my_list);

    student_print(&my_list);
}
