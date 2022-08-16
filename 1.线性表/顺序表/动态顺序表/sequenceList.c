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
 * @param element   结点数据
 * @return int 
 */
int SequentialListInsert(DSList *list,int index,ElemType element)
{
    int i;      // 循环变量，用于移动元素时记录下标

    // 1）将用户角度的下标转为程序角度的下标
    index = index - 1;

    // 2）判断顺序表是否已满
    if(list->length >= MAXSIZE)
    {
        printf("\n顺序表已满，无法继续添加数据!\n");
        return FALSE;   //添加失败
    }

    // 3）判断插入位置是否越界
    if((index < 0)||(index > list->length))
    {
        printf("\n插入位置不合法，请重新输入!\n");
        return FALSE;   //添加失败
    }

    // 4）待插入元素位置后面的元素依次向后后移一位
    for(i = list->length; i > index; i--)      
    {
        *(list->data + i) = *(list->data + (i-1));      // 结点元素依次后移一位
    }

    // 5）插入数据
    *(list->data + index) = element;

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
int SequentialListDelete(DSList *list,int index)
{
    int i;  // 循环变量，用于移动元素时记录下标

    // 1）将用户角度的下标转为程序角度的下标
    index = index - 1;  

    // 2）判断顺序表是否为空表
    if(list->length == 0)
    {
        printf("\n顺序表为空,无法继续删除\n");
        return FALSE;   //删除失败
    }

    // 3）判断删除位置是否越界
    if((index < 0)||(index >= list->length))
    {
        printf("\n删除位置不合法，请重新输入!\n");
        return FALSE;   //删除失败
    }

    // 4）删除元素，即覆盖被删除的元素
    for(i = index; i < list->length; i++)
    {
        *(list->data + i) = *(list->data + (i+1));
    }
    
    // 5）长度减1
    list->length -= 1;

    return TRUE;    // 删除成功
}

/**
 * @brief   根据下标查找结点
 *          1）将用户角度的下标转为程序角度的下标：index = index - 1
 *              注：程序从0开始，用户角度为从1开始，因此index需要减1
 *          2）判断顺序表是否为空表
 *          3）判断下标是否合法
 *          4）返回index对应的结点
 * 
 * @param list 
 * @param index     下标
 * @param element   查找到的元素
 * @return int 
 */
int SequentialListSearchByIndex(DSList list,int index,ElemType *element)
{
    int i;      // 循环变量
    // 1）将用户角度的下标转为程序角度的下标
    index = index - 1;

    // 2）判断顺序表是否为空表
    if(list.length == 0)
    {
        printf("\n顺序表为空,无法进行查找操作\n");
        return FALSE;   //查找失败
    }

    // 3）判断下标是否合法
    if((index < 0)||(index >= list.length))
    {
        printf("\n查找位置不合法，请重新输入!\n");
        return FALSE;   //查找失败
    }

    // 4）返回到的查找元素
    printf("\n下标为%d的结点为:\n",index + 1);      // 将程序角度的index转为用户角度的index
    SwapNodeInfo(element,(list.data + index));

    return TRUE;    // 查找成功
}

/**
 * @brief   根据下标查找结点
 *          1）将用户角度的下标转为程序角度的下标：index = index - 1
 *              注：程序从0开始，用户角度为从1开始，因此index需要减1
 *          2）判断顺序表是否为空表
 *          3）判断下标是否合法
 *          4）返回index对应的结点
 * 
 * @param list 
 * @param index     下标
 * @param element   查找到的元素
 * @return int 
 */
int SequentialListSearchByIndex(DSList list,int index,ElemType *element)
{
    int i;      // 循环变量
    // 1）将用户角度的下标转为程序角度的下标
    index = index - 1;

    // 2）判断顺序表是否为空表
    if(list.length == 0)
    {
        printf("\n顺序表为空,无法进行查找操作\n");
        return FALSE;   //查找失败
    }

    // 3）判断下标是否合法
    if((index < 0)||(index >= list.length))
    {
        printf("\n查找位置不合法，请重新输入!\n");
        return FALSE;   //查找失败
    }

    // 4）返回到的查找元素
    printf("\n下标为%d的结点为:\n",index + 1);      // 将程序角度的index转为用户角度的index
    SwapNodeInfo(element,&(list.data[index]));

    return TRUE;    // 查找成功
}

/**
 * @brief   根据ID查找结点
 *          1）判断顺序表是否为空表
 *          2）遍历顺序表，查找对应id元素的下标
 *          3）返回对应id结点
 * 
 * @param list 
 * @param id        查找id 
 * @param element   查找到的结点
 * @return int 
 */
int SequentialListSearchById(DSList list, char* id, ElemType *element)
{
    int i;          // 循环变量，用于遍历顺序表
    int index;      // 记录查找到的对应元素的下标

    // 1）判断顺序表是否为空表
    if(list.length == 0)
    {
        printf("\n顺序表为空,无法进行查找操作\n");
        return FALSE;   //查找失败
    }

    // 2）遍历顺序表，查找对应id元素的下标
    for(i = 0; i < list.length; i++)
    {
        // strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
        if(strcmp(id,(list.data + i)->id) == 0)     
        {
            index = i;      // 找到对应id的元素，记录下表
            break;          // 结束循环
        }
    }

    // 3）返回对应id结点
    SwapNodeInfo(element,(list.data + index));

    return TRUE;
}