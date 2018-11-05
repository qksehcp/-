#include <stdio.h>
#include <malloc.h>
#include <cstdbool>


typedef int element;

typedef struct tlistnode;

typedef struct tlistnode { // list의 node부분 선언
	element data; // data 변수의 자료형 (int)
	listnode *next; // 다음 node의 주소를 저장
}listnode;

typedef struct { // list의 header부분 선언
	int count; // node의 개수를 count
	listnode *head; // 첫번째 node의 주소를 저장
}list;

list *createlist() // list 생성 함수 정의
{
	list *pnewlist = (list*)malloc(sizeof(list)); // pnewlist에 구조체 list의 메모리 할당
	if (pnewlist == NULL) // 메모리 할당 성공 여부 확인
		return NULL;

	pnewlist->count = 0; // node가 없으므로 count = 0
	pnewlist->head = NULL; // node가 없으므로 head = NULL

	return pnewlist; // pnewlist 반환
}

void insertlist(list *plist, listnode *ppre, element data) // node삽입 함수 정의
{
	listnode *pnewnode = (listnode*)malloc(sizeof(listnode)); // pnewnode에 구조체 listnode의 메모리 할당
	pnewnode->data = data; // pnewnode에 데이터 삽입

	if (ppre ==NULL) // head와 list를 삽입할 위치 사이에 node가 존재하지 않을 때
	{
		pnewnode->next = plist->head; // pnewnode의 next 링크는 원래 head가 가리키던 node를 가리킴
		plist->head = pnewnode; // head는 pnewnode를 가리킴
		}
	else {
		pnewnode->next = ppre->next; // pnewnode의 next 링크는 원래 ppre가 가리키던 node를 가리킴
		ppre->next = pnewnode; // ppre의 next 링크는 pnewnode를 가리킴
	}
	plist->count++; // 노드의 개수 +1
}

bool searchlist(list *plist, listnode *ppre, listnode *ploc, element data) // 데이터 탐색 함수
{
	for (ppre = NULL, ploc = plist->head; ploc != NULL; ppre = ploc, ploc = ploc->next) // 첫번째 node부터 마지막 node까지 탐색
	{
		if (ploc->data == data) // 삽입하려는 데이터가 기존의 데이터와 일치
			return 1;
		else if (ploc->data > data) // 삽입하려는 데이터가 기존의 데이터와 불일치
			break;
	}

	return 0;
}

void addnodelist(list *plist, element data) // node 추가 함수(탐색 후 중복되는 데이터가 없을시 node 삽입)
{
	listnode *ppre = NULL, *ploc = NULL;
	bool found = searchlist(plist, ppre, ploc, data); // searchlist 함수를 사용하여 데이터 중복여부 확인

	if (!found) // 중복되는 데이터가 없을 시
		insertlist(plist, ppre, data); // node 삽입
}

void deletelist(list *plist, listnode *ppre, listnode *ploc) // node 삭제 함수
{
	if (ppre == NULL) // 삭제할 node와 head사이에 node가 없을 때
		plist->head = ploc->next; // head에 삭제될 node의 다음 node 대입
	else
		ppre->next = ploc->next; // ppre에 삭제될 node의 다음 node 대입

	free(ploc); // node에 메모리 해제
	plist->count--; // node의 개수 -1
}

void removelist(list *plist, element data) // node 제거 함수(탐색 후 data가 일치하는 node 제거)
{
	listnode *ppre = NULL, *ploc = NULL;
	bool found = searchlist(plist, ppre, ploc, data); // searchlist를 사용하여 삭제할 data를 갖는 node 탐색

	if (found) // 탐색이 성공할 시
		deletelist(plist, ppre, ploc); // deletelist함수를 사용하여 node 삭제
}

