#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int StackDataType;
typedef 
struct Stack {
	StackDataType* _a;
	int _top;
	int _capacity;
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//ѹջ
void StackPush(Stack* ps, StackDataType x)
{
	if (ps->_top == ps->_capacity) {
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		StackDataType* PS = (StackDataType*)realloc(ps->_a, sizeof(StackDataType) * newcapacity);
		if(PS == NULL){
			return;
	}
		ps->_a = PS;
	}	
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_top--;
}
//��ȡջ��Ԫ��
StackDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//���ջ���Ƿ�Ϊ�գ�Ϊ�շ��ط��㣨1���շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}
//����ջ
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_capacity = ps->_top = 0;
}
//void StackPrint(Stack* ps)
//{
//	for (int i = 0; i < ps->_top; i++)
//		printf("%d ", ps->_a[i]);
//}

void StackTest1()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st)) {
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
 }