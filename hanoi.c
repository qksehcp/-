#include <stdio.h>
// n개 짜리
// n-1개를 B로 옮기고, 1개를 C로 옮기고, n-1개를 C로

//T(n) = 2*T(n-1) + T(1) ---> O(2^n)

void hanoi(int tower_num, char source, char auxiliary, char dest){ // 하노이탑 출력 함수 정의
    if(tower_num == 1){ // basic condition
        printf("Move from %c to %c\n", source, dest); // 1개의 원판을 이동 출발축->도착축
    }
    else { // general condition
        hanoi(tower_num-1,source,dest,auxiliary); // n-1개의 원판을 보조축으로 이동
        hanoi(1,source, auxiliary, dest); // 1개의 원판을 도착축으로 이동
        hanoi(tower_num-1,auxiliary,source,dest); // n-1개의 원판을 도착축으로 이동
    }
}

int main() {
    int tower_num; // 원판의 개수
    char source, dest, auxiliary; // 출발축, 도착축, 보조축

    scanf_s("%d %c %c %c", &tower_num, &source, &auxiliary, &dest);  

    hanoi(tower_num, source, auxiliary, dest); // 하노이 함수 호출
}

