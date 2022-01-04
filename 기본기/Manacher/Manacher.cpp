#include <iostream>
using namespace std;

/*
10000 이상의 길이를 가진 문자열의 부분 문자열에 대해서 팰린드롬을 빠르게 판단해줄 수 있다.
부분 문자열이 팰린드롬인지 O(n)에 판단 가능하게 할 수 있다.

A 배열 i번째 원소 A[i]는 i번째 문자를 중심으로 하는 가장 긴 회문의 반지름 크기를 의미한다.
예를들어 ban a nac에서 a의 A[4]는 최대 반지름인 2가 된다.
*/

const int MAX = 101;
int A[MAX];

void manachers(string s, int N) {
    int r = 0, p = 0;

    for (int i = 0; i < N; i++) {
        if (i <= r) {   // i는 p를 중심으로 한 회문에 속함
            A[i] = min(A[2 * p - i], r - i);
        }
        else {  // i > r 이라면, A[i]의 초기값은 0
            A[i] = 0;
        }

        // 범위 내에서 팰린드롬이라면?
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && s[i - A[i] - 1] == s[i + A[i] + 1]) {
            A[i]++;
        }

        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}