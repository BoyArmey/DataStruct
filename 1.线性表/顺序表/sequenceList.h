#ifndef _SEQUENCELIST_H
#define _SEQUENCELIST_H

//定义顺序表最大存储容量
#define MAXSIZE 100          

//定义顺序表中结点存储数据的类型
typedef struct 
{
    char id[10];       //ID
    char name[20];    //姓名
    int age;          //年龄
}ElemType;


//静态方法定义顺序表的结构
typedef struct
{
    ElemType data[MAXSIZE+1];
    int length;
}SSList;    //Static Sequence List


/* 顺序表的操作函数声明 */

// 初始化顺序表
int SequentialListInit(SSList *list);
// 添加结点
int SequentialListAdd(SSList *list,ElemType element);
// 显示所有的结点
void SequentialListShow(SSList list);
// 插入结点
int SequentialListInsert(SSList *list,int index,ElemType element);
// 删除结点
int SequentialListDelete(SSList *list,int delIndex);
//根据下标查找结点
int SequentialListSearchByIndex(SSList *list,int index,ElemType *element);
//根据ID查找结点
int SequentialListSearchById(SSList *list, int id, ElemType *element);
//求顺序表的长度
int GetSequentialListLength(SSList list);
//清空顺序表
int SequentialListClear(SSList *list);
//销毁顺序表
void SequentialListDestroy(SSList *list);
//判断顺序表是否为空表
int SequentialListIsEmpty(SSList list);



#endif