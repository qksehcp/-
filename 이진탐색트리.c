#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int compareint(void *argu1, void* argu2) // 노드의 대소 비교 함수 선언
{
	return *(int*)argu1 - *(int*)argu2;
}

typedef struct node // 이진탐색트리 구조체 노드선언
{
	void* dataptr;
	struct node* left;
	struct node* right;
}node;

typedef struct { // 이진탐색트리 root 선언
	int count;
	int(*compare)(void* argu1, void* argu2);
	node* root;
}bst_tree;

bst_tree* bst_create(int (*compare)(void* argu1, void* argu2)) // 이진탐색트리 생성
{
	bst_tree* tree = NULL; // 이진탐색트리의 root 초기화

	tree = (bst_tree*)malloc(sizeof(bst_tree)); // root에 구조체 bst_tree의 메모리 할당
	if (tree) { // 메모리 할당 성공 여부 확인
		tree->root = NULL;
		tree->count = 0;
		tree->compare = compare;
	} // root의 데이터 초기화
	return tree; // tree 반환
}

node* _insert(bst_tree* tree, node* root, node* newptr) // 이진탐색트리의 node 삽입 함수
{
	if (!root) // root가 존재하지 않는 경우
		return newptr; // 삽입하는 데이터가 root가 됨

	if (tree->compare(newptr->dataptr, root->dataptr) < 0) //삽입하는 데이터가 root보다 작은 경우 
	{
		root->left = _insert(tree, root->left, newptr); // root의 왼쪽에 삽입
	}
	else { // 삽입하는 데이터가 root보다 큰 경우
		root->right = _insert(tree, root->right, newptr); // root의 오른쪽에 삽입

	}
	return root; // root 반환
}

bool bst_insert(bst_tree *tree, void* dataptr) // 이진탐색트리에 데이터 삽입을 위한 탐색
{
	node* newptr = NULL;

	newptr = (node*)malloc(sizeof(node));
	if (!newptr) // 메모리 할당 성공 여부 확인
		return false;
	newptr->right = NULL;
	newptr->left = NULL;
	newptr->dataptr = dataptr;

	if (tree->count == 0) // 노드가 존재하지 않는 경우
		tree->root = newptr; // 삽입하는 노드가 root가 됨
	else // root가 존재하는 경우
		_insert(tree, tree->root, newptr); // tree의 root에 노드 삽입 
	(tree->count)++; // tree의 노드개수 증가
	return true;

}

void* _retrieve(bst_tree* tree, void* dataptr, node* root) // 데이터 검색 함수
{
	if (root) { // root가 존재하는 경우
		if (tree->compare(dataptr, root->dataptr) < 0) // 찾으려는 데이터가 root보다 작은경우
			return _retrieve(tree, dataptr, root->left); // root의 왼쪽 노드를 검색
		else if (tree->compare(dataptr, root->dataptr) > 0) // 찾으려는 데이터가 root보다 큰 경우
			return _retrieve(tree, dataptr, root->right); // root의 오른쪽 노드를 검색
		else
			return root->dataptr; // root와 일치하는 경우

	}
	else
		return NULL;
}

void* bst_retrieve(bst_tree* tree, void* keyptr) // 데이터 검색함수 정의
{
	if (tree->root) // root가 존재하는 경우
		return _retrieve(tree, keyptr, tree->root); // 데이터 크기를 비교하여 검색
	else
		return NULL;
}