#include <stdio.h>
#include <malloc.h>
#include <cstdbool>


typedef int element;

typedef struct tlistnode;

typedef struct tlistnode { // list�� node�κ� ����
	element data; // data ������ �ڷ��� (int)
	listnode *next; // ���� node�� �ּҸ� ����
}listnode;

typedef struct { // list�� header�κ� ����
	int count; // node�� ������ count
	listnode *head; // ù��° node�� �ּҸ� ����
}list;

list *createlist() // list ���� �Լ� ����
{
	list *pnewlist = (list*)malloc(sizeof(list)); // pnewlist�� ����ü list�� �޸� �Ҵ�
	if (pnewlist == NULL) // �޸� �Ҵ� ���� ���� Ȯ��
		return NULL;

	pnewlist->count = 0; // node�� �����Ƿ� count = 0
	pnewlist->head = NULL; // node�� �����Ƿ� head = NULL

	return pnewlist; // pnewlist ��ȯ
}

void insertlist(list *plist, listnode *ppre, element data) // node���� �Լ� ����
{
	listnode *pnewnode = (listnode*)malloc(sizeof(listnode)); // pnewnode�� ����ü listnode�� �޸� �Ҵ�
	pnewnode->data = data; // pnewnode�� ������ ����

	if (ppre ==NULL) // head�� list�� ������ ��ġ ���̿� node�� �������� ���� ��
	{
		pnewnode->next = plist->head; // pnewnode�� next ��ũ�� ���� head�� ����Ű�� node�� ����Ŵ
		plist->head = pnewnode; // head�� pnewnode�� ����Ŵ
		}
	else {
		pnewnode->next = ppre->next; // pnewnode�� next ��ũ�� ���� ppre�� ����Ű�� node�� ����Ŵ
		ppre->next = pnewnode; // ppre�� next ��ũ�� pnewnode�� ����Ŵ
	}
	plist->count++; // ����� ���� +1
}

bool searchlist(list *plist, listnode *ppre, listnode *ploc, element data) // ������ Ž�� �Լ�
{
	for (ppre = NULL, ploc = plist->head; ploc != NULL; ppre = ploc, ploc = ploc->next) // ù��° node���� ������ node���� Ž��
	{
		if (ploc->data == data) // �����Ϸ��� �����Ͱ� ������ �����Ϳ� ��ġ
			return 1;
		else if (ploc->data > data) // �����Ϸ��� �����Ͱ� ������ �����Ϳ� ����ġ
			break;
	}

	return 0;
}

void addnodelist(list *plist, element data) // node �߰� �Լ�(Ž�� �� �ߺ��Ǵ� �����Ͱ� ������ node ����)
{
	listnode *ppre = NULL, *ploc = NULL;
	bool found = searchlist(plist, ppre, ploc, data); // searchlist �Լ��� ����Ͽ� ������ �ߺ����� Ȯ��

	if (!found) // �ߺ��Ǵ� �����Ͱ� ���� ��
		insertlist(plist, ppre, data); // node ����
}

void deletelist(list *plist, listnode *ppre, listnode *ploc) // node ���� �Լ�
{
	if (ppre == NULL) // ������ node�� head���̿� node�� ���� ��
		plist->head = ploc->next; // head�� ������ node�� ���� node ����
	else
		ppre->next = ploc->next; // ppre�� ������ node�� ���� node ����

	free(ploc); // node�� �޸� ����
	plist->count--; // node�� ���� -1
}

void removelist(list *plist, element data) // node ���� �Լ�(Ž�� �� data�� ��ġ�ϴ� node ����)
{
	listnode *ppre = NULL, *ploc = NULL;
	bool found = searchlist(plist, ppre, ploc, data); // searchlist�� ����Ͽ� ������ data�� ���� node Ž��

	if (found) // Ž���� ������ ��
		deletelist(plist, ppre, ploc); // deletelist�Լ��� ����Ͽ� node ����
}

