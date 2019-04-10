#include "Stack_Sq.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstring>

Status InitStack_Sq(SqStack *s)
{
	try
	{
        s->base = new SElemType[STACK_INIT_SIZE];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(OVERFLOW);
	}

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack_Sq(SqStack *s)
{
    delete[] s->base;
    s->base = nullptr;
    s->top = nullptr;
    s->stackSize = 0;
    return OK;
}

Status ClearStack_Sq(SqStack *s)
{
    s->stackSize = 0;
    return OK;
}

bool IsStackEmpty_Sq(const SqStack *s)
{
    return (s->stackSize == 0)?true:false;
}

int StackLength_Sq(const SqStack *s)
{
    return s->stackSize;
}

Status GetTop_Sq(const SqStack *s, SElemType &e)
{
    if(s->stackSize == 0)return ERROR;
    e = *(s->top - 1);
    return OK;
}

Status Push_Sq(SqStack *s, SElemType e)
{
    if(s->top - s->base > s->stackSize)
    {
        try
		{
			SElemType *newBase = new SElemType[s->stackSize+ STACK_INCREAMENT];
			memmove(newBase, s->base, s->stackSize* sizeof(SElemType));
			delete[] s->base;
			s->base = newBase;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			exit(ERROR);
		}

		s->stackSize += STACK_INCREAMENT;
    }
    *s->top++ = e;
    ++ s->stackSize;
    return OK;
}

Status Pop_Sq(SqStack *s, SElemType &e)
{
    if(s->stackSize == 0)return ERROR;
    e = *--s->top;
    --s->stackSize;
    return OK;
}

Status StackTraverse_Sq(SqStack *s, void (* visit)(SElemType e))
{
    if(s->stackSize != 0)
    {
        for(int i = 0;i<s->stackSize;++i)
        {
            visit(*(s->base+i));
        }
    }
    return OK;
}