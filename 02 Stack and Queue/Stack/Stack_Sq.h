#ifndef STACK_SQ_H
#define STACK_SQ_H


#define SElemType int 			// 数据类型
#define STACK_INIT_SIZE 1 		// 存储空间的初始大小
#define STACK_INCREAMENT 1 		// 存储空间增量

#define Status int 				// 返回状态
#define OVERFLOW 0 				// 溢出错误代码
#define OK 1
#define ERROR 0


// 顺序栈，以数组为存储结构，即以连续地址存储栈中元素

struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stackSize;
};

Status InitStack_Sq(SqStack *s);

Status DestroyStack_Sq(SqStack *s);

Status ClearStack_Sq(SqStack *s);

Status IsStackEmpty_Sq(const SqStack *s);

int StackLength_Sq(const SqStack *s);

Status GetTop_Sq(const SqStack *s);

Status Push_Sq(SqStack *s, SElemType *e);

Status Pop_Sq(SqStack *s, SElemType *e);

Status StackTraverse_Sq(SqStack *s, Status (* visit)());

#endif