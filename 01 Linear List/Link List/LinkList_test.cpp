#include "LinkList.h"
#include <iostream>

using namespace std;

int main()
{
    LL_ptr L;
    InitList(L);
    Append_L(L, 10);
    Append_L(L, 20);
    ElemType e;
    GetElem_L(L, 2, e);
    cout<<e<<endl;
    ClearList(L);
    Append_L(L,30);
    Append_L(L,31);
    Insert_L(L, 2, 2);
    GetElem_L(L, 3, e);
    cout<<e<<endl;
    cout<< GetLength_L(L)<<endl;
    ListTraverse(L);
    DestroyList(L);
    return 0;
}