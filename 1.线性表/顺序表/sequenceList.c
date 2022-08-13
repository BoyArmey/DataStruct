#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "utils.h"
#include "sequenceList.h"


/**
 * @brief 初始化顺序表
 *        将顺序表结点个数设为0即可,
 *        即使有数据也可以被新加入的数据覆盖掉.
 * 
 * @param list 
 * @return int 
 */
int SequentialListInit(SSList *list)
{
    list->length = 0;
    return TRUE; 
}