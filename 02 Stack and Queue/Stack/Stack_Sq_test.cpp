#include "Stack_Sq.h"
#include <iostream>

using namespace std;

void visit(SElemType e)
{
    cout<<e<<" ";
}

int main()
{
    SqStack *s = new SqStack;
    InitStack_Sq(s);
    Push_Sq(s, 5);
    Push_Sq(s, 10);
    Push_Sq(s, 15);

    void (*visitFunc)(SElemType);
    visitFunc = visit;
    StackTraverse_Sq(s, visitFunc);
    int a;
    Pop_Sq(s, a);
    cout<<a<<endl;
    Pop_Sq(s, a);
    cout<<a<<endl;
    DestroyStack_Sq(s);
    cout<<s->stackSize<<endl;
    return 0;
}
