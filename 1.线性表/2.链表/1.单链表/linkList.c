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


/**
 * @brief   链表追加元素
 *          1）申请结点，将传入的数据保存到结点
 *          2）申请指针，将其指向链表的首元结点
 *          3）使用while循环，将指针移动到链表尾部
 *          4）将数据插入到链表尾部
 * 
 * @param list 
 * @param elem 
 * @return int 
 */
int LinkListAdd(linkList list,ElemType elem)
{
    // 1）申请结点，将传入的数据保存到结点
    Node node;
    NodeInfoCopy(&(node.elem),&(elem));
    
}