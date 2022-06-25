#ifndef _SEQUENCELIST_H
#define _SEQUENCELIST_H

//定义顺序表最大存储容量
#define MAXSIZE 100          

//定义顺序表中结点存储数据的类型
typedef struct 
{
    int id;           //ID
    char name[10];    //姓名
    int age;          //年龄
}ElemType;


//动态方法定义顺序表的结构
typedef struct
{
    ElemType *data;
    int length;
}DSList;    //Dynamic Sequence List


/* 顺序表的操作函数声明 */

// 初始化顺序表
int SequentialListInit(DSList *list);
// 添加结点
int SequentialListAdd(DSList *list,ElemType element);
// 显示所有的结点
int SequentialListShow(DSList *list);
// 插入节点
int SequentialListInsert(DSList *list,int index,ElemType element);
// 删除节点
int SequentialListDelete(DSList *list,int delIndex);
//根据下标查找结点
int SequentialListSearchByIndex(DSList *list,int index,ElemType *element);
//根据ID查找结点
int SequentialListSearchById(DSList *list, int id, ElemType *element);
//求顺序表的长度
int GetSequentialListLength(DSList *list);
//清空顺序表
int SequentialListClear(DSList *list);
//销毁顺序表
void SequentialListDestroy(DSList *list);
//判断顺序表是否为空表
int SequentialListIsEmpty(DSList *list);



#endif