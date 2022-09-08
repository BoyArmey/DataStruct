#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "DuLinkList.h"

/**
 * @brief   初始化循环链表
 *          1）分配内存空间
 *          2）分配成功，将前驱与后继指针指向本身
 *          3）将首元结点作为函数返回值
 * 
 * @param list 
 * @return DuLinkList 
 */
DuLinkList DuLinkListInit(DuLinkList list)
{
    list = (DuLinkList)malloc(sizeof(DuLinkListNode));
    if (list)
    {
        list->prior = list;     // 前驱指针指向本身
        list->next = list;      // 后继指针指向本身
        
        return list;
    }
    return NULL;
}


// 循环链表插入数据
DuLinkList DuLinkListInsert(DuLinkList list, ElemType elem)
{
    
}