/*���ܣ���д������float  fun(float* a, int  n)����������n�ſγ̵�ƽ
		���֣������Ϊ����ֵ���ء���������a�б�����n�ſγ̵ķ�����*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
float fun(float* a, int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + *(a + i);
	}
	return sum / n;
}
//int main(void)
//{
//	int n;
//	printf("Please input the num :");
//	scanf("%d", &n);
//	//getchar();
//	printf("Please input the score :");
//	float score[20] = { 0 };  //��Ҫ��̬����
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%f", &score[i]);
//	}
//	printf("The average is : %f\n", fun(score, n));
//	return 0;
//}
int main(void)
{
	int n;
	printf("Please input the num :");
	scanf("%d", &n);
	float* score = (float*)malloc(n * sizeof(float));
	if (score == NULL)
	{
		printf("error .");
		return 0;
	}
	printf("Please input the score :");
	for (int i = 0; i < n; i++)
	{
		scanf("%f", score + i);
	}
	printf("The average is : %f\n", fun(score, n));
	free(score);
	score = NULL;
	return 0;
}


