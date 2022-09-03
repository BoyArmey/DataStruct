#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"
#include "status.h"
#include "linkList.h"

/**
 * @brief   初始化链表
 *          1）申请内存空间
 *          2）申请成功，指针域设为空,返回链表的地址
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
 *          1）申请指针p，将其指向链表的首元结点
 *          2）创建保存数据的结点，内存申请失败则退出
 *              创建新结点后，新结点指针域置空
 *          3）内存申请成功则将传入的数据保存到新创建的结点
 *          4）使用循环，将指针p定位到链表尾部
 *              while (p->next != NULL)
 *          5）将数据添加到链表尾部
 * 
 * @param list 
 * @param elem 
 * @return status 
 */
status LinkListAddEnd(linkList *list,ElemType elem)
{

    // 1）申请指针，指向链表的头结点
    linkList *p = list;     

    // 2）创建保存数据的结点，内存申请失败则退出
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    if(!node)
    {
        printf("\n内存申请失败!\n");
        return FALSE;
    }

    // 3）申请成功将传入的数据保存到新创建的结点
    NodeInfoCopy(&(node->elem),&(elem));
    

    // 4）使用循环，将指针p定位到链表尾部，用于添加数据
    while (p->next != NULL)
    {
        p = p->next;
    }

    // 5）添加结点
    p->next = node;  

    return TRUE;
}

/**
 * @brief   链表的长度
 *          1）新建指针p，指向链表的头结点
 *              首元结点不存储数据，不必计算
 *          2）使用p进行链表的遍历，对结点个数进行累加计算
 *          3）每一次遍历完成后，要将p指向下一个结点
 * 
 * @param list 
 * @return int 
 */
int LinkListLength(linkList list)
{
    int length = 0;         // 记录链表长度
    linkList *p = list.next;    // 1）指向头结点
    while (p)
    {
        length += 1;               // 2）长度加1
        p = p->next;              // 3）指向链表的下一个结点
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
    linkList *p = list.next;    // 1）指向链表的头结点
    while (p)
    {
        NodeInfoPrint(p->elem);      // 2）输出结点信息
        p = p->next;                // 3）指向链表的下一个结点
    }
    printf("\n当前链表长度为:%d\n",LinkListLength(list));
}

/**
 * @brief   链表头部追加元素
 *          1）创建保存数据的结点，内存申请失败则退出
 *              创建新结点后，新结点指针域置空
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
    node->next = NULL;          // 指针域置空
    if(!node)
    {
        printf("\n内存申请失败!\n");
        return FALSE;
    }
    NodeInfoCopy(&(node->elem),&elem);   // 结点数据进行保存
    

    // 2）将首元结点的指针域保存到新结点的指针域
    node->next = list->next;

    // 3）新结点追加到头结点的位置
    list->next = node;
    
    return TRUE;
}

/**
 * @brief   链表插入元素
 *          1）新建指针p，指向链表的首元结点
 *          2）将插入下标进行角色转换
 *              程序角度从0开始，用户角度从1开始
 *          3）获取链表长度，并判断插入位置是否合法
 *          4）创建结点，保存传入的数据
 *          5）查找插入位置，将指针p指向插入位置的前一个元素
 *          6）插入数据
 *          
 * 
 * @param list 
 * @param elem      插入元素
 * @param index     插入位置
 * @return status 
 */
status LinkListInsert(linkList *list, ElemType elem, int index)
{
    int length = LinkListLength(*list);     // 获取链表长度
    Node *node = (Node*)malloc(sizeof(Node));   // 创建结点
    int i;      // 魂环变量

    // 1）指向首元结点
    linkList *p = list;
    
    // 2）下标转换
    index = index - 1;

    // 3）判断插入位置是否合法
    if(index < 0 || index > length)
    {
        printf("\n插入位置不合法，插入失败\n");
        return FALSE;
    }

    // 4）保存待插入的结点
    NodeInfoCopy(&(node->elem),&elem);

    // 5）查找插入位置，将指针p指向插入位置的前一个元素
    for (i = 0; i < index; i++)
    {
        p = p->next;
    }

    // 6）插入元素
    node->next = p->next;
    p->next = node;
    
    return TRUE;
}


/**
 * @brief   通过下标查找链表数据
 *          1）将用户角度的下标转化为程序角度的下标
 *              用户从1开始，程序从0开始，所以需要减1
 *          2）获取链表长度
 *              如果链表长度小于等于0，空链表返回FALSE
 *          3）判断下标位置是否合法
 *          4）新建指针p指向头结点，使用循环将p指向查找的结点
 *              首元结点无数据信息，直接指向头结点即可
 *          5）保存查找到的数据
 * 
 * 
 * @param list 
 * @param index     下标
 * @param elem      查找到的元素
 * @return status 
 */
status LinkListSearchByIndex(linkList list,int index,ElemType *elem)
{
    int i;  // 循环变量
    linkList *p = list.next;

    // 1）下标角度转换
    index = index - 1;

    // 2）获取链表长度
    int length = LinkListLength(list);
    
    if (length <= 0)
    {
        printf("\n链表为空，查找失败\n");
        return FALSE;
    }

    // 3）判断查找下标是否合法
    if(index < 0 || index > length)
    {
        printf("\n查找位置有误，查找失败\n");
        return FALSE;
    }
    
    // 4）将p指向查找的结点
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }

    // 5）保存查找到的结点信息
    NodeInfoCopy(elem,&(p->elem));
    return TRUE;
}


