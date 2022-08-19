#ifndef _UTILS_H
#define _UTILS_H

#include "sequenceList.h"


// 解决控制台中程序执行时显示中文乱码的问题
void windows_cmd_support_utf8();

// 生成数据结点
ElemType GetElement();

// 输出结点的数据信息
void NodeInfoPrint(ElemType elemtype);

// 结点数据拷贝
void NodeInfoCopy(ElemType *elemtype1,ElemType *elemtype2);

// 结点数据交换
void NodeInfoSwap(ElemType *elem1,ElemType *elem2);

#endif