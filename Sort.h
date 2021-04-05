#pragma once
#include<stdio.h>
#include<string.h>
#include"stack.h"
//打印数组
void SortPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//交换函数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//插入排序  时间复杂度 O(N^2) 稳定  
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
}
//希尔排序    时间复杂度 O(N^1.3)左右   不稳定
void ShellSort(int* a, int n)
{
	//gap  > 1 时是预排序 ，使数组接近有序 
	//  使大数快速到数组尾，小数快速到数组头  
	//gap == 1 时就是插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;     //为了保证最后一次gap 为1
		for (int i = 0; i < n - gap; i++)   //gap组数交叉排序
		{         
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//选择排序    时间复杂度O(N^2) 
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;       //在区间[begin , end]中找到最大值
	while (begin <= end)             //和最小值的下标
	{
		int maxi = begin, mini = end;
		for (int i = begin; i <= end; i++)   //i<=end  要有等于号 因为是
		{                                      //闭区间
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)      //如果begin == maxi 		                  
			maxi = mini;          // 需要调整一下 不然maxi就被换走了
		Swap(&a[end], &a[maxi]);
		--end;
		++begin;                
	}
}
//堆排序     时间复杂度O(N*logN)  
void AdjustDown(int* a,int root,int size)
{
	//建大堆
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
		{
			child++;    //找到孩子中大的那个
		}
		if (a[child] > a[parent])   //如果父亲小于孩子，交换
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;     //不然，调整结束
		}
	}
}
void HeapSort(int* a, int n)
{
	//建da堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, i, n);   
		
	}
	
	int size = n-1;
	while (size > 0)
	{
		Swap(&a[0], &a[size]);  //把最大的数交换到最后
		
		AdjustDown(a, 0, size);  //调整成大堆
		--size;
	}
}
//冒泡排序   时间复杂度O(N^2)  稳定
void BubbleSort(int* a, int n)
{
	int flag = 0;
	int end = n - 1;
	for (end = n - 1; end > 0; --end)   //冒泡n-1趟
	{
		for (int i = 0; i < end; ++i) //每趟从[0 end]中选出max沉到最后
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;  //如果flag == 0，证明没有交换
		}           //数组已经有序，直接停止。
	}
}
//挖坑法
int PitHoleSort(int* a, int begin, int end)
{
	//将key的位置作为坑 ，然后前指针找大于key的填上
//此时begin的位置又成为新坑，end找小于key的填上
//最后将key填到begin == end 的坑上
	int key = a[end];
	//int keyindex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}
//Hoare法
int PartSort(int* a, int begin, int end)
{
	//前指针 先 找大于key的值，后指针 后 找小于key的值，
//然后交换两个值 
//最后交换下标为 keyindex 和begin == end 的数组值
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
//双指针法
int PrevCurSort(int* a, int begin, int end)
{
	//cur找小于key的，每当cur找到一个小于key的值，prev++，
//然后交换下标为prev和cur的值
//不然cur继续++，最后prev++ 和 end交换
	int key = a[end];
	int prev = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&a[prev], &a[end]);
	return prev;
}
//快排  时间复杂度O(N*logN)  
void QuickSort(int* a, int begin, int end)
{
	//快排的一趟遍历，是为了固定1个数。
	//PartSort一次 将区间分成
	//[begin keyindex-1]   keyindex   [keyindex+1 end]
	if (begin >= end)
	{
		return;
	}
	int keyindex = PrevCurSort(a, begin, end);
		QuickSort(a, begin, keyindex - 1);
		QuickSort(a, keyindex + 1, end);
	
}
//快排 非递归
void QuickSortNoR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyindex = PartSort(a, left, right);
		//[left keyindex-1] [keyindex+1 right]
		if (left < keyindex - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}
		if (keyindex + 1 < right)
		{
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}

	}
	StackDestroy(&st);
}
//归并排序子函数
void _MergeSort(int* a, int begin, int end, int* tmp)
{ //类似二叉树的后序遍历
	//将数组分成[begin mid] [mid+1 end] 
	//先把左区间归并成有序，再右区间
	//然后归并成一个
	if (begin >= end) return;
	int index = begin;
	int mid = (begin + end) >> 1;
	//[begin mid] [mid+1 end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	_MergeSort(a, begin1, end1, tmp);
	_MergeSort(a, begin2, end2, tmp);
	//归并，直道一个数组先结束
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	} 
	//然后补充另外一个
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
	tmp[index++] = a[begin2++];
 }
	//将相对位置的数拷进去
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) return;
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);

}
//计数排序
void CountSort(int* a, int n)
{
	//找到最大和最小
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* countArr = (int*)malloc(range * sizeof(int));
	if (countArr == NULL) return;
	memset(countArr, 0, sizeof(int) * range);
	//统计次数
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}
	//排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i])
		{
			a[j++] = i + min;
			countArr[i]--;
		}
	}
	free(countArr);
}