/********************************************************************************
 * @file types.h
 * @author xiaotupo (xiaotupo@163.com)
 * @brief Linux 链表学习项目
 * @version 0.1
 * @date 2024-12-05
 *
 * @copyright Copyright (c) 2024
 *
 ********************************************************************************/
#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <stddef.h>

typedef unsigned long u64;

struct list_head {
    struct list_head *next, *prev;
};

#endif
