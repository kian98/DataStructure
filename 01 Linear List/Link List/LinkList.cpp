#include "LinkList.h"
#include <stdexcept>
#include <iostream>

Status InitList(LL_ptr L)
{
    L->next = nullptr;
    return OK;
}

Status DestroyList(LL_ptr L)
{
    LL_ptr p = L->next;
    while (p != nullptr)
    {
        LL_ptr temp = p->next;
        delete p;
        p = temp;
    }
    L = nullptr;
    return OK;
}

Status ClearList(LL_ptr L)
{
    LL_ptr p = L->next;
    while (p != nullptr)
    {
        LL_ptr temp = p->next;
        delete p;
        p = temp;
    }
    L->next = nullptr;
}

Status Append_L(LL_ptr L, const ElemType e)
{
    if(L == nullptr) return ERROR;
    LL_ptr p = L;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    LNode *newNode;
    try
    {
        newNode = new LNode;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(OVERFLOW);
    }
    newNode->data = e;
    newNode->next = nullptr;
    p->next = newNode;
    return OK;
}

Status Insert_L(LL_ptr L, int i,const ElemType e)
{
    LL_ptr p = L;     // p为头结点
    int index = 0;

    // 当p指向最后一个结点，或p已经指向第i - 1个结点
    while(p!=nullptr && index < i-1)
    {
        p = p->next;
        ++ index;
    }
    if(p==nullptr && index < i - 1) return OVERFLOW;
    LNode *newNode = new LNode;
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

int GetLength_L(const LL_ptr L)
{
    LL_ptr p = L;     // p为头结点
    int count = 0;

    // 当p指向最后一个结点，或p已经指向第i - 1个结点
    while(p!=nullptr)
    {
        p = p->next;
        ++ count;
    }
    return count - 1;
}

bool IsEmpty_L(const LL_ptr L)
{
    if(L==nullptr)return false;
    return (L->next == nullptr)?true:false;
}

Status ListTraverse(const LL_ptr L)
{
    if(L==nullptr)return ERROR;
    LL_ptr p = L->next;     // p为头结点

    // 当p指向最后一个结点，或p已经指向第i - 1个结点
    while(p!=nullptr)
    {
        std::cout<<p->data<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
    return OK;
}

// 默认为带有头结点的单链表
Status GetElem_L(LL_ptr L, int i, ElemType &e)
{
    // L为单链表的头指针，则L指向的是头结点
    LL_ptr p = L->next; // p指向第一个结点
    int index = 1;
    // 注意此处index<i，因为p总是指向第index个结点
    while (p != nullptr && index < i)
    {
        p = p->next;
        ++index;
    }
    if (p == nullptr || index > i)
        return ERROR; // p为空指针，说明链表长度不足，index>i，则说明输入i有误
    e = p->data;
    return OK;
}

Status MergeList_L(LL_ptr la, LL_ptr lb, LL_ptr lc, bool (*compare)(ElemType, ElemType))
{
    if(!InitList(lc))return ERROR;
    LL_ptr pa = la->next;
    LL_ptr pb = lb->next;
    while(pa!=nullptr && pb!= nullptr)
    {
        ElemType ea = pa->data;
        ElemType eb = pb->data;
        if(compare(ea,eb))
        {
            //ea>=eb
            Append_L(lc, eb);
            pb = pb->next;
        }else
        {
            Append_L(lc, eb);
            pb = pb->next;
        }
    }
    while(pa!=nullptr)
    {
        Append_L(lc, pa->data);
        pa = pa->next;
    }
    while(pb!=nullptr)
    {
        Append_L(lc, pb->data);
        pb = pb->next;
    }
    DestroyList(la);DestroyList(lb);
    return OK;
}