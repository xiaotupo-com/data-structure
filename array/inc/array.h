#ifndef __ARRAY_H
#define __ARRAY_H
#include <stddef.h>

/// @brief 颜色
typedef struct 
{
    char name[50];
} Color;

void set_color_name(Color* color, char *txt, size_t _str_len);
void print_color(Color* color, size_t arr_len);

#endif