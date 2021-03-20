#include"List.h"
//开辟头节点
ListNode* CreateList()
{
	ListNode* Head = (ListNode*)malloc(sizeof(ListNode));
	if (Head == NULL) {
		printf("CreateList malloc error .");
		return NULL;
	}
	Head->data = 0;
	Head->next = Head;
	Head->prev = Head;
	return Head;
}
//增加结点
ListNode* BuyList(ListDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	if (NewNode == NULL) {
		printf("BuyList malloc error");
		exit(0);
	}
	NewNode->prev = NULL;
	NewNode->next = NULL;
	NewNode->data = x;
	return NewNode;
}
//尾插
void ListPushBack(ListNode* Phead, ListDataType x)
{
	ListNode* NewNode = BuyList(x);
	ListNode* tail = Phead->prev;
	tail->next = NewNode;
	NewNode->prev = tail;
	Phead->prev = NewNode;
	NewNode->next = Phead;
}
//尾删
void ListPopBack(ListNode* Phead)
{
	assert(Phead);
	assert(Phead->next != Phead);
	ListNode* tail = Phead->prev;
	tail = tail->prev;
	free(tail->next);
	tail->next = Phead;
	Phead->prev = tail;
}
//头插
void ListPushFront(ListNode* Phead, ListDataType x)
{
	ListNode* NewNode = BuyList(x);
	ListNode* NextNode = Phead->next;
	Phead->next = NewNode;
	NewNode->prev = Phead;
	NewNode->next = NextNode;
	NextNode->prev = NewNode;
}
//头删
void ListPopFront(ListNode* Phead)
{
	assert(Phead);
	ListNode* NextNode = Phead->next;
	ListNode* NextNext = NextNode->next;
	Phead->next = NextNext;
	NextNext->prev = Phead;
	free(NextNode);
}
//打印
void ListPrint(ListNode* Phead)
{
	ListNode* cur = Phead->next;
	while (cur != Phead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}