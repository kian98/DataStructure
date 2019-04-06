/* 
 * 线性表的链式结构存储
 */

#ifndef LINKLIST_H
#define LINKLIST_H

#define ElemType int 			// 数据类型
#define LIST_INIT_SIZE 1 		// 线性表存储空间的初始大小
#define LIST_INCREAMENT 1 		// 线性表存储空间增量

#define Status int 				// 返回状态
#define OVERFLOW 0 				// 溢出错误代码
#define OK 1
#define ERROR 0

struct LNode
{
    ElemType data;
    LNode *next;
};
typedef  LNode* LL_ptr ;

Status InitList(LL_ptr L);      // 初始化，构造空链表
Status DestroyList(LL_ptr L);   // 删除整个链表
Status ClearList(LL_ptr L);     // 清空链表，只剩下头结点

Status Append_L(LL_ptr L, const ElemType e);        // 链表尾部添加元素
Status Insert_L(LL_ptr L, int i,const ElemType e);  // 链表第i个位置插入元素

bool IsEmpty_L(const LL_ptr L);
int GetLength_L(const LL_ptr L);

Status ListTraverse(const LL_ptr L);

Status GetElem_L(LL_ptr L, int i, ElemType &e);

// 传入la，lb两个递增链表，进行合并s
Status MergeList_L(LL_ptr la, LL_ptr lb, LL_ptr lc, bool (*compare)(ElemType, ElemType));

#endif