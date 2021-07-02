/*
BIT
2진법 인덱스 구조를 활용해 구간 합 문제를 효과적으로 해결해 줄 수 있는 자료구조

0이 아닌 마지막 비트를 찾는 방법 K & -K
BIT에서 활용하자면 0이 아닌 마지막 비트 = 저장하고 있는 값들의 개수이다.
(백준 2042 활용)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;    // 데이터의 개수, 변경 횟수, 구간합 계산 횟수
const int MAX = 1000001;
long long arr[MAX];
long long tree[MAX];

// i번째 수까지 누적 합을 계산하는 함수
long long prefixSum(int i) {
    long long res = 0;

    while (i > 0) {
        res += tree[i];
        i -= (i & -i);  // 0이 아닌 마지막 비트만큼 빼가면서 이동
    }

    return res;
}

// i번째 수를 dif만큼 더하는 수
void update(int i, long long dif) {
    while (i <= n) {
        tree[i] += dif;
        i += (i & -i);
    }
}

// start부터 end까지의 구간 합을 계산하는 함수
long long intervalSum(int start, int end) {
    return prefixSum(end) - prefixSum(start - 1);
}


int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        long long num;
        cin >> num;
        
        arr[i] = num;
        update(i, num);
    }

    
    for (int i = 0; i < m + k; i++) {
        int select;
        cin >> select;

        // update 연산일 경우
        if (select == 1) {
            int idx;
            long long value;
            cin >> idx >> value;

            update(idx, value - arr[idx]);  // 바뀐 크기(dif)만큼 적용
            arr[idx] = value;
        }
        else {
            int start, end;
            cin >> start >> end;
            cout << intervalSum(start, end) << '\n';
        }
    }

    return 0;
}
