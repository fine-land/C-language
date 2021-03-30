#include"BinaryTree.h"
#include"queue.h"
int BinaryTreeSize(BinaryTree* root)
{
	if (root == NULL) return 0;
	//�ֳɸ��ڵ�  ������   ������ 
	else {
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}
}
//������Ҷ�Ӹ���
int BinaryTreeLeafSize(BinaryTree* root)
{
	if (root == NULL) return 0;
	if (!root->_left && !root->_right)
		return 1;
	else
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//��������k�������
int BinaryTreeLevelKSize(BinaryTree* root, int k)
{
	//if (k <= 0 && k >= BinaryTreeHeight(BinaryTree* root))return 0;
	if (root == NULL) return 0;
	if (k == 1) return 1;
	--k;
	return BinaryTreeLevelKSize(root->_left, k) + BinaryTreeLevelKSize(root->_right, k);
}
//�ؽ�������
BinaryTree* BinaryTreeCreat(int* a, int* i)
{
	if (a[*i] == '#') return NULL;
	BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (root == NULL) return NULL;
	root->data = a[*i];
	(*i)++;
	root->_left = BinaryTreeCreat(a, i);
	(*i)++;
	root->_right = BinaryTreeCreat(a, i);
	return root;
}
//ǰ�����
void InOrder(BinaryTree* root)
{
	if (root == NULL) return;
	printf("%d ", root->data);
	InOrder(root->_left);
	InOrder(root->_right);

}
//������
void DestroyBT(BinaryTree* root)
{
	if (root == NULL) return;
	DestroyBT(root->_left);
	DestroyBT(root->_right);
	free(root);
}
//�ҵ�ֵΪx �Ľ��
BinaryTree* FindBT(BinaryTree* root, BTDataType x)
{
	if (root == NULL) 
		return NULL;
	if (root->data == x) return root;


	/*BinaryTree* left = FindBT(root->_left, x);
	BinaryTree* right = FindBT(root->_right, x);
	return left || right;*/
	//������ || ���� bool ���� ||
	//return FindBT(root->_left, x) || FindBT(root->_right, x);


	BinaryTree* rel = FindBT(root->_left, x);
	if (rel->data == x) {    //������
		return rel;
	}
	rel = FindBT(root->_right, x);
	if (rel->data == x) {   //������
		return rel;
	}
	return NULL;     //û���ҵ�
}
//�������
void LevelOrder(BinaryTree* root)
{
	if (root == NULL) return;
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, root);
	while (!QueueEmpty(&q1)) {
		BinaryTree* front = QueueTop(&q1);
		printf("%d ", front->data);
		QueuePop(&q1);

		if (front->_left != NULL) {
			QueuePush(&q1, front->_left);
		}
		if (front->_right != NULL) {
			QueuePush(&q1, front->_right);
		}
	}
	QueueDestroy(&q1);
}    
//�ж��Ƿ�Ϊ��ȫ������   �Ƿ���1 ���Ƿ���0
//�������������  �ս��Ҳ����
//��������ΪNULLֹͣ  ��������л��з�NULL�Ľ�� ֤��������������
//so ������������ȫ������
//���������ȫ��NULL  ������ȫ������
int IsPerfectBTree(BinaryTree* root)
{
	//if (root == NULL) return 1;  ��һ�д��벻��Ҫ ��Ϊ��Ϊ��ʱ��������������������߼�
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, root);
	while (!QueueEmpty(&q1)) {        //��һ�е�ѭ���������Ի���  while(1) ��������
		BinaryTree* front = QueueTop(&q1);
		if (front == NULL) {
			break;
			QueuePop(&q1);
			QueuePush(&q1, root->_left);
			QueuePush(&q1, root->_right);

		}
	}
	QueuePop(&q1);
	while (!QueueEmpty(&q1)) {
		BinaryTree* front = QueueTop(&q1);
		if (front != NULL) {
			return 0;
		}
		QueuePop(&q1);
	}
	QueueDestroy(&q1);
	return 1;
}