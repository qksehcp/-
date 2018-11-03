#include <Stdio.h>
#include <malloc.h>

typedef struct tstacknode { // 이진법을 구현할 stack의 node 정의
	int data; // 0 또는 1이 저장될 데이터
	struct tstacknode* next; // 다음 노드를 가르키는 link
}stacknode;

typedef struct { // stack의 top노드를 가리키는 header 정의
	int count; // 노드의 개수를 count
	stacknode* top; // top 노드를 가르키는 link 
}stack;

stack* createstack(int size) // stack 생성 함수
{
	stack* pstack = (stack*)malloc(sizeof(stack)); // pstack에 구조체 stack의 메모리 할당
	if (pstack == NULL) // 메모리 할당 성공여부 확인
		return NULL;
	pstack->count = 0; // 현재 노드 개수가 없으므로 count = 0
	pstack->top = (stack*)malloc(sizeof(stack)); // stack의 top 노드를 가리키는 pstack->top에 구조체 stack의 메모리 할당
	if (pstack->top == NULL) // 메모리 할당 성공여부 확인
		return NULL;
	pstack->top = NULL; // 현재 top 노드가 없으므로 NULL

	return pstack; // pstack 생성
}

void push(stack* pstack, int item) // stack에 데이터 입력하는 함수
{
	stacknode *pnewnode = (stacknode*)malloc(sizeof(stacknode)); // 새 데이터(노드) pnewnode에 노드(구조체 stacknode)의 메모리 할당
	if (pnewnode == NULL) // 메모리 할당 성공여부 확인
		return;

	pnewnode->data = item; // stack에 새로 저장될 데이터 입력
	pnewnode->next = pstack->top; // 새로 생성되는 노드의 link가 원래 존재하던 top이 가르키던 노드를 가르킴 
	pstack->top = pnewnode; // header의 top이 새로 생성된 노드를 가르킴
	pstack->count++; // header의 count에 노드개수 추가
}

int pop(stack *pstack) // stack의 데이터를 삭제하는 함수
{
	if (pstack->top == NULL) // 노드의 존재여부 확인
		return 0;
	else
	{
		int item = pstack->top->data; // item에 top포인터가 가르키는 노드의 데이터 저장
		stacknode* poldtop = pstack->top; // 노드의 주소를 저장할 임시노드에 top포인터가 가르키는 노드 저장
		pstack->top = poldtop->next; // 노드의 top포인터에 삭제될 노드가 가르키는 노드 저장
		free(poldtop); // 원래 top위치에 존재하던 노드 메모리 해제(삭제)
		pstack->count--; // header의 노드개수 감소
		return item; // 삭제된 노드의 데이터 반환
	}
}

void main()
{
	int n;
	scanf_s("%d", &n); // 이진법으로 나타낼 정수 입력
	stack* pstack = createstack(100); // 이진법으로 표현할 stack 생성
	while (n / 2 >= 1 ) // 정수 n을 이진법으로 나타내기 위하여 더이상 나누어지지 않을 때까지 2로 나누기
	{
		push(pstack, n % 2); // n을 2로 나눈 나머지를 stack에 저장
		n /= 2; // n = n / 2 대입

	}
	push(pstack, 1); 

	while (!pstack->top == NULL) // 노드가 존재할때까지 실행(header의 top이 NULL이 아닐때까지)
	{
		printf("%d", pop(pstack)); // stack에 저장된 노드의 데이터를 출력
	}
	
}
