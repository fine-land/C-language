#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QueueDataType;
typedef
struct QueueNode {
	struct QueueNode* next;
	QueueDataType data;
}QueueNode;

typedef 
struct Queue {
	QueueNode* _front;
	QueueNode* _back;
}Queue;

//��ʼ������
void QueueInit(Queue* q)
{
	q->_front = q->_back = NULL;
}
//��β������
void QueuePush(Queue* q, QueueDataType x)
{
	assert(q);
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NewNode == NULL) {
		printf("error ");
		return;
	}
	NewNode->data = x;
	NewNode->next = NULL;
	if (q->_back == NULL) {
		q->_back = q->_front = NewNode;
	}
	else {
		q->_back->next = NewNode;
		q->_back = NewNode;
	}
}
//��ͷ��
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->next == NULL) {
		free(q->_back);
		q->_back = q->_front = NULL;
	}
	else {
		QueueNode* next = q->_front->next;
		free(q->_front);
		q->_front = next;
	}
}
//��ȡ����ͷ��Ԫ��
QueueDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->data;
}
//��ȡ����β��Ԫ��
QueueDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->data;
}
//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur) {
		n++;
		cur = cur->next;
	}
	return n;
}
//�������Ƿ�Ϊ�� Ϊ�շ��ط��㣨1�� �ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 1 : 0;
}
//���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur) {
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->_back = q->_front = NULL;
}

void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d\n", QueueSize(&q));
	while (QueueEmpty(&q) == 0) {
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
}
