#include<stdio.h>
int RemoveDuplicates(int* phead)
{
	int count = 1;
	int* next = phead;
	int* cur = phead;
	for (int num = 0; num < 2; num++)
	{
		next++;
		if (*next != *cur)
		{
			*++cur = *next;
			count++;
		}
	}
	return count;
}
int main()
{
	int num[] = { 1,1,2 };
	int len = RemoveDuplicates(num);
	for (int i = 0; i < len; i++)
		printf("%d ", num[i]);
	return 0;
}