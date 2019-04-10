#include "SqList.h"
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <iostream>

Status InitList_Sq(SqList &L)
{
	// 初始化空的线性表，存储分配

	// 使用new运算符进行内存分配，若失败，抛出异常
	try
	{
		L.elem = new ElemType[LIST_INIT_SIZE];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(OVERFLOW);
	}

	// 表空
	L.length = 0;
	// 初始容量
	L.listSize = LIST_INIT_SIZE;

	return OK;
}

Status DestroyList_Sq(SqList &L)
{
	delete[] L.elem;
	L.elem = nullptr;
	L.length = 0;
	L.listSize = 0;
}

Status ClearList_Sq(SqList &L)
{
	L.length = 0;
	return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
	// 插入元素e到第i个元素前，则e变为第i个元素

	// 表的元素总数为length，插入元素时i最小为第一个元素前，即插到首位，最大为length+1，即插到末尾
	if (i < 1 || i > L.length + 1)
		return ERROR;

	if (L.length >= L.listSize)
	{
		// 使用realloc增加分配的内存
		try
		{
			ElemType *newBase = new ElemType[L.listSize + LIST_INCREAMENT];
			memmove(newBase, L.elem, L.length * sizeof(ElemType));
			delete[] L.elem;
			L.elem = newBase;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			exit(ERROR);
		}

		L.listSize += LIST_INCREAMENT;
	}

	ElemType *insertAddr = &(L.elem[i - 1]);
	// 将插入位置之后的每一个元素向后移动，由于顺序存储，可以直接地址加减
	for (ElemType *p = &(L.elem[L.length - 1]); p >= insertAddr; --p)
	{
		*(p + 1) = *p;
	}
	*insertAddr = e;
	++L.length;
	return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	if (i < 1 || i > L.length + 1)
		return ERROR;

	ElemType *p = &(L.elem[i - 1]);
	e = *p;
	ElemType *tailAddr = L.elem + L.length - 1;

	// 将删除元素之后的每个元素向前移动一位
	for (++p; p <= tailAddr; ++p)
		*(p - 1) = *p;

	--L.length;
	return OK;
}

bool ListEmpty_Sq(const SqList L)
{
	return (L.length == 0) ? true : false;
}

int ListLength_Sq(const SqList L)
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
	if (i < 1 || i > L.length + 1)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int LocateElem_Sq(const SqList L, ElemType e, bool (*compare)(ElemType, ElemType))
{
	ElemType *addr = L.elem;
	int index = 1;
	while (index <= L.length && !compare(e, *addr++))
		++index;
	if (index <= L.length)
		return index;
	else
		return -1;
}

Status PriorElem_Sq(const SqList L, ElemType cur_e, ElemType &prior_e, bool (*compare)(ElemType, ElemType))
{
	int index = LocateElem_Sq(L, cur_e, compare);
	if (index <= 1)
		return ERROR;
	GetElem(L, index - 1, prior_e);
	return OK;
}
Status NextElem_Sq(const SqList L, ElemType cur_e, ElemType &next_e, bool (*compare)(ElemType, ElemType))
{
	int index = LocateElem_Sq(L, cur_e, compare);
	if (index >= L.length)
		return ERROR;
	GetElem(L, index + 1, next_e);
	return OK;
}

Status ListTraverse(const SqList L, void (*visit)(ElemType e))
{
	for(int index = 1;index <= L.length;index ++)
	{
		ElemType e;
		GetElem(L, index, e);
		visit(e);
	}
	return OK;
}

bool isEqual(int a, int b)
{
    return a==b?true:false;
}

void UnionList(SqList &La, const SqList Lb)
{
	int len_a = La.length;
	int len_b = Lb.length;
	for(int i = 1;i<=len_b;++i)
	{
		ElemType e;
		GetElem(Lb, i, e);
		if(!LocateElem_Sq(Lb, e, isEqual))ListInsert_Sq(La, ++len_a, e);
	}
}

void MergeList_Sq(const SqList La, const SqList Lb, SqList &Lc)
{
	// 要求La与Lb为递增排列
	ElemType* tail_a = La.elem + La.length -1;;
	ElemType* tail_b = Lb.elem + Lb.length -1;

	try
	{
		Lc.elem = new ElemType[La.length + Lb.length];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(OVERFLOW);
	}
	Lc.length = La.length + Lb.length;
	Lc.listSize  = Lc.length;

	ElemType* index_a = La.elem;
	ElemType* index_b = Lb.elem;
	ElemType* index_c = Lc.elem;
	while(index_a <= tail_a && index_b <= tail_b)
	{
		if(*index_a <= *index_b)
		{
			*index_c++ = *index_a ++;
		}
		else
		{
			*index_c++ = *index_b++;
		}
	}

	while(index_a <=tail_a) *index_c++ = *index_a++;
	while(index_b <=tail_b) *index_c++ = *index_b++;
	
}