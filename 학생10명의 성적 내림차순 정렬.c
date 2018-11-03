#include <stdio.h>
#include <string.h>

void sort(int*); // 내림차순 배열 sort함수 선언

void main()
{
	int score[10] = { 0 }; // 학생 10명의 점수를 저장할 배열 초기화
	int i,j = 0;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &score[i]); // 학생 10명의 점수 입력

	sort(score); // sort함수 실행

	for (j = 0; j < 10; j++)
		printf("%d\n", *(score+j)); // 배열 0번째 주소부터 10번째 주소까지 저장된 데이터 출력
}

void sort(int* score)
{
	int i, j = 0;
	int key = 0; // 점수를 저장할 임시 데이터
	for (i = 0; i < 10; i++) // 배열의 첫번째 데이터부터 점수 비교
	{
		for (j = i + 1; j < 10; j++) // i번째 데이터와 i+1 ~ 10번째 데이터까지 비교
		{
			if (*(score + i) < *(score + j)) // 만약 i번째 데이터가 j번째 데이터보다 작을 경우(j>i)
			{
				key = *(score + i); // i번째 데이터를 key에 임시로 저장
				*(score + i) = *(score + j); // i번째 데이터와 j번째 데이터의 위치 교환
				*(score + j) = key; // i번째 데이터에 원래 j번째 데이터인 key값을 저장
			}
		}
	}
}