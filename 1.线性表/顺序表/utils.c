#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


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
    scanf("%d",&element.id);
    printf("请输入姓名:");
    scanf("%s",element.name);
    printf("请输入年龄:");
    scanf("%d",&element.age);
    return element;
}


/**
 * @brief 打印结点的数据信息
 * 
 * @param elemtype     待打印的结点
 */
void PrintNodeInfo(ElemType elemtype)
{
    //printf("ID\t姓名\t年龄\n");
    printf("%d\t%s\t%d\n",elemtype.id,elemtype.name,elemtype.age);
}

//打印顺序表信息
void PrintList(DSList* list)
{
    //待更新
}