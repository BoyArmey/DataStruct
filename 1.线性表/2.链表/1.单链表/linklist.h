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
struct Node
{
    ElemType elem;               // 数据域
    struct Node *next;      //  结点域
};

// 定义链表
typedef struct Node *linklist;  



#endif