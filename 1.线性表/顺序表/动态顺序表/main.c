#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "sequenceList.h"


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


    DSList list;

    // 初始化顺序表
    SequentialListInit(&list);

    // 添加数据
    SequentialListAdd(&list,datas[0]);
    SequentialListAdd(&list,datas[1]);
    SequentialListAdd(&list,datas[2]);
    SequentialListAdd(&list,datas[3]);
    printf("\n---------------------------添加数据----------------------------\n");
    SequentialListShow(list);




    // 添加元素
    return 0;
}