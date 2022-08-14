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
        printf("顺序表已满，无法继续添加数据!\n");
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


/**
 * @brief   插入结点
 *          1）将用户角度的下标转为程序角度的下标：index = index - 1
 *              注：程序从0开始，用户角度为从1开始，因此index需要减1
 *          2）判断顺序表是否已满
 *          3）判断插入位置是否越界：0 <= index <= length
 *          4）插入元素所在位置后面的元素依次后移一位
 *          5）插入新元素
 *          6）插入成功后，顺序表长度加1
 * 
 * @param list 
 * @param index     下标 
 * @param element   数据
 * @return int 
 */
int SequentialListInsert(SSList *list,int index,ElemType element)
{
    int i;      // 用于移动元素时记录下标

    // 1）将用户角度的下标转为程序角度的下标
    index = index - 1;      
    // 2）判断顺序表是否已满
    if(list->length >= MAXSIZE)
    {
        printf("顺序表已满，无法继续添加数据!\n");
        return FALSE;   //添加失败
    }

    // 3）判断插入位置是否越界
    if((index < 0)||(index > list->length))
    {
        printf("插入位置不合法，请重新输入!\n");
        return FALSE;   //添加失败
    }

    // 4）待插入元素位置后面的元素依次向后后移一位
    for(i = list->length; i > index; i--)      // 
    {
        list->data[i] = list->data[i-1];
    }

    // 5）插入数据
    list->data[index] = element;

    // 6）长度加1
    list->length += 1;

    return TRUE;    //插入成功
}

/**
 * @brief   删除结点
 *          1）将用户角度的下标转为程序角度的下标：index = index - 1
 *              注：程序从0开始，用户角度为从1开始，因此index需要减1
 *          2）判断顺序表是否已满
 *          3）判断插入位置是否合法：0 <= index < length
 *              注：length指向最后一个元素的后一位，length下标元素为空，所以不可以=length
 *          4）删除元素所在位置后面的元素依次前移一位 (i=index; i<length; i++)
 *          5）删除成功后，顺序表长度减1
 * 
 * @param list 
 * @param index     下标
 * @return int 
 */
int SequentialListDelete(SSList *list,int index)
{
    int i;  // 用于移动元素时记录下标

    // 1）将用户角度的下标转为程序角度的下标
    index = index - 1;  

    // 2）判断顺序表是否已满
    if(list->length >= MAXSIZE)
    {
        printf("顺序表已满，无法继续添加数据!\n");
        return FALSE;   //添加失败
    }

    // 3）判断插入位置是否越界
    if((index < 0)||(index >= list->length))
    {
        printf("插入位置不合法，请重新输入!\n");
        return FALSE;   //添加失败
    }

    // 4）删除元素，即覆盖被删除的元素
    for(i = index; i < list->length; i++)
    {
        list->data[i] = list->data[i+1];
    }
    
    // 5）长度减1
    list->length -= 1;

    return TRUE;    // 删除成功
}

/**
 * @brief   根据下标查找结点
 *          1）判断下标是否合法
 * 
 * @param list 
 * @param index     下标
 * @param element   查找到的元素
 * @return int 
 */
int SequentialListSearchByIndex(SSList *list,int index,ElemType *element)
{

    return TRUE;    // 查找成功
}