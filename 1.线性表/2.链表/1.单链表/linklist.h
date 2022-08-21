#ifndef _LINKLIST_H
#define _LINKLIST_H

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
// 链表追加元素
int LinkListAdd(linkList *list,ElemType elem);
// 链表的长度
int LinkListLength(linkList list);
// 显示链表元素
void LinkListShow(linkList list);
// 



#endif