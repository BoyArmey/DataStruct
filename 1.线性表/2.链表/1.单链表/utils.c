#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "linkList.h"


/**
 * @brief 解决控制台中程序执行时输出中文乱码的问题
 * 
 */
void winCmd_support_utf8()
{
    // 如果是Windows系统，则修改控制台的编码为 UTF-8
    #ifdef WIN32 
	system("chcp 65001 > nul");
    #endif
}

/**
 * @brief 处理用户输入的数据，生成顺序表的结点
 * 
 * @return ElemType 返回结点所需的数据类型
 */
ElemType GetElement()
{
    //解决控制台中文乱码问题
    winCmd_support_utf8();
    //声明结点
    ElemType element;
    printf("请输入ID:");
    scanf("%s",element.id);
    printf("请输入姓名:");
    scanf("%s",element.name);
    printf("请输入年龄:");
    scanf("%d",&element.age);
    return element;
}


/**
 * @brief 打印结点的数据信息
 * 
 * @param elem     待打印的结点
 */
void NodeInfoPrint(ElemType elem)
{
    //printf("ID\t姓名\t年龄\n");
    printf("%-10s\t%-10s\t%-10d\n",elem.id,elem.name,elem.age);
}

/**
 * @brief   结点数据拷贝
 *          将第二个参数的数据保存到第一个参数中
 * @param elem1     结点1
 * @param elem2     结点2
 */
void NodeInfoCopy(ElemType *elem1,ElemType *elem2)
{
    strcpy(elem1->id,elem2->id);          // 保存id字段
    strcpy(elem1->name,elem2->name);      // 保存姓名字段
    elem1->age = elem2->age;               // 保存年龄字段
}

/**
 * @brief       结点数据交换
 *              交换两个结点的数据信息
 * @param elem1 
 * @param elem2 
 * @return * void 
 */
void NodeInfoSwap(ElemType *elem1,ElemType *elem2)
{   
    ElemType elem;  // 用于交换的中间变量
    
    // 保存elem2的信息
    strcpy(elem.id,elem2->id);
    strcpy(elem.name,elem2->name);
    elem.age = elem2->age;

    // 将elem1的信息保存到elem2中
    strcpy(elem2->id,elem1->id);
    strcpy(elem2->name,elem1->name);
    elem2->age = elem1->age;

    // 将elem1的信息修改为elem2的信息
    strcpy(elem1->id,elem.id);
    strcpy(elem1->name,elem.name);
    elem1->age = elem.age;
}