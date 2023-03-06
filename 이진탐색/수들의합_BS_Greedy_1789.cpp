#include <iostream>
#include <algorithm>
using namespace std;

// Greedy + Binary Search 문제 (기존의 풀이 방법은 최적화에 있어서 좋지 않다고 판단)

/*
합 s가 주어질 때, 자연수 갯수 n이 최대가 되려면, 합을 이루는 자연수 원소들의 값이 작은 순서로 구성되어야 한다.
- 1 ~ end의 합과 목표 상한 합 s를 비교
    - 1 ~ mid 까지의 합 > 목표 합 s인 경우
        start = start, end = mid - 1로 재탐색
    - 1 ~ mid 까지의 합 < 목표 합 s인 경우
        최대 자연수 개수 n 갱신 (n = max(n, mid))
*/
long S, N;

long calculate(long x) {
    return (x * (x + 1)) / 2;
}

void binarySearch(long start, long end) {
    if (start > end) return;

    long mid = (start + end) / 2;
    long sum = calculate(mid);
    if (sum > S) {
        binarySearch(start, mid - 1);
    }
    else if (sum < S) {
        N = max(N, mid);
        binarySearch(mid + 1, end);
    }
    else {
        N = mid;
        return;
    }
}


int main() {
    cin >> S;

    binarySearch(1, S);
    cout << N;
    
    return 0;
}