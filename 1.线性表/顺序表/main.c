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

    SSList list;
    // 初始化顺序表
    SequentialListInit(&list);
    
    // 添加数据
    SequentialListAdd(&list,datas[0]);
    SequentialListAdd(&list,datas[1]);
    SequentialListAdd(&list,datas[2]);
    SequentialListAdd(&list,datas[3]);
    
    // 插入数据
    SequentialListInsert(&list,1,datas[4]);     // 首部插入
    SequentialListInsert(&list,3,datas[5]);     // 中间插入
    SequentialListInsert(&list,7,datas[6]);     // 尾部插入


    // 输出顺序表结点信息
    SequentialListShow(list);
    return 0;
}