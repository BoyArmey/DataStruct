#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "utils.h"
#include "status.h"
#include "linkList.h"

/**
 * @brief   初始化链表
 *          1）指针域设置为NULL
 * 
 * @param list 
 * @return int 
 */
int LinkListInit(linkList list)
{
    list->next = NULL;      // 1）指针域设置为NULL
    return TRUE;
}