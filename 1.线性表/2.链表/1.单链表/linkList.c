#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "utils.h"
#include "status.h"
#include "linkList.h"

/**
 * @brief   初始化链表
 *          1）申请内存空间
 *          2）申请成功，指针域设为空
 * 
 * @return linkList* 
 */
linkList* LinkListInit()
{
    linkList *list = (linkList*)malloc(sizeof(linkList));
    if (list)
    {
        list->next = NULL;      // 1）指针域设置为NULL
        return list;
    }
    printf("\n内存申请失败!\n");
    return NULL;
    
}


/**
 * @brief   链表尾部追加元素
 *          1）申请指针，将其指向链表的头结点
 *          2）创建保存数据的结点，内存申请失败则退出
 *          3）创建成功则将传入的数据保存到新创建的结点
 *          4）判断是否为空链表，为空链表，则将新创建的结点加入到头结点的位置
 *              因为p指向了NULL
 *          5）非空链表则使用循环，将指针定位到链表尾部
 *          6）将数据添加到链表尾部
 * 
 * @param list 
 * @param elem 
 * @return status 
 */
status LinkListAddEnd(linkList *list,ElemType elem)
{

    // 1）申请指针，指向链表的头结点
    linkList *p = list->next;     

    // 2）创建保存数据的结点，内存申请失败则退出
    Node *node = (Node*)malloc(sizeof(Node));
    if(!node)
    {
        printf("\n内存申请失败!\n");
        return FALSE;
    }

    // 3）申请成功将传入的数据保存到新创建的结点
    NodeInfoCopy(&(node->elem),&(elem));
    node->next = NULL;

    // 4）为空链表，将新创建的结点加入到头结点的位置
    if(list->next == NULL)      
    {
        
        list->next = node;
        return TRUE;
    }
    else
    {
        // 5）非空链表，使用指针p移动到链表尾部，便于添加数据
        while (p->next != NULL)
        {
            p = p->next;
        }

        // 6）添加结点
        p->next = node;        
    }  

    return TRUE;
}

/**
 * @brief   链表的长度
 *          1）新建指针p，指向链表的头结点
 *          2）使用p进行链表的遍历，对结点个数进行累加计算
 *          3）每一次遍历完成后，要将p指向下一个结点
 * 
 * @param list 
 * @return int 
 */
int LinkListLength(linkList list)
{
    int length = 0;         // 记录链表长度
    linkList *p = (&list)->next;    // 1）指向头结点
    while (p)
    {
        length += 1;               // 长度加1
        p = p->next;              // 指向链表的下一个结点
    }
    return length;
}


/**
 * @brief   显示链表元素
 *          1）新建指针p，指向链表的头结点
 *          2）使用p进行链表的遍历，输出每个结点的信息
 *          3）每一次遍历完成后，要将p指向下一个结点
 * 
 * @param list 
 */
void LinkListShow(linkList list)
{
    linkList *p = (&list)->next;    // 1）指向链表的头结点
    while (p)
    {
        NodeInfoPrint(p->elem);      // 2）输出结点信息
        p = p->next;                // 指向链表的下一个结点
    }
    printf("\n当前链表长度为:%d\n",LinkListLength(list));
}

/**
 * @brief   链表头部追加元素
 *          1）创建保存数据的结点，内存申请失败则退出
 *          2）将首元结点的指针域保存到新结点的指针域，防止后续元素丢失
 *          3）新结点追加到头结点的位置，即list的指针域指向新结点
 * 
 * @param list 
 * @param elem 
 * @return status 
 */
status LinkListAddFirst(linkList *list, ElemType elem)
{
    // 1）创建保存数据的结点，内存申请失败则退出
    Node *node = (Node*)malloc(sizeof(Node));
    if(!node)
    {
        printf("\n内存申请失败!\n");
        return FALSE;
    }
    NodeInfoCopy(&(node->elem),&elem);   // 结点数据进行保存
    node->next = NULL;          // 指针域置空

    // 2）将首元结点的指针域保存到新结点的指针域
    node->next = list->next;

    // 3）新结点追加到头结点的位置
    list->next = node;
    
    return TRUE;
}

/**
 * @brief   链表插入元素
 *          1）新建指针p，指向链表的首元结点
 *          ）判断插入位置是否合法
 *          ）创建结点，保存传入的
 *          ）将插入下标进行角色转换
 *              程序角度从0开始，用户角度从1开始
 *          
 * 
 * @param list 
 * @param elem      插入元素
 * @param index     插入位置
 * @return status 
 */
status LinkListInsert(linkList *list, ElemType elem, int index)
{
    // 1）指向首元结点
    linkList *p = list->next;

    // 2）下标转换
    index = index - 1;



}

