#ifndef _LINKLIST_H
#define _LINKLIST_H

#include "status.h"

//定义链表中结点存储数据的类型
typedef struct 
{
    char id[10];       //ID
    char name[20];    //姓名
    int age;          //年龄
}ElemType;


// 定义链表结点类型
struct NODE
{
    ElemType elem;           // 数据域
    struct NODE *next;      //  结点域
};     

// 定义链表结点
typedef struct NODE Node; 
// 定义链表
typedef struct NODE linkList;  


// 链表初始化
linkList* LinkListInit();
// 链表尾部追加元素
status LinkListAddEnd(linkList *list, ElemType elem);
// 链表的长度
int LinkListLength(linkList list);
// 显示链表元素
void LinkListShow(linkList list);
// 链表头部追加元素
status LinkListAddFirst(linkList *list, ElemType elem);
// 链表插入元素
status LinkListInsert(linkList *list, ElemType elem, int index);
// 依据下标查找链表数据
status LinkListSearchByIndex(linkList list,int index,ElemType *elem);
// 依据用户ID查找链表数据
status LinkListSearchById(linkList list,const char *id,ElemType *elem);
// 根据下标删除链表元素
status LinkListDeleteByIndex(linkList *list,int index);
// 根据ID删除链表元素
status LinkListDeleteById(linkList *list,const char* id);
// 判断链表为空
status LinkListIsEmpty(linkList list);
// 链表逆序
linkList* LinkLisInverse(linkList *list);
// 链表销毁
status LinkListDestroy(linkList *list);



#endif