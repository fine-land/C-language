#include"Heap.h"

void Swap(int* a, int* b)
{
	int x = *a;
	    *a = *b;
	    *b = x;
}
//向下调整
void AdjustDown(HeapDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		//寻找小的孩纸
		if (child + 1 < n && a[child] > a[child + 1]) {
			++child;
		}
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}	
	}
}
void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0) {
		
		if (a[parent] > a[child]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
//堆排序  降序建小堆
void HeapSort(HeapDataType* a, int len)
{

	//建堆
	for (int i = (len - 2) / 2; i >= 0; --i) {
		AdjustDown(a, len, i);
	}
	int end = len - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	for (int j = 0; j < len; j++) {
		printf("%d ", a[j]);
	}
}
//建堆
void HeapCreate(Heap* hp, HeapDataType* a, int n)
{
	hp->_capacity = hp->_size = n;
	hp->_a = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	if (hp->_a == NULL) {
		return;
	}
	memcpy(hp->_a, a, sizeof(HeapDataType) * n);
	 //建小堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(hp->_a, hp->_size, i);
	}
}
//入堆
void HeapPush(Heap* hp, HeapDataType x)
{
	if (hp->_capacity == hp->_size) {
		int newcapacity = hp->_capacity * 2;
		HeapDataType* HP = (HeapDataType*)realloc(hp->_a, sizeof(HeapDataType) * newcapacity);
		if (HP == NULL) return;
		hp->_a = HP;
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	++hp->_size;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0);
}
HeapDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\nThe capacity of heap is :%d", hp->_capacity);
	printf("\nThe size of heap is :%d ", hp->_size);

}

