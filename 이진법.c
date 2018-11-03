#include <Stdio.h>
#include <malloc.h>

typedef struct tstacknode { // �������� ������ stack�� node ����
	int data; // 0 �Ǵ� 1�� ����� ������
	struct tstacknode* next; // ���� ��带 ����Ű�� link
}stacknode;

typedef struct { // stack�� top��带 ����Ű�� header ����
	int count; // ����� ������ count
	stacknode* top; // top ��带 ����Ű�� link 
}stack;

stack* createstack(int size) // stack ���� �Լ�
{
	stack* pstack = (stack*)malloc(sizeof(stack)); // pstack�� ����ü stack�� �޸� �Ҵ�
	if (pstack == NULL) // �޸� �Ҵ� �������� Ȯ��
		return NULL;
	pstack->count = 0; // ���� ��� ������ �����Ƿ� count = 0
	pstack->top = (stack*)malloc(sizeof(stack)); // stack�� top ��带 ����Ű�� pstack->top�� ����ü stack�� �޸� �Ҵ�
	if (pstack->top == NULL) // �޸� �Ҵ� �������� Ȯ��
		return NULL;
	pstack->top = NULL; // ���� top ��尡 �����Ƿ� NULL

	return pstack; // pstack ����
}

void push(stack* pstack, int item) // stack�� ������ �Է��ϴ� �Լ�
{
	stacknode *pnewnode = (stacknode*)malloc(sizeof(stacknode)); // �� ������(���) pnewnode�� ���(����ü stacknode)�� �޸� �Ҵ�
	if (pnewnode == NULL) // �޸� �Ҵ� �������� Ȯ��
		return;

	pnewnode->data = item; // stack�� ���� ����� ������ �Է�
	pnewnode->next = pstack->top; // ���� �����Ǵ� ����� link�� ���� �����ϴ� top�� ����Ű�� ��带 ����Ŵ 
	pstack->top = pnewnode; // header�� top�� ���� ������ ��带 ����Ŵ
	pstack->count++; // header�� count�� ��尳�� �߰�
}

int pop(stack *pstack) // stack�� �����͸� �����ϴ� �Լ�
{
	if (pstack->top == NULL) // ����� ���翩�� Ȯ��
		return 0;
	else
	{
		int item = pstack->top->data; // item�� top�����Ͱ� ����Ű�� ����� ������ ����
		stacknode* poldtop = pstack->top; // ����� �ּҸ� ������ �ӽó�忡 top�����Ͱ� ����Ű�� ��� ����
		pstack->top = poldtop->next; // ����� top�����Ϳ� ������ ��尡 ����Ű�� ��� ����
		free(poldtop); // ���� top��ġ�� �����ϴ� ��� �޸� ����(����)
		pstack->count--; // header�� ��尳�� ����
		return item; // ������ ����� ������ ��ȯ
	}
}

void main()
{
	int n;
	scanf_s("%d", &n); // ���������� ��Ÿ�� ���� �Է�
	stack* pstack = createstack(100); // ���������� ǥ���� stack ����
	while (n / 2 >= 1 ) // ���� n�� ���������� ��Ÿ���� ���Ͽ� ���̻� ���������� ���� ������ 2�� ������
	{
		push(pstack, n % 2); // n�� 2�� ���� �������� stack�� ����
		n /= 2; // n = n / 2 ����

	}
	push(pstack, 1); 

	while (!pstack->top == NULL) // ��尡 �����Ҷ����� ����(header�� top�� NULL�� �ƴҶ�����)
	{
		printf("%d", pop(pstack)); // stack�� ����� ����� �����͸� ���
	}
	
}
