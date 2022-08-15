# 静态顺序表与到那个太顺序表的区别

两者仅在定义数据结构与初始化时存在较大差别，其他操作差别并不大。

## 定义区别

```c
// 静态顺序表定义及初始化
typedef struct
{
    ElemType data[MAXSIZE+1];
    int length;
}SSList;    //Static Sequence List


// 动态顺序表定义及初始化
typedef struct
{
    ElemType *data;
    int length;
}DSList;    //Dynamic Sequence List

```