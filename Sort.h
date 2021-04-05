#pragma once
#include<stdio.h>
#include<string.h>
#include"stack.h"
//��ӡ����
void SortPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������  ʱ�临�Ӷ� O(N^2) �ȶ�  
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
//ϣ������    ʱ�临�Ӷ� O(N^1.3)����   ���ȶ�
void ShellSort(int* a, int n)
{
	//gap  > 1 ʱ��Ԥ���� ��ʹ����ӽ����� 
	//  ʹ�������ٵ�����β��С�����ٵ�����ͷ  
	//gap == 1 ʱ���ǲ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;     //Ϊ�˱�֤���һ��gap Ϊ1
		for (int i = 0; i < n - gap; i++)   //gap������������
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
//ѡ������    ʱ�临�Ӷ�O(N^2) 
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;       //������[begin , end]���ҵ����ֵ
	while (begin <= end)             //����Сֵ���±�
	{
		int maxi = begin, mini = end;
		for (int i = begin; i <= end; i++)   //i<=end  Ҫ�е��ں� ��Ϊ��
		{                                      //������
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
		if (begin == maxi)      //���begin == maxi 		                  
			maxi = mini;          // ��Ҫ����һ�� ��Ȼmaxi�ͱ�������
		Swap(&a[end], &a[maxi]);
		--end;
		++begin;                
	}
}
//������     ʱ�临�Ӷ�O(N*logN)  
void AdjustDown(int* a,int root,int size)
{
	//�����
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
		{
			child++;    //�ҵ������д���Ǹ�
		}
		if (a[child] > a[parent])   //�������С�ں��ӣ�����
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;     //��Ȼ����������
		}
	}
}
void HeapSort(int* a, int n)
{
	//��da��
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, i, n);   
		
	}
	
	int size = n-1;
	while (size > 0)
	{
		Swap(&a[0], &a[size]);  //�����������������
		
		AdjustDown(a, 0, size);  //�����ɴ��
		--size;
	}
}
//ð������   ʱ�临�Ӷ�O(N^2)  �ȶ�
void BubbleSort(int* a, int n)
{
	int flag = 0;
	int end = n - 1;
	for (end = n - 1; end > 0; --end)   //ð��n-1��
	{
		for (int i = 0; i < end; ++i) //ÿ�˴�[0 end]��ѡ��max�������
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;  //���flag == 0��֤��û�н���
		}           //�����Ѿ�����ֱ��ֹͣ��
	}
}
//�ڿӷ�
int PitHoleSort(int* a, int begin, int end)
{
	//��key��λ����Ϊ�� ��Ȼ��ǰָ���Ҵ���key������
//��ʱbegin��λ���ֳ�Ϊ�¿ӣ�end��С��key������
//���key�begin == end �Ŀ���
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
//Hoare��
int PartSort(int* a, int begin, int end)
{
	//ǰָ�� �� �Ҵ���key��ֵ����ָ�� �� ��С��key��ֵ��
//Ȼ�󽻻�����ֵ 
//��󽻻��±�Ϊ keyindex ��begin == end ������ֵ
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
//˫ָ�뷨
int PrevCurSort(int* a, int begin, int end)
{
	//cur��С��key�ģ�ÿ��cur�ҵ�һ��С��key��ֵ��prev++��
//Ȼ�󽻻��±�Ϊprev��cur��ֵ
//��Ȼcur����++�����prev++ �� end����
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
//����  ʱ�临�Ӷ�O(N*logN)  
void QuickSort(int* a, int begin, int end)
{
	//���ŵ�һ�˱�������Ϊ�˹̶�1������
	//PartSortһ�� ������ֳ�
	//[begin keyindex-1]   keyindex   [keyindex+1 end]
	if (begin >= end)
	{
		return;
	}
	int keyindex = PrevCurSort(a, begin, end);
		QuickSort(a, begin, keyindex - 1);
		QuickSort(a, keyindex + 1, end);
	
}
//���� �ǵݹ�
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
//�鲢�����Ӻ���
void _MergeSort(int* a, int begin, int end, int* tmp)
{ //���ƶ������ĺ������
	//������ֳ�[begin mid] [mid+1 end] 
	//�Ȱ�������鲢��������������
	//Ȼ��鲢��һ��
	if (begin >= end) return;
	int index = begin;
	int mid = (begin + end) >> 1;
	//[begin mid] [mid+1 end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	_MergeSort(a, begin1, end1, tmp);
	_MergeSort(a, begin2, end2, tmp);
	//�鲢��ֱ��һ�������Ƚ���
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
	//Ȼ�󲹳�����һ��
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
	tmp[index++] = a[begin2++];
 }
	//�����λ�õ�������ȥ
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
//�鲢����
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) return;
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);

}
//��������
void CountSort(int* a, int n)
{
	//�ҵ�������С
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
	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}
	//����
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