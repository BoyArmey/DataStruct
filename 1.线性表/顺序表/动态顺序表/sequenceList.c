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
    /* 手动输入申请内存
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