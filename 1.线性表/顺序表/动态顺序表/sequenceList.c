#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"
#include "utils.h"
#include "sequenceList.h"

/**
 * @brief   初始化顺序表
 *          1）申请内存空间
 *	        2）判断是否分配成功
 *	        3）分配成功，将顺序表长度置为0
 * 
 * @param list 
 * @return int 
 */
int SequentialListInit(DSList *list)
{
    /* 手动输入申请内存【如果手动输入顺序表最大容量，后面判断线性表是否已满需要修改相对于的判断条件】
    int maxSize;
    printf("请输入线性表最大容量:");
    scanf("%d",&maxSize);
    list->data = (ElemType*)malloc(sizeof(ElemType) * maxSize);
    */

    list->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);   // 分配内存
    if(list->data)      // 判断内存是否分配成功
    {
        list->length = 0;   // 长度置为0
        return TRUE;        // 初始化成功
    }
    return FALSE;       // 初始化失败
}


/**
 * @brief   添加结点
 *          1）判断顺序表是否已满
 *          2）未满，则添加数据
 *          3）顺序表长度加1
 * 
 * @param list      
 * @param element   结点数据
 * @return int 
 */
int SequentialListAdd(DSList *list,ElemType element)
{
    // 1）判断顺序表是否已满
    if(list->length == MAXSIZE)
    {
        printf("\n\n顺序表已满，无法继续添加数据!\n");
        return FALSE;
    }

    // 2）添加数据
    list->data[list->length] = element;

    // 3）顺序表长度加1
    list->length += 1;

    return TRUE;

}

/**
 * @brief   显示所有的结点
 *          1）判断顺序表是否为空表
 *          2）输出顺序表结点信息 
 * 
 * @param list
 * @return int 
 */
int SequentialListShow(DSList list)
{
    int i;  // 循环变量

    // 1）判断顺序表是否为空表
    if(list.length == 0)
    {
        printf("\n顺序表为空!\n");
        return FALSE;   
    }

    // 2）输出顺序表结点信息 
    for (i = 0; i < list.length; i++)
    {
        PrintNodeInfo(*(list.data + i));        // 打印每个结点的数据
    }
    printf("当前顺序表长度为：%d\n",list.length);
    
    return TRUE;
}

/**
 * @brief   插入结点
 * 
 * @param list 
 * @param index     下标
 * @param element   结点数据
 * @return int 
 */
int SequentialListInsert(DSList *list,int index,ElemType element)
{
    
}