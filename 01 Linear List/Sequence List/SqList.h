/*
 * 线性表的顺序存储结构
 */

#ifndef SQLIST_H
#define SQLIST_H

#define ElemType int 			// 数据类型
#define LIST_INIT_SIZE 1 		// 线性表存储空间的初始大小
#define LIST_INCREAMENT 1 		// 线性表存储空间增量

#define Status int 				// 返回状态
#define OVERFLOW 0 				// 溢出错误代码
#define OK 1
#define ERROR 0

struct SqList
 {
 	ElemType *elem;
 	int length;
 	int listSize;
 }; 

Status InitList_Sq(SqList &L); 	// 初始化线性表
Status DestroyList_Sq(SqList &L); 	// 销毁线性表
Status ClearList_Sq(SqList &L); 	// 清空线性表

// 插入与删除操作主要耗时在元素的移动上，时间复杂度均为 O(n)
Status ListInsert_Sq(SqList &L, int i, ElemType e); 	// 在第i个元素之前插入元素e
Status ListDelete_Sq(SqList &L, int i, ElemType &e); 	// 删除第i个元素，并用e返回值

// 获取表的属性，复杂度为 O(1)
bool ListEmpty_Sq(const SqList L);
int ListLength_Sq(const SqList L);

// 按下标获取元素
Status GetElem(SqList L, int i, ElemType &e);

// 查找某元素在表中的位置，使用compare函数作为大小比较
int LocateElem_Sq(const SqList L, ElemType e, bool (*compare)(ElemType, ElemType));

// 返回指定元素的前驱元素
Status PriorElem_Sq(const SqList L, ElemType cur_e, ElemType &prior_e, bool (*compare)(ElemType, ElemType));
// 返回指定元素的后继元素
Status NextElem_Sq(const SqList L, ElemType cur_e, ElemType &next_e, bool (*compare)(ElemType, ElemType));
// 遍历元素
Status ListTraverse(const SqList L, void (* visit)(ElemType e));

// 线性表求并集
void UnionList(SqList &La, const SqList Lb);

// 合并两个有序线性表
void MergeList_Sq(const SqList La, const SqList Lb, SqList &Lc);

#endif