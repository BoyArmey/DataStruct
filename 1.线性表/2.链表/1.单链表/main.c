#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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
    
    // 保存查找到的结点信息
    ElemType *elem = (ElemType*)malloc(sizeof(ElemType));

    // 追加元素
    LinkListAddEnd(list,datas[0]);
    LinkListAddEnd(list,datas[1]);
    LinkListAddEnd(list,datas[2]);
    LinkListAddEnd(list,datas[3]);
    // 输出链表信息
    printf("\n---------------------------尾部添加数据----------------------------\n");
    LinkListShow(*list); 


    LinkListAddFirst(list,datas[0]);
    LinkListAddFirst(list,datas[1]);
    LinkListAddFirst(list,datas[2]);
    LinkListAddFirst(list,datas[3]);
    // 输出链表信息
    printf("\n---------------------------头部添加数据----------------------------\n");
    LinkListShow(*list);        

    // 插入数据
    LinkListInsert(list,datas[4],1);        // 头部插入
    LinkListInsert(list,datas[5],3);        // 尾部插入
    LinkListInsert(list,datas[6],11);        // 中间插入
    // 输出链表信息
    printf("\n---------------------------插入数据----------------------------\n");
    LinkListShow(*list);  


    printf("\n---------------------------查找数据----------------------------\n");
    LinkListSearchByIndex(*list,2,elem);
    NodeInfoPrint(*elem);
    LinkListSearchByIndex(*list,1,elem);
    NodeInfoPrint(*elem);
    LinkListSearchByIndex(*list,11,elem);
    NodeInfoPrint(*elem);


    return 0;
}