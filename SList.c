#include"SList.h"
//增加结点
SListNode* BuySList(SListDataType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL) {
		printf("malloc fail .");
		return NULL;
	}
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}
//尾插
void SListPushBack(SListNode** Phead, SListDataType x)
{
	SListNode* NewNode = BuySList(x);
	if (*Phead == NULL) {               //空链表
		*Phead = NewNode;
	}
	else {
		SListNode* cur = *Phead;        //非空链表
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = NewNode;
	}

}
//尾删
void SListPopBack(SListNode** Phead)     
{
	if (*Phead == NULL) {             //空链表
		return;
	}
	else if ((*Phead)->next == NULL) {    //单结点
		*Phead = NULL;
	}
	else {                                //多结点
		SListNode* cur = (*Phead)->next;
		SListNode* prev = *Phead;
		while (cur->next) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
	}
}
//头插
void SListPushFront(SListNode** Phead, SListDataType x)
{
	SListNode* NewNode = BuySList(x);
	NewNode->next = *Phead;
	*Phead = NewNode;
}
//头删
void SListPopFront(SListNode** Phead)
{
	if (*Phead == NULL) {
		return;
	}
	else {
		SListNode* cur = *Phead;
		*Phead = (*Phead)->next;
		free(cur);
	}
}
//查找  假设链表各个数据都不同
SListNode* FindList(SListNode* Phead, SListDataType x)
{
	SListNode* cur = Phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	printf("No such data .");
	return NULL;
}
//打印
void SListPrint(SListNode* Phead)
{
	SListNode* cur = Phead;
	while (cur) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}