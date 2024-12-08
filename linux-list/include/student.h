#ifndef _STUDENT_H
#define _STUDENT_H

#include "types.h"

#define STUDENT_NAME_LEN  25

typedef unsigned char STUDENT_AGE_TYPE;

enum Sex { MALE, FEMALE };

struct student {
    struct list_head list;
    u64 id;
    char name[STUDENT_NAME_LEN];
    STUDENT_AGE_TYPE age;
    enum Sex sex;
};


void student_add(u64 id, char* name, STUDENT_AGE_TYPE age, enum Sex sex, struct list_head* head);

void student_print(struct list_head* head);
const char* sex_get_str(enum Sex sex);

#endif
