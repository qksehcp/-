#include <stdio.h>

typedef int element;


typedef struct Heap { // Heap ����
	element *heapAry; // �����͸� ������ �迭
	int maxSize; // �迭�� ũ��
	int size; // �������� ũ��
}Heap;

void ReheapUp(Heap *, int);

void ReheapUp(Heap *pHeap, int idx) // reheapup �Լ� ����
{
	int parentidx = 0; // �θ����� �ּ� 0���� �ʱ�ȭ

	if (idx <= 0 || idx >= pHeap->size) // idx�� �θ� ���� ���� Ȯ��
		return;

	parentidx = (idx - 1) / 2; // idx ����� �θ� ���
	if (pHeap->heapAry[idx] > pHeap->heapAry[parentidx]) // idx ��尡 �θ� ��庸�� Ŭ ���
	{
		element temp = pHeap->heapAry[idx];
		pHeap->heapAry[idx] = pHeap->heapAry[parentidx];
		pHeap->heapAry[parentidx] = temp; // idx ���� �θ� ����� ������ ��ȯ
		ReheapUp(pHeap, parentidx); // reheapup �۾� ���
	}

}

void insertHeap(Heap *pHeap, element data) // ������ ���� �Լ� ����
{
	if (pHeap->size >= pHeap->maxSize) // �����Ͱ� ���Ե� �迭 �޸𸮰� �ִ��� Ȯ��
	{
		printf("Heap is full\n");
		return;
	}
	pHeap->heapAry[pHeap->size++] = data; // �迭�� ���� ������ ��� �ڿ� ������ ����
	ReheapUp(pHeap, pHeap->size - 1); // ���Ե� ������ reheapup �۾�

}

int DeleteHeap(Heap *pHeap, element *pDataOut) // deleteheap �Լ� ����
{
	if (pHeap->size <= 0) // ��尡 �������� ���� ��
	{
		printf("Heap is empty!\n");
		return 0;
	}

	*pDataOut = pHeap->heapAry[0]; // ��Ʈ ����� �����͸� ������ ������ ����
	pHeap->heapAry[0] = pHeap->heapAry[--pHeap->size]; // ���� ������ ����� �����͸� ��Ʈ�� ����
	ReHeapDown(pHeap, 0); // reheapdown
	
	return 1;
}

void ReheapDown(Heap *pHeap, int idx) // reheapdown �Լ� ����
{
	if (idx < 0 || idx >= pHeap->size)
		return;

	if (idx * 2 + 1 < pHeap->size) // idx ����� ���� �ڽ��� heap�� size���� ���� ���
	{
		int maxChild = idx * 2 + 1;
		if (maxChild + 1 < pHeap->size) // idx ����� ������ �ڽ��� size���� ���� ���
		{
			int maxChild = idx * 2 + 1;
			if (maxChild + 1 < pHeap->size && pHeap->heapAry[maxChild + 1] > pHeap->heapAry[maxChild])
				maxChild++; // idx ����� ������ �ڽ��� ���� �ڽĺ��� ū ��� maxChild�� ������ �ڽ� ����
			if (pHeap->heapAry[maxChild] > pHeap->heapAry[idx]) // idx ����� �ڽ��� idx ��庸�� ū ���
			{
				element temp = pHeap->heapAry[idx];
				pHeap->heapAry[idx] = pHeap->heapAry[maxChild];
				pHeap->heapAry[maxChild] = temp; // idx ���� �ڽ� ��ȯ
				ReheapDown(pHeap, maxChild); // reheapdown �۾� �ݺ�

			}
		}
	}
}

void BuildHeap(Heap* pHeap)
{
	int i = 0;
	for (i = 1; i < pHeap->size;i++)
		ReheapUp(pHeap, i);
}