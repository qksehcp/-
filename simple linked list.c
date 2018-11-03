#include <stdio.h>
#include <malloc.h>

typedef struct node NODE;
typedef struct node {
	void* dataPtr; // ������ �������ڷ����� ��� �����ϱ� ���� void pointer ����
	struct NODE* link; // ����� ���� ����� ��ũ �ּҸ� ����
}NODE;

NODE* createNode(void* itemPtr){ // ��� ���� �Լ�
	NODE* nodePtr = NULL; // ��� �ʱ�ȭ
	nodePtr = (NODE*)malloc(sizeof(NODE)); // ����ü ���� nodePtr ����, ����ü NODE ��ŭ�� �޸� �Ҵ�
	nodePtr->dataPtr = itemPtr; // ������� ��� nodePtr�� itemPtr ������ ����
	nodePtr->link = NULL; // ��� nodePtr�� ���� ����� �ּ�(����� ����� ��尡 �����Ƿ� NULL)����
	return nodePtr; // nodePtr ����
}

int main() {
	
	NODE* node1 = NULL; // ������ ������ ���� ���1 ����
	NODE* node2 = NULL; // ������ ������ ���� ���2 ����
	NODE* print = NULL; // ������ ����� ���� ���print ����

	int data1 = 7; // ���1�� ����� ������
	int data2 = 8; // ���2�� ����� ������

	node1 = createNode(&data1); // ���1�� ������ 7 ����
	node2 = createNode(&data2); // ���2�� ������ 8 ����
	node1->link = node2; // ���1�� ��ũ�� ���2�� ����Ŵ

	print = (NODE*)malloc(sizeof(NODE)); // ���print�� �޸� �Ҵ�
	print = node1; // ���print�� ���1 �ּ� ����

	while (print != NULL) { // print��尡 NULL�� �ƴҶ�����
		printf("%d\n", *(int*)print->dataPtr); // print����� ������ ���
		print = print->link; // print��忡�� print����� ��ũ�� ����Ű�� ���� ����� �ּ� ����
	}
	return 0;
}