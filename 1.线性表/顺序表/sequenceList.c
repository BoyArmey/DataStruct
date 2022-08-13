#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "utils.h"
#include "sequenceList.h"


/**
 * @brief   初始化顺序表
 *          将顺序表结点个数设为0即可,
 *          即使有数据也可以被新加入的数据覆盖掉.
 * 
 * @param list 
 * @return int 
 */
int SequentialListInit(SSList *list)
{
    list->length = 0;
    return TRUE; 
}


/**
 * @brief   添加结点
 *          1）判断顺序表是否已满
 *          2）未满，则添加数据，并且顺序表长度加1
 *          3）
 * @param list 
 * @param element 
 * @return int 
 */
int SequentialListAdd(SSList *list,ElemType element)
{
    if(list->length >= MAXSIZE)
    {
        printf("顺序表已满，无法继续添加数据!");
        return FALSE;   //添加失败
    }
    list->data[list->length] = element;         // 添加数据
    list->length += 1;                          // 顺序表长度加1
    return TRUE;   //添加成功
}

/**
 * @brief 输出所有结点的信息
 * 
 * @param list 
 * @return void 
 */
void SequentialListShow(SSList list)
{
    int i;
    for (i = 0; i < list.length; i++)
    {
        PrintNodeInfo(list.data[i]);    // 打印每个结点的数据
    }
    printf("当前顺序表长度为：%d",list.length);
}


