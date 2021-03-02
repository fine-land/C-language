/*功能：编写函数　float  fun(float* a, int  n)，用来计算n门课程的平
		均分，结果作为函数值返回。其中数组a中保存了n门课程的分数。*/
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
//	float score[20] = { 0 };  //需要动态开辟
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


