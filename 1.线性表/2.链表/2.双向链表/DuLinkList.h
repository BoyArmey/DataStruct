#ifndef _DULINKLIST_H_
#define _DULINKLIST_H_


//定义链表中结点存储数据的类型
typedef struct 
{
    char id[10];       //ID
    char name[20];    //姓名
    int age;          //年龄
}ElemType;

struct Node
{
    ElemType elem;
    struct Node *prior;     // 前驱指针
    struct Node *next;      // 后继指针
};

typedef struct Node DuLinkListNode;       // 结点
typedef struct Node *DuLinkList;         // 双向链表指针




#endif