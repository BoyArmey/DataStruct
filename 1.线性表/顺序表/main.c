#include <stdio.h>
#include <stdlib.h>
#include "sequenceList.h"
#include "utils.h"

int main()
{
    ElemType datas[4] = {
        {"0001","tom",19},
        {"0002","Ailsa",18},
        {"0003","小明",19},
        {"0004","小红",18}
    };

    SSList list;
    //初始化顺序表
    SequentialListInit(&list);
    
    //添加数据
    SequentialListAdd(&list,datas[0]);
    SequentialListAdd(&list,datas[1]);
    SequentialListAdd(&list,datas[2]);
    SequentialListAdd(&list,datas[3]);
    
    //打印顺序表
    SequentialListShow(list);
    return 0;
}