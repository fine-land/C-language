#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinaryTree {
	BTDataType data;
	struct BinaryTree* _left;
	struct BinaryTree* _right;
}BinaryTree;

//求二叉树结点个数
BinaryTree* BinaryTreeCreat(int* a, int* i);
int BinaryTreeSize(BinaryTree* root); 
int BinaryTreeLeafSize(BinaryTree* root);
int BinaryTreeLevelKSize(BinaryTree* root, int k);
void InOrder(BinaryTree* root);
void DestroyBT(BinaryTree* root);
BinaryTree* FindBT(BinaryTree* root, BTDataType x);
//void PrevOrder(BinaryTree* root);
//void NextOrder(BinaryTree* root);
void LevelOrder(BinaryTree* root);
void IsPerfectBTree(BinaryTree* root);