#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int compareint(void *argu1, void* argu2) // ����� ��� �� �Լ� ����
{
	return *(int*)argu1 - *(int*)argu2;
}

typedef struct node // ����Ž��Ʈ�� ����ü ��弱��
{
	void* dataptr;
	struct node* left;
	struct node* right;
}node;

typedef struct { // ����Ž��Ʈ�� root ����
	int count;
	int(*compare)(void* argu1, void* argu2);
	node* root;
}bst_tree;

bst_tree* bst_create(int (*compare)(void* argu1, void* argu2)) // ����Ž��Ʈ�� ����
{
	bst_tree* tree = NULL; // ����Ž��Ʈ���� root �ʱ�ȭ

	tree = (bst_tree*)malloc(sizeof(bst_tree)); // root�� ����ü bst_tree�� �޸� �Ҵ�
	if (tree) { // �޸� �Ҵ� ���� ���� Ȯ��
		tree->root = NULL;
		tree->count = 0;
		tree->compare = compare;
	} // root�� ������ �ʱ�ȭ
	return tree; // tree ��ȯ
}

node* _insert(bst_tree* tree, node* root, node* newptr) // ����Ž��Ʈ���� node ���� �Լ�
{
	if (!root) // root�� �������� �ʴ� ���
		return newptr; // �����ϴ� �����Ͱ� root�� ��

	if (tree->compare(newptr->dataptr, root->dataptr) < 0) //�����ϴ� �����Ͱ� root���� ���� ��� 
	{
		root->left = _insert(tree, root->left, newptr); // root�� ���ʿ� ����
	}
	else { // �����ϴ� �����Ͱ� root���� ū ���
		root->right = _insert(tree, root->right, newptr); // root�� �����ʿ� ����

	}
	return root; // root ��ȯ
}

bool bst_insert(bst_tree *tree, void* dataptr) // ����Ž��Ʈ���� ������ ������ ���� Ž��
{
	node* newptr = NULL;

	newptr = (node*)malloc(sizeof(node));
	if (!newptr) // �޸� �Ҵ� ���� ���� Ȯ��
		return false;
	newptr->right = NULL;
	newptr->left = NULL;
	newptr->dataptr = dataptr;

	if (tree->count == 0) // ��尡 �������� �ʴ� ���
		tree->root = newptr; // �����ϴ� ��尡 root�� ��
	else // root�� �����ϴ� ���
		_insert(tree, tree->root, newptr); // tree�� root�� ��� ���� 
	(tree->count)++; // tree�� ��尳�� ����
	return true;

}

void* _retrieve(bst_tree* tree, void* dataptr, node* root) // ������ �˻� �Լ�
{
	if (root) { // root�� �����ϴ� ���
		if (tree->compare(dataptr, root->dataptr) < 0) // ã������ �����Ͱ� root���� �������
			return _retrieve(tree, dataptr, root->left); // root�� ���� ��带 �˻�
		else if (tree->compare(dataptr, root->dataptr) > 0) // ã������ �����Ͱ� root���� ū ���
			return _retrieve(tree, dataptr, root->right); // root�� ������ ��带 �˻�
		else
			return root->dataptr; // root�� ��ġ�ϴ� ���

	}
	else
		return NULL;
}

void* bst_retrieve(bst_tree* tree, void* keyptr) // ������ �˻��Լ� ����
{
	if (tree->root) // root�� �����ϴ� ���
		return _retrieve(tree, keyptr, tree->root); // ������ ũ�⸦ ���Ͽ� �˻�
	else
		return NULL;
}