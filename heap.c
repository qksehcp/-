#include <stdio.h>

typedef int element;


typedef struct Heap { // Heap 선언
	element *heapAry; // 데이터를 저장할 배열
	int maxSize; // 배열의 크기
	int size; // 데이터의 크기
}Heap;

void ReheapUp(Heap *, int);

void ReheapUp(Heap *pHeap, int idx) // reheapup 함수 정의
{
	int parentidx = 0; // 부모노드의 주소 0으로 초기화

	if (idx <= 0 || idx >= pHeap->size) // idx의 부모 존재 여부 확인
		return;

	parentidx = (idx - 1) / 2; // idx 노드의 부모 노드
	if (pHeap->heapAry[idx] > pHeap->heapAry[parentidx]) // idx 노드가 부모 노드보다 클 경우
	{
		element temp = pHeap->heapAry[idx];
		pHeap->heapAry[idx] = pHeap->heapAry[parentidx];
		pHeap->heapAry[parentidx] = temp; // idx 노드와 부모 노드의 데이터 교환
		ReheapUp(pHeap, parentidx); // reheapup 작업 계속
	}

}

void insertHeap(Heap *pHeap, element data) // 데이터 삽입 함수 정의
{
	if (pHeap->size >= pHeap->maxSize) // 데이터가 삽입될 배열 메모리가 있는지 확인
	{
		printf("Heap is full\n");
		return;
	}
	pHeap->heapAry[pHeap->size++] = data; // 배열의 가장 마지막 노드 뒤에 데이터 삽입
	ReheapUp(pHeap, pHeap->size - 1); // 삽입된 데이터 reheapup 작업

}

int DeleteHeap(Heap *pHeap, element *pDataOut) // deleteheap 함수 정의
{
	if (pHeap->size <= 0) // 노드가 존재하지 않을 시
	{
		printf("Heap is empty!\n");
		return 0;
	}

	*pDataOut = pHeap->heapAry[0]; // 루트 노드의 데이터를 임의의 변수에 저장
	pHeap->heapAry[0] = pHeap->heapAry[--pHeap->size]; // 가장 마지막 노드의 데이터를 루트에 저장
	ReHeapDown(pHeap, 0); // reheapdown
	
	return 1;
}

void ReheapDown(Heap *pHeap, int idx) // reheapdown 함수 정의
{
	if (idx < 0 || idx >= pHeap->size)
		return;

	if (idx * 2 + 1 < pHeap->size) // idx 노드의 왼쪽 자식이 heap의 size보다 작은 경우
	{
		int maxChild = idx * 2 + 1;
		if (maxChild + 1 < pHeap->size) // idx 노드의 오른쪽 자식이 size보다 작은 경우
		{
			int maxChild = idx * 2 + 1;
			if (maxChild + 1 < pHeap->size && pHeap->heapAry[maxChild + 1] > pHeap->heapAry[maxChild])
				maxChild++; // idx 노드의 오른쪽 자식이 왼쪽 자식보다 큰 경우 maxChild에 오른쪽 자식 대입
			if (pHeap->heapAry[maxChild] > pHeap->heapAry[idx]) // idx 노드의 자식이 idx 노드보다 큰 경우
			{
				element temp = pHeap->heapAry[idx];
				pHeap->heapAry[idx] = pHeap->heapAry[maxChild];
				pHeap->heapAry[maxChild] = temp; // idx 노드와 자식 교환
				ReheapDown(pHeap, maxChild); // reheapdown 작업 반복

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