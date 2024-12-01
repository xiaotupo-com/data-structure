# C 语言数组与结构体的小例子

这是一个`C` 语言数组与结构体的小例子，其中会用到指针、数组、字符串、等内容。包括如何获取数组的长度，如何让指针自加。

## utils.c utils.h

该文件目前之保护了获取数组长度的宏。

```c
#define GetArrLen(array)    sizeof(array) / sizeof(array[0])    // 获取数组的长度
```

## array.c array.h

这两个文件是程序的主题，`array.c` 包含了两个函数 `set_color_name()` 和 `print_color()`。

```c
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
```

`array.h` 头文件:

头文件包含了 `Color` 结构体的定义和函数的声明。

```c
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
```

## main.c

`main.c` 是用来调用其它函数的文件。

```c
#include <string.h>
#include "array.h"
#include "utils.h"

int main()
{
    Color color[4];
    Color *cp = color;

    set_color_name(cp, "Red", strlen("Red"));
    set_color_name(++cp, "Green", strlen("Green"));
    set_color_name(++cp, "Blue", strlen("Blue"));
    set_color_name(++cp, "Yellow", strlen("Yellow"));

    cp = color; // 重新让 cp 指针指向 Color 数组的首地址
    print_color(cp, GetArrLen(color));
}
```

## CMake

项目使用了 `CMake` 作为构建工具：

```cmake
cmake_minimum_required(VERSION 3.15)

project(array_learn)

# 将 src 目录中的所有文件保存到 SOURCE_PATH 变量中
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_PATH)
message(src 下的所有 ".c" 文件：${SOURCE_PATH})

# 设置头文件的路径
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/inc)
message(inc 路径：${INCLUDE_PATH})

# 包含头文件的路径
include_directories(${INCLUDE_PATH})

add_executable(${PROJECT_NAME} 
    ${SOURCE_PATH}
)

```
