#include <stdio.h>
#include <stdlib.h>
#include "sequenceList.h"
#include "utils.h"

int main()
{
    // 初始化数据
    ElemType datas[7] = {
        {"0001","tom",19},
        {"0002","Ailsa",18},
        {"0003","小明",19},
        {"0004","小红",18},
        {"0005","test1",18},
        {"0006","test2",18},
        {"0007","test3",18}
    };

    ElemType elem1,elem2,elem3,elem4;     // 接收查找到的数据

    SSList list;
    // 初始化顺序表
    SequentialListInit(&list);
    
    // 添加数据
    SequentialListAdd(&list,datas[0]);
    SequentialListAdd(&list,datas[1]);
    SequentialListAdd(&list,datas[2]);
    SequentialListAdd(&list,datas[3]);
    printf("\n---------------------------添加数据----------------------------\n");
    SequentialListShow(list);

    
    // 插入数据
    SequentialListInsert(&list,1,datas[4]);     // 首部插入
    SequentialListInsert(&list,3,datas[5]);     // 中间插入
    SequentialListInsert(&list,7,datas[6]);     // 尾部插入
    printf("\n---------------------------插入数据----------------------------\n");
    SequentialListShow(list);


    // 删除数据
    SequentialListDelete(&list,7);          // 删除尾部元素
    SequentialListDelete(&list,3);          // 删除中间元素
    SequentialListDelete(&list,1);          // 删除头部元素
    printf("\n---------------------------删除数据----------------------------\n");
    SequentialListShow(list);


    // 按指定下标查找数据
    printf("\n---------------------------按指定下标查找数据----------------------------\n");
    /* SequentialListSearchByIndex()返回值为TRUE或FALSE，所以使用if判断是否查找到元素 */
    // 查找首元素
    if(SequentialListSearchByIndex(list,1,&elem1))
    {
        PrintNodeInfo(elem1);
    }
    else
    {
        printf("\n查找错误!\n");
    }
    // 查找末尾元素
    if(SequentialListSearchByIndex(list,4,&elem1))
    {
        PrintNodeInfo(elem1);
    }
    else
    {
        printf("\n查找错误!\n");
    }
    // 查找中间元素
    if(SequentialListSearchByIndex(list,2,&elem1))
    {
        PrintNodeInfo(elem1);
    }
    else
    {
        printf("\n查找错误!\n");
    }

    // 按指定下标查找数据
    printf("\n---------------------------按指定id查找数据----------------------------\n");
    // 查找id为"0003"的结点信息
    if(SequentialListSearchById(list,"0003",&elem1))
    {
        PrintNodeInfo(elem1);
    }
    else
    {
        printf("\n查找错误!\n");
    }



    // 输出顺序表结点信息
    //SequentialListShow(list);
    return 0;
}