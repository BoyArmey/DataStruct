#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "utils.h"
#include "status.h"
#include "linkList.h"

// 初始化链表
int LinkListInit(linkList list)
{
    list->next = NULL;      // 指针域置空
    return TRUE;
}