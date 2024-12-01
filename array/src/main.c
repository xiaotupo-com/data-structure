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