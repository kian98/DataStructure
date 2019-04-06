#include "SqList.h"
#include <iostream>

using namespace std;

bool isEqual(int a, int b)
{
    return a==b?true:false;
}

void visit(int x)
{
    cout<<x<<" ";
}

int main()
{
    SqList L = SqList();

    // 初始化
    InitList_Sq(L);

    // 插入元素，获取元素
    ListInsert_Sq(L, 1, 4);
    ListInsert_Sq(L, 1, 1);
    ListInsert_Sq(L, 1, 2);
    ListInsert_Sq(L, 2, 5);
    int getX;
    GetElem(L, 2, getX);
    cout<<"Num at pos 2: "<<getX<<endl;

    // 获取表长度与是否为空
    if(!ListEmpty_Sq(L))cout<<"Length: "<<ListLength_Sq(L)<<endl;
    
    // 删除元素
    int deleteNum;
    ListDelete_Sq(L, 1, deleteNum);
    cout << "Delete: "<<deleteNum<<endl;

    // 查找元素
    bool (*compare)(int ,int);
    compare = isEqual;
    cout<<"Num 4 is at: "<<LocateElem_Sq(L, 4, compare)<<endl;

    // 遍历表
    void (*visitFunc)(int);
    visitFunc = visit;
    ListTraverse(L, visitFunc);

    return 0;
}