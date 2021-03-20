#include"List.h"
//����ͷ�ڵ�
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
//���ӽ��
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
//β��
void ListPushBack(ListNode* Phead, ListDataType x)
{
	ListNode* NewNode = BuyList(x);
	ListNode* tail = Phead->prev;
	tail->next = NewNode;
	NewNode->prev = tail;
	Phead->prev = NewNode;
	NewNode->next = Phead;
}
//βɾ
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
//ͷ��
void ListPushFront(ListNode* Phead, ListDataType x)
{
	ListNode* NewNode = BuyList(x);
	ListNode* NextNode = Phead->next;
	Phead->next = NewNode;
	NewNode->prev = Phead;
	NewNode->next = NextNode;
	NextNode->prev = NewNode;
}
//ͷɾ
void ListPopFront(ListNode* Phead)
{
	assert(Phead);
	ListNode* NextNode = Phead->next;
	ListNode* NextNext = NextNode->next;
	Phead->next = NextNext;
	NextNext->prev = Phead;
	free(NextNode);
}
//��ӡ
void ListPrint(ListNode* Phead)
{
	ListNode* cur = Phead->next;
	while (cur != Phead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}