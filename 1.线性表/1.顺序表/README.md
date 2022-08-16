# 静态顺序表与到那个太顺序表的区别

1）两者仅在定义数据结构与初始化时存在较大差别，其他操作基本相同。
2）动态顺序表需要进行销毁，即手动释放申请的内存。

## 定义与初始化区别

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
int SequentialListInit(DSList *list)
{
    list->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);   // 分配内存
    if(list->data)      // 判断内存是否分配成功
    {
        list->length = 0;   // 长度置为0
        return TRUE;        // 初始化成功
    }
    return FALSE;       // 初始化失败
}

// 销毁动态顺序表
int SequentialListDestroy(DSList *list)
{
    if(list->data)
    {
        free(list->data);   // 2）销毁顺序表
        list->length = 0;   // 3）长度置为0
        return TRUE;        // 销毁成功
    }
    return FALSE;           // 销毁失败
}

```