#include"SList.h"
//���ӽ��
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
//β��
void SListPushBack(SListNode** Phead, SListDataType x)
{
	SListNode* NewNode = BuySList(x);
	if (*Phead == NULL) {               //������
		*Phead = NewNode;
	}
	else {
		SListNode* cur = *Phead;        //�ǿ�����
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = NewNode;
	}

}
//βɾ
void SListPopBack(SListNode** Phead)     
{
	if (*Phead == NULL) {             //������
		return;
	}
	else if ((*Phead)->next == NULL) {    //�����
		*Phead = NULL;
	}
	else {                                //����
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
//ͷ��
void SListPushFront(SListNode** Phead, SListDataType x)
{
	SListNode* NewNode = BuySList(x);
	NewNode->next = *Phead;
	*Phead = NewNode;
}
//ͷɾ
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
//����  ��������������ݶ���ͬ
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
//��ӡ
void SListPrint(SListNode* Phead)
{
	SListNode* cur = Phead;
	while (cur) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}