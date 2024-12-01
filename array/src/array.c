#include <stdio.h>
#include <string.h>
#include "array.h"


/********************************************************************************
 * @brief 给 Color 中的 name 设置内容
 * 
 * @param color     Color 指针
 * @param txt       要插入的文本
 * @param _str_len  要插入文本字符串的长度
 ********************************************************************************/
void set_color_name(Color* color, char *txt, size_t _str_len)
{
    printf("str->len: %d\n", _str_len);
    strncpy(color->name, txt, _str_len);
}

/********************************************************************************
 * @brief 打印 Color
 * 
 * @param color 
 * @param arr_len 
 ********************************************************************************/
void print_color(Color* color, size_t arr_len)
{
    for (size_t i=0; i<arr_len; i++)
    {
        printf("%d:%s\n", i, (color++)->name);
    }
}