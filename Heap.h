#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int HeapDataType;
typedef struct Heap {
	int _size;
	int _capacity;
	HeapDataType* _a;
}Heap;
void HeapSort(HeapDataType* a, int len);
void AdjustDown(HeapDataType* a, int n, int root);
void AdjustUp(HeapDataType* a, int child);
void HeapCreate(Heap* hp, HeapDataType* a, int n);
void HeapPush(Heap* hp, HeapDataType x);
void HeapPop(Heap* hp);
HeapDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapPrint(Heap* hp);
