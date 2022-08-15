# 静态顺序表与到那个太顺序表的区别

两者仅在定义数据结构与初始化时存在较大差别

## 定义区别

```c
// 静态顺序表初始化
typedef struct 
{
    char id[10];       //ID
    char name[20];    //姓名
    int age;          //年龄
}ElemType;
typedef struct
{
    ElemType data[MAXSIZE+1];
    int length;
}SSList;    //Static Sequence List

// 静态顺序表初始化
typedef struct 
{
    char *id;       //ID
    char *name;    //姓名
    int *age;          //年龄
}ElemType;
typedef struct
{
    ElemType *data;
    int length;
}DSList;    //Dynamic Sequence List

```