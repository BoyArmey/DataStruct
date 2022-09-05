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
    linkList *list1 = LinkListInit();
    // LinkListIsEmpty(*list);      // 测试链表是否为空
    
    // 保存查找到的结点信息
    ElemType *elemIndex = (ElemType*)malloc(sizeof(ElemType));
    ElemType *elemId = (ElemType*)malloc(sizeof(ElemType));

    // 尾部追加元素
    LinkListAddEnd(list,datas[2]);
    LinkListAddEnd(list,datas[3]);
    // 输出链表信息
    printf("\n---------------------------尾部添加数据----------------------------\n");
    LinkListShow(*list); 
    
    // 头部追加数据
    LinkListAddFirst(list,datas[1]);
    LinkListAddFirst(list,datas[0]);
    // 输出链表信息
    printf("\n---------------------------头部添加数据----------------------------\n");
    LinkListShow(*list);        
    
    // 插入数据
    LinkListInsert(list,datas[4],1);        // 头部插入
    LinkListInsert(list,datas[5],3);        // 尾部插入
    LinkListInsert(list,datas[6],7);        // 中间插入
    // 输出链表信息
    printf("\n---------------------------插入数据----------------------------\n");
    LinkListShow(*list);  

    
    printf("\n---------------------------依据ID查找数据----------------------------\n");
    if(LinkListSearchById(*list,"0001",elemId))
    {
        NodeInfoPrint(*elemId);
    }
    else
    {
        printf("\n未查找到相关结点信息\n");
    }
    if(LinkListSearchById(*list,"0007",elemId))      
    {
        NodeInfoPrint(*elemId);
    }
    else
    {
        printf("\n未查找到相关结点信息\n");
    }
    if(LinkListSearchById(*list,"0009",elemId))       // 不存在的结点
    {
        NodeInfoPrint(*elemId);
    }
    else
    {
        printf("\n未查找到相关结点信息\n");
    }


    printf("\n---------------------------依据下标查找数据----------------------------\n");
    // 查找中间结点
    if(LinkListSearchByIndex(*list,2,elemIndex))
    {
        NodeInfoPrint(*elemIndex);
    }
    else
    {
        printf("\n未查找到相关结点信息\n");
    }
    // 查找第一个结点
    if(LinkListSearchByIndex(*list,1,elemIndex))
    {
        NodeInfoPrint(*elemIndex);
    }
    else
    {
        printf("\n未查找到相关结点信息\n");
    }
    // 查找最后一个结点
    if(LinkListSearchByIndex(*list,7,elemIndex))
    {
        NodeInfoPrint(*elemIndex);
    }
    else
    {
        printf("\n未查找到相关结点信息\n");
    } 
    
    // 依据下标删除结点
    printf("\n---------------------------依据下标删除数据----------------------------\n");
    LinkListDeleteByIndex(list,1);      // 删除第一个结点
    LinkListDeleteByIndex(list,2);      // 删除中间结点
    LinkListDeleteByIndex(list,5);      // 删除最后一个结点
    LinkListShow(*list);

    // 依据ID删除结点
    printf("\n---------------------------依据ID删除数据----------------------------\n");
    // 插入数据，用于删除测试
    printf("\n删除前：\n");
    LinkListInsert(list,datas[4],1);
    LinkListInsert(list,datas[5],3);
    LinkListInsert(list,datas[6],7); 
    LinkListShow(*list);
    // 删除操作
    printf("\n删除后：\n");
    LinkListDeleteById(list,"0005");    // 删除第一个结点
    LinkListDeleteById(list,"0006");    // 删除中间结点
    LinkListDeleteById(list,"0007");    // 删除最后一个结点
    LinkListShow(*list);

    // 判断列表是否为空
    LinkListIsEmpty(*list);


    // 链表逆序
    printf("\n---------------------------链表逆序----------------------------\n");
    list1 = LinkLisInverse(list);       // 有问题
    LinkListShow(*list1);

    // 销毁链表


    return 0;
}