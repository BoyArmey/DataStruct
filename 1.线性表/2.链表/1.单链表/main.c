#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "utils.h"
#include "linkList.h"

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


    // 初始化链表
    linkList *list = LinkListInit();

    // 追加元素
    LinkListAdd(list,datas[0]);
    LinkListAdd(list,datas[1]);
    LinkListAdd(list,datas[2]);
    LinkListAdd(list,datas[3]);
    // 输出链表信息
    printf("\n---------------------------添加数据----------------------------\n");
    LinkListShow(*list);         




    return 0;
}