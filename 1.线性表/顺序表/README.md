# 静态顺序表与到那个太顺序表的区别

两者仅在定义数据结构与初始化时存在较大差别，其他操作差别并不大。

## 定义区别

```c
/* 静态顺序表 */
// 定义
typedef struct
{
    ElemType data[MAXSIZE+1];
    int length;
}SSList;    //Static Sequence List
// 初始化
int SequentialListInit(SSList *list)
{
    list->length = 0;
    return TRUE; 
}


/* 动态顺序表 */
//定义
typedef struct
{
    ElemType *data;
    int length;
}DSList;    //Dynamic Sequence List
//初始化


```