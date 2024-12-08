#include "student.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
 * @brief 动态的向链表中添加 student 节点
 * 
 * @param id 
 * @param name 
 * @param age 
 * @param sex 
 * @param head 
 ********************************************************************************/
void student_add(u64 id, char *name, STUDENT_AGE_TYPE age, enum Sex sex,
                 struct list_head *head)
{
    struct student *stu = (struct student *)malloc(sizeof(struct student));
    stu->id = id;
    snprintf(stu->name, sizeof(stu->name), "%s", name);
    stu->age = age;
    stu->sex = sex;
    list_add_tail(&stu->list, head);
}

/********************************************************************************
 * @brief 遍历打印 student 链表
 * 
 * @param head 
 ********************************************************************************/
void student_print(struct list_head *head)
{
    struct list_head *pos;
    list_for_each(pos, head)
    {
        printf("id: %d, name: %s, age: %d, Sex: %s\n",
               ((struct student *)pos)->id, ((struct student *)pos)->name,
               ((struct student *)pos)->age, sex_get_str(((struct student *)pos)->sex));
    }
}

/********************************************************************************
 * @brief 将性别枚举类型转换为对应的字符串
 * 
 * @param sex 
 * @return const char* 
 ********************************************************************************/
const char* sex_get_str(enum Sex sex)
{
    switch (sex)
    {
    case FEMALE:
        return "女";
        break;
    case MALE:
        return "男";
        break;
    default:
        break;
    }
}
