#include"BinaryTree.h"
#include"queue.h"
int BinaryTreeSize(BinaryTree* root)
{
	if (root == NULL) return 0;
	//分成根节点  左子树   右子树 
	else {
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}
}
//二叉树叶子个数
int BinaryTreeLeafSize(BinaryTree* root)
{
	if (root == NULL) return 0;
	if (!root->_left && !root->_right)
		return 1;
	else
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//二叉树第k层结点个数
int BinaryTreeLevelKSize(BinaryTree* root, int k)
{
	//if (k <= 0 && k >= BinaryTreeHeight(BinaryTree* root))return 0;
	if (root == NULL) return 0;
	if (k == 1) return 1;
	--k;
	return BinaryTreeLevelKSize(root->_left, k) + BinaryTreeLevelKSize(root->_right, k);
}
//重建二叉树
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
//前序遍历
void InOrder(BinaryTree* root)
{
	if (root == NULL) return;
	printf("%d ", root->data);
	InOrder(root->_left);
	InOrder(root->_right);

}
//销毁树
void DestroyBT(BinaryTree* root)
{
	if (root == NULL) return;
	DestroyBT(root->_left);
	DestroyBT(root->_right);
	free(root);
}
//找到值为x 的结点
BinaryTree* FindBT(BinaryTree* root, BTDataType x)
{
	if (root == NULL) 
		return NULL;
	if (root->data == x) return root;


	/*BinaryTree* left = FindBT(root->_left, x);
	BinaryTree* right = FindBT(root->_right, x);
	return left || right;*/
	//不能用 || 整形 bool 才能 ||
	//return FindBT(root->_left, x) || FindBT(root->_right, x);


	BinaryTree* rel = FindBT(root->_left, x);
	if (rel->data == x) {    //找左树
		return rel;
	}
	rel = FindBT(root->_right, x);
	if (rel->data == x) {   //找右树
		return rel;
	}
	return NULL;     //没有找到
}
//层序遍历
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
//判断是否为完全二叉树   是返回1 不是返回0
//层序遍历二叉树  空结点也接收
//遇到队列为NULL停止  如果队列中还有非NULL的结点 证明二叉树不连续
//so 二叉树不是完全二叉树
//如果队列中全是NULL  则是完全二叉树
int IsPerfectBTree(BinaryTree* root)
{
	//if (root == NULL) return 1;  这一行代码不需要 因为树为空时，照样可以满足下面的逻辑
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, root);
	while (!QueueEmpty(&q1)) {        //这一行的循环条件可以换成  while(1) 照样满足
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