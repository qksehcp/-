#include <stdio.h>
#include <string.h>

void sort(int*); // �������� �迭 sort�Լ� ����

void main()
{
	int score[10] = { 0 }; // �л� 10���� ������ ������ �迭 �ʱ�ȭ
	int i,j = 0;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &score[i]); // �л� 10���� ���� �Է�

	sort(score); // sort�Լ� ����

	for (j = 0; j < 10; j++)
		printf("%d\n", *(score+j)); // �迭 0��° �ּҺ��� 10��° �ּұ��� ����� ������ ���
}

void sort(int* score)
{
	int i, j = 0;
	int key = 0; // ������ ������ �ӽ� ������
	for (i = 0; i < 10; i++) // �迭�� ù��° �����ͺ��� ���� ��
	{
		for (j = i + 1; j < 10; j++) // i��° �����Ϳ� i+1 ~ 10��° �����ͱ��� ��
		{
			if (*(score + i) < *(score + j)) // ���� i��° �����Ͱ� j��° �����ͺ��� ���� ���(j>i)
			{
				key = *(score + i); // i��° �����͸� key�� �ӽ÷� ����
				*(score + i) = *(score + j); // i��° �����Ϳ� j��° �������� ��ġ ��ȯ
				*(score + j) = key; // i��° �����Ϳ� ���� j��° �������� key���� ����
			}
		}
	}
}