/**
 * @brief   依据用户ID查找链表数据
 *          1）新建指针p指向链表头结点
 *          2）设置标志位，检测是否查找到数据
 *          3）遍历链表，对比用户ID是否相同
 *              相同则保存结点信息，不同继续遍历
 * 
 * @param list 
 * @param id 
 * @param elem 
 * @return status 
 */
status LinkListSearchById(linkList list,const char *id,ElemType *elem)
{
    int flag = 0;   // 标记位，记录是否查找到数据
    
    // 1）将p指向链表头结点
    linkList *p = list.next;

    // 2）遍历链表，对比用户ID是否相同
    while (p != NULL)
    {
        if( strcmp(id,p->elem.id) == 0)
        {
            flag = 1;
            NodeInfoCopy(elem,&(p->elem));      // 找到对应ID
            break;
        }
        else
        {
            // 未找到，继续循环
            p = p->next; 
        }                     
    }
    
    if(flag == 0)
    {
        return FALSE;   // 为查找到对应的数据
    }

    return TRUE;
}

/**
 * @brief   根据下标删除链表元素
 *          1）用户下标转换为程序角度下标
 *              用户从1开始，程序从0开始
 *          2）判断用户输入的下标是否合法：1 <= index <= 链表最大长度
 *          3）将指针p指向链表被删除结点的前一个结点
 *          4）将指针q指向被删除的结点
 *          5）修改指针域 
 *              p->next = q->next
 *          6）释放被删除的结点的内存空间
 *
 * @param list 
 * @param index     下标
 * @return status 
 */
status LinkListDeleteByIndex(linkList *list,int index)
{

    // 获取链表长度
    int length = LinkListLength(*list);

    // 指针p指向首元结点
    linkList *p = list;
    // 循环变量
    int i;
    // 记录被删除的结点
    linkList * q = NULL;

    // 1）用户下标转换为程序角度下标
    index = index - 1;

    // 2）判断删除下标是否合法
    if(index < 0 || index > length)
    {
        printf("\n输入位置不合法！\n");
        return FALSE;
    }

    // 将指针p指向被删除结点的头一个结点
    for(i=0; i < index; i++)
    {
        p = p->next;
    }
    
    // 将指针q指向被删除的结点
    q = p->next;

    // 修改指针域
    p->next = q->next;
    
    // 释放被删除结点的内存
    free(q);

    return TRUE;
}


/**
 * @brief   根据ID删除链表元素
 *          2）指针p指向头结点，遍历列表，查找对应id所在的结点
 *          3）指针q指向首元结点，遍历列表，查找对应id所在的结点的前一个结点
 * 
 * @param list 
 * @param id    待删除结点的ID
 * @return status 
 */
status LinkListDeleteById(linkList *list,const char* id)
{

    // 指针p指向头结点
    linkList *p = list->next;
    // 指针q指向首元结点
    linkList *q = list;

    while (p)
    {
        if(strcmp(p->elem.id,id) == 0)
        {
            q->next = p->next;
            free(p);
            return TRUE;
        }

        q = q->next;
        p = p->next;
    }

    return FALSE;

}
