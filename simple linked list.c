#include <stdio.h>
#include <malloc.h>

typedef struct node NODE;
typedef struct node {
	void* dataPtr; // 임의의 데이터자료형을 모두 포함하기 위한 void pointer 선언
	struct NODE* link; // 연결된 다음 노드의 링크 주소를 저장
}NODE;

NODE* createNode(void* itemPtr){ // 노드 생성 함수
	NODE* nodePtr = NULL; // 노드 초기화
	nodePtr = (NODE*)malloc(sizeof(NODE)); // 구조체 변수 nodePtr 선언, 구조체 NODE 만큼의 메모리 할당
	nodePtr->dataPtr = itemPtr; // 만들어진 노드 nodePtr에 itemPtr 데이터 저장
	nodePtr->link = NULL; // 노드 nodePtr에 다음 노드의 주소(현재는 연결된 노드가 없으므로 NULL)저장
	return nodePtr; // nodePtr 생성
}

int main() {
	
	NODE* node1 = NULL; // 데이터 저장을 위한 노드1 생성
	NODE* node2 = NULL; // 데이터 저장을 위한 노드2 생성
	NODE* print = NULL; // 데이터 출력을 위한 노드print 생성

	int data1 = 7; // 노드1에 저장될 데이터
	int data2 = 8; // 노드2에 저장될 데이터

	node1 = createNode(&data1); // 노드1에 데이터 7 저장
	node2 = createNode(&data2); // 노드2에 데이터 8 저장
	node1->link = node2; // 노드1의 링크가 노드2를 가르킴

	print = (NODE*)malloc(sizeof(NODE)); // 노드print에 메모리 할당
	print = node1; // 노드print에 노드1 주소 대입

	while (print != NULL) { // print노드가 NULL이 아닐때까지
		printf("%d\n", *(int*)print->dataPtr); // print노드의 데이터 출력
		print = print->link; // print노드에는 print노드의 링크가 가르키는 다음 노드의 주소 대입
	}
	return 0;
}