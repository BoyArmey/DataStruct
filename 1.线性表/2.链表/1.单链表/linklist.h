#ifndef _LINKLIST_H
#define _LINKLIST_H

//定义链表中结点存储数据的类型
typedef struct 
{
    char id[10];       //ID
    char name[20];    //姓名
    int age;          //年龄
}ElemType;


// 定义链表数据结构
struct linklist
{
    ElemType elem;               // 数据域
    struct linklist *next;      //  结点域
};


#endif